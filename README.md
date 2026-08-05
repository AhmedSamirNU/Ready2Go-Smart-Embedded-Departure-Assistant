<p align="center">
  <img src="Images/cover.png" width="100%">
</p>

<h1 align="center">Ready2Go</h1>

<p align="center">
<b>Smart Embedded Departure Assistant</b>
</p>

<p align="center">

![ESP32](https://img.shields.io/badge/ESP32-Microcontroller-red)
![Arduino IDE](https://img.shields.io/badge/Arduino_IDE-C++-00979D)
![Blynk](https://img.shields.io/badge/Blynk-IoT-green)
![Embedded Systems](https://img.shields.io/badge/Embedded-Systems-orange)
![IEEE](https://img.shields.io/badge/IEEE-SSCS-blue)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

</p>

---

# 📖 Overview

Ready2Go is an **ESP32-based smart embedded departure assistant** designed to help users avoid forgetting essential belongings before leaving home.

Unlike traditional reminder applications that rely entirely on manual interaction, Ready2Go combines **dynamic destination-based checklists**, **physical object verification**, and **IoT connectivity** to ensure that critical belongings have actually been taken before departure.

The system detects user presence automatically using a PIR sensor, generates personalized checklists based on the selected destination, verifies critical items using Hall-effect sensors, and continuously alerts the user if any important object is still left behind.

Additionally, the integrated **Blynk IoT dashboard** enables real-time monitoring and allows users to create custom destinations and personalized checklists without modifying the firmware.

---

# 🚀 Quick Facts

| Item | Details |
|------|---------|
| Microcontroller | ESP32 DevKit V1 |
| Programming Language | Arduino C++ |
| IoT Platform | Blynk IoT |
| Simulation | Wokwi |
| Development Environment | Arduino IDE |
| Competition | IEEE SSCS Arduino Contest 2026 |

---

# 🎥 Demonstration

### 📺 Project Video

**YouTube**

https://youtu.be/xozcsi4o3Z0?si=FPg_Io4ks2JNHsAm

---

### 📄 Project Report

[Ready2Go Project Report](Report/Ready2Go_Report.pdf)

---

# ✨ Features

- Motion-activated startup using PIR sensor
- Destination-based dynamic checklist generation
- Physical verification using Hall-effect sensors
- Critical item detection
- Continuous audible warning system
- Readiness score calculation
- ESP32-based embedded architecture
- Blynk IoT dashboard
- Custom destination creation
- Real-time cloud synchronization

---

# 🛠 Hardware Components

| Component | Purpose |
|-----------|----------|
| ESP32 DevKit V1 | Main Controller |
| PIR Motion Sensor | Motion Detection |
| LCD 16×2 I2C | User Interface |
| Analog Joystick | Menu Navigation |
| Hall Effect Sensors | Physical Verification |
| Push Buttons | User Interaction |
| Active Buzzer | Audible Alerts |

<p align="center">
<img src="Images/prototype.jpeg" width="750">
</p>

---

# 🏗 System Architecture

<p align="center">
<img src="Images/system_architecture.png" width="900">
</p>

The software follows a modular architecture composed of:

- Motion Detection
- Destination Selection
- Dynamic Checklist Generation
- Decision Engine
- Hardware Verification
- User Interface
- IoT Communication

---

# 🔲 Hardware Block Diagram

<p align="center">
<img src="Images/hardware_block_diagram.png" width="900">
</p>

---

# 🔌 Hardware Connections

<p align="center">
<img src="Images/hardware_connections.jpeg" width="750">
</p>

---

# 📍 ESP32 Pin Mapping

<p align="center">
<img src="Images/pin_mapping.png" width="850">
</p>

---

# ⚡ Circuit Diagram (Wokwi)

<p align="center">
<img src="Images/wokwi.png" width="900">
</p>

Ready2Go was initially validated using **Wokwi** before deploying the firmware to the physical ESP32 prototype.

🔗 **Simulation**

https://wokwi.com/projects/470927609513027585

---

# 🖥 User Interface

## LCD Interface

<p align="center">
<img src="Images/welcome_back.jpeg" width="350">
&nbsp;&nbsp;&nbsp;
<img src="Images/where_to.jpeg" width="350">
</p>

The LCD guides the user through destination selection, checklist interaction, verification messages, and final readiness status.

---

# ☁ IoT Dashboard

<p align="center">
<img src="Images/connecting.jpeg" width="350">
&nbsp;&nbsp;&nbsp;
<img src="Images/blynk_dashboard.jpeg" width="350">
</p>

The Blynk dashboard provides:

- Current Destination
- System Status
- Readiness Score
- Missing Items
- Live Activity Logs
- Custom Destination Management

---

# 📂 Repository Structure

```
Ready2Go-Smart-Embedded-Departure-Assistant
│
├── Report
├── Source_Code
├── Images
└── Resources
```

---

# 💻 Technologies Used

- ESP32 DevKit V1
- Arduino IDE
- Embedded C++
- Blynk IoT
- Wokwi Simulator
- Hall Effect Sensors
- PIR Motion Sensor
- LCD I2C
- Joystick Navigation

---

# 🔮 Future Improvements

- RFID-based automatic object identification
- Voice assistant integration
- AI-powered personalized recommendations
- Mobile push notifications
- Cloud-based usage analytics
- Battery-powered standalone version

---
# 👥 Team Ready2Go

| Name | Role |
|------|------|
| Ahmed Samir | Embedded Software & System Design |
| Ahmed Eltanany | Hardware Integration |
| Mohamed Aboelkasem | Testing & Documentation |
---

# 📜 License

This project is licensed under the **MIT License**.
