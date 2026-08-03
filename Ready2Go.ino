// ========================================================================================
//  Ready2Go – Smart Embedded Departure Assistant
//  Author: Ahmed Samir (Nile University - ECE)
//  Event: IEEE SSCS Arduino Contest
// ========================================================================================
//  Blynk Datastreams:
//    V0  – System Status         (String) - Human-readable system state
//    V1  – Current Destination   (String) - Clean destination name
//    V2  – Current Item          (String) - Clean item name
//    V3  – Readiness Score       (Integer 0–100) - Clamped scoring system
//    V4  – AI Assistant Message  (String) - Complete event timeline
//    V5  – Missing Items         (String) - Dynamically generated list
// ========================================================================================

// --- Blynk Credentials (must be defined BEFORE including Blynk) ---
#define BLYNK_TEMPLATE_ID   "TMPL2Dh8I1eqd"
#define BLYNK_TEMPLATE_NAME "Ready2Go"
#define BLYNK_AUTH_TOKEN    "gOnx6kCUGNovvZhwDiDUQl9laD3PBI7K"

#define BLYNK_PRINT Serial

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// --- WiFi Credentials ---
char ssid[] = "Ahmed@yousef";
char pass[] = "25112595";

// --- Pin Definitions (Preserved strictly as requested) ---
#define PIN_PIR         27
#define PIN_JOY_X       34
#define PIN_JOY_SW      32  
#define PIN_BTN_YES     13  
#define PIN_BTN_NO       5  
#define PIN_BTN_BACK    23  
#define PIN_SENS_KEYS   25  
#define PIN_SENS_WALLET 26  
#define PIN_SENS_ID     14  // Renamed from PIN_SENS_PHONE
#define PIN_BUZZER      12

// --- Scoring Constants ---
const int SCORE_START              = 100;
const int SCORE_MIN                = 0;
const int PENALTY_CRITICAL_SKIPPED = 15;
const int PENALTY_NON_CRITICAL     = 5;
const int PENALTY_SENSOR_LEFT      = 20;

// --- LCD Setup ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- System States ---
enum SystemState {
  STATE_SLEEP,
  STATE_MENU,
  STATE_CHECKLIST,
  STATE_VALIDATE,
  STATE_SUCCESS
};
SystemState currentState = STATE_SLEEP;

// --- Menu Variables ---
String destinations[] = {"University", "Work", "Gym", "Travel", "Emergency", "Custom"};
int menuIndex    = 0;
int maxMenuIndex = 5;

// --- Checklist Items (Updated replacing Phone with Student ID) ---
String uniItems[]     = {"Laptop", "Charger", "Case", "Notebook", "Keys", "Wallet", "Student ID"};
bool   uniCritical[]  = {false,    false,     false,  false,      true,   true,     true};

String workItems[]    = {"Keys", "Wallet", "Student ID", "Water Bottle", "Food"};
bool   workCritical[] = {true,   true,     true,         false,          false};

String gymItems[]     = {"Keys", "Wallet", "Student ID", "Pre-Workout", "Water Bottle"};
bool   gymCritical[]  = {true,   true,     true,         false,         false};

String travelItems[]    = {"Travel Bag", "Keys", "Wallet", "Student ID", "Passport"};
bool   travelCritical[] = {false,        true,   true,     true,         false};

String emergencyItems[]    = {"Keys", "Wallet", "Student ID"};
bool   emergencyCritical[] = {true,   true,     true};

// --- Active Checklist Pointers ---
String* currentItems    = nullptr;
bool*   currentCritical = nullptr;
int     maxItems        = 0;
int     currentItemIndex = 0;

// --- Debounce & Timing ---
unsigned long lastJoyMove      = 0;
unsigned long lastButtonPress  = 0;
const int     debounceDelay    = 300;
bool          joystickCentered = true;

// --- Global Variables ---
int    readinessScore    = SCORE_START;
String missingItems      = "None";
String assistantMessage  = "";
unsigned long sessionStart = 0;
unsigned long sessionDuration = 0;

// ========================================================================================
//  EXTENSION POINTS (FUTURE READY ARCHITECTURE)
// ========================================================================================
void triggerCloudLogging(String event, String details) { /* TODO: Push to external backend */ }
void sendPushNotification(String title, String msg) { /* TODO: Trigger Blynk Automations */ }
void recordAnalyticsData(int finalScore) { /* TODO: Log daily success rates */ }
void handleRemoteCommand(String cmd) { /* TODO: Process remote trigger actions */ }

// ========================================================================================
//  BLYNK & SERIAL HELPER FUNCTIONS (DRY Principle)
// ========================================================================================

void updateStatus(String status) {
  Blynk.virtualWrite(V0, status);
}

void updateDestination(String dest) {
  Blynk.virtualWrite(V1, dest);
  Serial.println("[INFO] Destination = " + dest);
}

void updateChecklistItem(String item) {
  Blynk.virtualWrite(V2, item);
  if (item != "Done" && item != "None") {
    Serial.println("[CHECK] " + item);
  }
}

void applyPenalty(int penalty) {
  readinessScore -= penalty;
  if (readinessScore < SCORE_MIN) readinessScore = SCORE_MIN;
  Blynk.virtualWrite(V3, readinessScore);
}

void resetScore() {
  readinessScore = SCORE_START;
  Blynk.virtualWrite(V3, readinessScore);
}

void updateAssistant(String msg, String logLevel = "[INFO]") {
  assistantMessage = msg;
  Blynk.virtualWrite(V4, msg);
  if (logLevel != "") {
    Serial.println(logLevel + " " + msg);
  }
}

// Updated to match the new hardware verification logic
void updateMissingItemsList(bool keysOnShelf, bool walletOnShelf, bool idOnShelf) {
  missingItems = "";
  if (keysOnShelf)   missingItems += "Keys";
  if (walletOnShelf) missingItems += (missingItems.length() > 0 ? ", " : "") + String("Wallet");
  if (idOnShelf)     missingItems += (missingItems.length() > 0 ? ", " : "") + String("Student ID");
  
  if (missingItems.length() == 0) missingItems = "None";
  
  Blynk.virtualWrite(V5, missingItems);
}

void syncInitialBlynkState() {
  updateStatus("Sleeping");
  Blynk.virtualWrite(V1, "None");
  Blynk.virtualWrite(V2, "None");
  Blynk.virtualWrite(V3, SCORE_START);
  updateAssistant("System Ready");
  Blynk.virtualWrite(V5, "None");
}

String customDestination = "";
bool hasCustomDestination = false;

String customChecklist[15];
int customItemsCount = 0;
bool customCritical[15];

BLYNK_WRITE(V6)
{
  customDestination = param.asStr();
  customDestination.trim();

  if (customDestination.length() > 0)
  {
    hasCustomDestination = true;
    Serial.println("Custom Destination: " + customDestination);
    Blynk.virtualWrite(V1, customDestination);
  }
  else
  {
    hasCustomDestination = false;
  }
}

BLYNK_WRITE(V7)
{
  String data = param.asStr();
  data.trim();
  customItemsCount = 0;

  while (data.length() > 0 && customItemsCount < 15)
  {
    int comma = data.indexOf(',');

    if (comma == -1)
    {
      customChecklist[customItemsCount] = data;
      customChecklist[customItemsCount].trim();

      if (customChecklist[customItemsCount].startsWith("*"))
      {
          customCritical[customItemsCount] = true;
          customChecklist[customItemsCount].remove(0,1);
      }
      else
      {
          customCritical[customItemsCount] = false;
      }

      customItemsCount++;
      break;
    }

    customChecklist[customItemsCount] = data.substring(0, comma);
    customChecklist[customItemsCount].trim();

    if (customChecklist[customItemsCount].startsWith("*"))
    {
        customCritical[customItemsCount] = true;
        customChecklist[customItemsCount].remove(0,1);
    }
    else
    {
        customCritical[customItemsCount] = false;
    }
    customItemsCount++;

    data = data.substring(comma + 1);
    data.trim();
  }

  Serial.println("Custom Checklist:");
  for (int i = 0; i < customItemsCount; i++)
  {
    Serial.println(customChecklist[i]);
  }
  updateAssistant("Custom Checklist Received");
  Serial.print("Items Count = ");
  Serial.println(customItemsCount);
}

// ========================================================================================
//  HARDWARE VERIFICATION HELPER (Improvement 9)
// ========================================================================================
void verifyHardwareItem(int pin, String itemName) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Checking...");
  lcd.setCursor(0, 1);
  lcd.print(itemName);

  if (!digitalRead(pin)) {
    applyPenalty(PENALTY_SENSOR_LEFT);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Take " + itemName);

    updateAssistant("Please Take Your " + itemName, "[WARNING]");

    while (!digitalRead(pin)) {
      tone(PIN_BUZZER, 1500, 150);
      delay(300);
      Blynk.run();
    }
  }

  // Visual confirmation with progress
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Checking...");
  lcd.setCursor(0, 1);
  lcd.print(itemName + " OK"); // Acts as checkmark per hardware constraints
  
  updateAssistant(itemName + " Verified");
  delay(1000);
}

// ========================================================================================
//  SETUP
// ========================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("================================");
  Serial.println("Ready2Go V1.0");
  Serial.println("IEEE SSCS Arduino Contest");
  Serial.println("Ahmed Samir");
  Serial.println("================================");

  pinMode(PIN_PIR,         INPUT);
  pinMode(PIN_JOY_SW,      INPUT_PULLUP);
  pinMode(PIN_BTN_YES,     INPUT_PULLUP);
  pinMode(PIN_BTN_NO,      INPUT_PULLUP);
  pinMode(PIN_BTN_BACK,    INPUT_PULLUP);
  pinMode(PIN_SENS_KEYS,   INPUT_PULLUP);
  pinMode(PIN_SENS_WALLET, INPUT_PULLUP);
  pinMode(PIN_SENS_ID,     INPUT_PULLUP); // Updated PIN definition check
  pinMode(PIN_BUZZER,      OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready2Go!");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  updateAssistant("Connected To Blynk");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Blynk OK!");
  delay(1000);
  lcd.clear();
  delay(500);

  syncInitialBlynkState();
  Serial.println("[INFO] System Ready. Waiting For Motion...");
}

// ========================================================================================
//  MAIN LOOP
// ========================================================================================
void loop() {
  Blynk.run();

  switch (currentState) {
    case STATE_SLEEP:      handleSleepState();     break;
    case STATE_MENU:       handleMenuState();      break;
    case STATE_CHECKLIST:  handleChecklistState(); break;
    case STATE_VALIDATE:   handleValidateState();  break;
    case STATE_SUCCESS:    handleSuccessState();   break;
  }
}

// ========================================================================================
//  STATE HANDLERS
// ========================================================================================

void handleSleepState() {
  lcd.clear();
  lcd.noBacklight();

  updateStatus("Sleeping");
  updateAssistant("Waiting For Motion");

  while (digitalRead(PIN_PIR) == LOW) {
    Blynk.run();
    delay(100);
  }

  // Motion Detected
  sessionStart = millis(); // Improvement 7: Start Session Timer
  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ready2Go!");
  lcd.setCursor(0, 1);
  lcd.print("Welcome Back...");

  resetScore();
  updateStatus("Motion");
  updateAssistant("Motion Detected");

  delay(2000);
  currentState = STATE_MENU;
  menuIndex    = 0;
  displayMenu();
}

void handleMenuState() {
  int joyX = analogRead(PIN_JOY_X);

  if (joyX >= 1500 && joyX <= 2500) {
    joystickCentered = true;
  }

  if (joystickCentered && (millis() - lastJoyMove > 300)) {
    if (joyX > 3200) {
      menuIndex++;
      if (menuIndex > maxMenuIndex) menuIndex = 0;
      displayMenu();
      lastJoyMove      = millis();
      joystickCentered = false;
    } else if (joyX < 900) {
      menuIndex--;
      if (menuIndex < 0) menuIndex = maxMenuIndex;
      displayMenu();
      lastJoyMove      = millis();
      joystickCentered = false;
    }
  }

  // Selection Logic
  if (digitalRead(PIN_JOY_SW) == LOW && (millis() - lastButtonPress > debounceDelay)) {
    lastButtonPress  = millis();
    currentItemIndex = 0;

    if (menuIndex == 0) {        
      currentItems = uniItems; currentCritical = uniCritical; maxItems = 7; // Fixed array size
    } else if (menuIndex == 1) { 
      currentItems = workItems; currentCritical = workCritical; maxItems = 5;
    } else if (menuIndex == 2) { 
      currentItems = gymItems; currentCritical = gymCritical; maxItems = 5;
    } else if (menuIndex == 3) { 
      currentItems = travelItems; currentCritical = travelCritical; maxItems = 5;
    } else if (menuIndex == 4) { 
      currentItems = emergencyItems; currentCritical = emergencyCritical; maxItems = 3;
    } else if (menuIndex == 5) {
      if (customItemsCount == 0) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("No Checklist");
        lcd.setCursor(0,1);
        lcd.print("Send from App");
        delay(2000);

        menuIndex = 0;
        displayMenu();
        return;
      }
      currentItems = customChecklist; currentCritical = customCritical; maxItems = customItemsCount;
    }

    updateAssistant("Destination Selected");
    
    if (menuIndex == 5 && hasCustomDestination) {
      updateDestination(customDestination);
    } else {
      updateDestination(destinations[menuIndex]);
    }
    
    currentState = STATE_CHECKLIST;
    updateStatus("Checklist");
    updateAssistant("Checklist Started");
    displayChecklistItem();
  }
}

void handleChecklistState() {
  // BACK BUTTON
  if (digitalRead(PIN_BTN_BACK) == LOW && (millis() - lastButtonPress > debounceDelay)) {
    lastButtonPress = millis();
    currentState = STATE_MENU;
    updateAssistant("Browsing Destinations");
    updateChecklistItem("None");
    displayMenu();
    return;
  }

  // YES BUTTON
  if (digitalRead(PIN_BTN_YES) == LOW && (millis() - lastButtonPress > debounceDelay)) {
    lastButtonPress = millis();
    updateAssistant(currentItems[currentItemIndex] + " Confirmed");

    currentItemIndex++;
    if (currentItemIndex >= maxItems) {
      updateChecklistItem("Done");
      updateAssistant("Checklist Completed");
      currentState = STATE_VALIDATE;
    } else {
      displayChecklistItem();
    }
  }

  // NO BUTTON
  if (digitalRead(PIN_BTN_NO) == LOW && (millis() - lastButtonPress > debounceDelay)) {
    lastButtonPress = millis();

    if (currentCritical[currentItemIndex]) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CRITICAL ITEM!");
      lcd.setCursor(0, 1);
      lcd.print("Please Get It!");
      tone(PIN_BUZZER, 1000, 500);

      applyPenalty(PENALTY_CRITICAL_SKIPPED);
      updateAssistant("Critical Item Missing", "[WARNING]");
      updateAssistant("Please Take Your " + currentItems[currentItemIndex], "");

      delay(2000);
      displayChecklistItem(); // Repeat critical item
    } else {
      applyPenalty(PENALTY_NON_CRITICAL);
      updateAssistant(currentItems[currentItemIndex] + " Skipped");

      currentItemIndex++;
      if (currentItemIndex >= maxItems) {
        updateChecklistItem("Done");
        updateAssistant("Checklist Completed");
        currentState = STATE_VALIDATE;
      } else {
        displayChecklistItem();
      }
    }
  }
}

void handleValidateState() {
  updateStatus("Checking Sensors");
  updateAssistant("Verifying Hardware");
  triggerCloudLogging("Validation", "Hall Sensors Started");
  Serial.println("[INFO] Hall Sensor Verification");

  // Read initial states to calculate true missing items BEFORE forcing user to grab them
  bool keysMissing   = !digitalRead(PIN_SENS_KEYS);
  bool walletMissing = !digitalRead(PIN_SENS_WALLET);
  bool idMissing     = !digitalRead(PIN_SENS_ID);

  updateMissingItemsList(keysMissing, walletMissing, idMissing);

  // Validate items visually and structurally using DRY principle helper function
  verifyHardwareItem(PIN_SENS_KEYS, "Keys");
  verifyHardwareItem(PIN_SENS_WALLET, "Wallet");
  verifyHardwareItem(PIN_SENS_ID, "Student ID");

  updateStatus("Items Verified");
  updateAssistant("All Items Verified");
  
  currentState = STATE_SUCCESS;
}

void handleSuccessState() {
  // Screen 1: All Items Verified (Improvement 5)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("All Items");
  lcd.setCursor(0, 1);
  lcd.print("Verified OK");
  delay(1000);

  // Screen 2: Readiness Score (Show for 2 seconds)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Readiness Score");
  lcd.setCursor(0, 1);
  lcd.print(String(readinessScore) + "%");
  delay(2000);

  // Screen 3: Farewell Message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You're Ready!");

  String farewell = "Stay Safe!";
  if      (menuIndex == 0) farewell = "Good Luck in Uni!";
  else if (menuIndex == 1) farewell = "Have a great day";
  else if (menuIndex == 2) farewell = "Enjoy Workout!";
  else if (menuIndex == 3) farewell = "Safe Travels!";
  
  lcd.setCursor(0, 1);
  lcd.print(farewell);

  updateStatus("Ready");
  sendPushNotification("Ready2Go", "You are ready to leave!");
  updateAssistant("Ready To Go", "[SUCCESS]");

  tone(PIN_BUZZER, 800, 200);
  delay(250);
  tone(PIN_BUZZER, 1200, 400);
  
  delay(2000); // Shortened to fit cleanly before sleep logic

  // Calculate and log session metrics (Improvement 7 & 8)
  sessionDuration = (millis() - sessionStart) / 1000;
  
  Serial.println("\n========== SESSION SUMMARY ==========");
  if (menuIndex == 5 && hasCustomDestination) {
    Serial.println("Destination: " + customDestination);
  } else {
    Serial.println("Destination: " + destinations[menuIndex]);
  }
  Serial.println("Readiness Score: " + String(readinessScore));
  Serial.println("Missing Items: " + missingItems);
  Serial.println("Session Time: " + String(sessionDuration) + " sec");
  Serial.println("=====================================\n");
  
  updateAssistant("Session Time: " + String(sessionDuration) + " sec");
  delay(2000);

  recordAnalyticsData(readinessScore);
  updateAssistant("Going Back To Sleep");
  
  // Clean final Blynk setup for next wake cycle
  updateMissingItemsList(false, false, false);
  
  currentState = STATE_SLEEP;
}

// ========================================================================================
//  DISPLAY HELPERS
// ========================================================================================

void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Where to?");
  lcd.setCursor(0, 1);
  
  if (menuIndex == 5 && hasCustomDestination) {
    lcd.print(customDestination);
  } else {
    lcd.print(destinations[menuIndex]);
  }

  updateStatus("Browsing");
  updateAssistant("Browsing Destinations");
  
  if (menuIndex == 5 && hasCustomDestination) {
    updateDestination(customDestination);
  } else {
    updateDestination(destinations[menuIndex]);
  }
}

void displayChecklistItem() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Did you take:");
  lcd.setCursor(0, 1);
  lcd.print(currentItems[currentItemIndex]);

  lcd.setCursor(15,1);
  lcd.print("?");

  updateChecklistItem(currentItems[currentItemIndex] + " (" + String(currentItemIndex + 1) + "/" + String(maxItems) + ")");
  updateAssistant("Checking " + currentItems[currentItemIndex]);
}