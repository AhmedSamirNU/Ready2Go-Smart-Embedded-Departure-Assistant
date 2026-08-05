<p align="center">
  <img src="Images/cover.png" width="100%">
</p>

<h1 align="center">Ready2Go</h1>
<p align="center"><b>Smart Embedded Departure Assistant</b></p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Microcontroller-E7352C?style=flat-square&logo=espressif&logoColor=white" alt="ESP32">
  <img src="https://img.shields.io/badge/Arduino_IDE-C++-00979D?style=flat-square&logo=arduino&logoColor=white" alt="Arduino IDE">
  <img src="https://img.shields.io/badge/Blynk-IoT_Platform-23C48E?style=flat-square&logo=blynk&logoColor=white" alt="Blynk">
  <img src="https://img.shields.io/badge/Wokwi-Simulation-7F52FF?style=flat-square" alt="Wokwi">
  <img src="https://img.shields.io/badge/IEEE-SSCS_2026-00629B?style=flat-square&logo=ieee&logoColor=white" alt="IEEE SSCS">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square" alt="MIT License">
</p>

<br>

<p align="center">
  <a href="Report/Ready2Go_Report.pdf">
    <img src="https://img.shields.io/badge/-%F0%9F%93%84%20Project%20Report-1a73e8?style=for-the-badge&labelColor=1a73e8&color=1a73e8" alt="Project Report" height="32">
  </a>
  &nbsp;&nbsp;
  <a href="https://youtu.be/xozcsi4o3Z0?si=FPg_Io4ks2JNHsAm">
    <img src="https://img.shields.io/badge/-%E2%96%B6%20Demo%20Video-FF0000?style=for-the-badge&logo=youtube&logoColor=white&labelColor=FF0000&color=FF0000" alt="Demo Video" height="32">
  </a>
  &nbsp;&nbsp;
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/-%E2%9A%A1%20Wokwi%20Simulation-7F52FF?style=for-the-badge&labelColor=7F52FF&color=7F52FF" alt="Wokwi Simulation" height="32">
  </a>
</p>

<br>

---

## 📑 Table of Contents

[Overview](#-overview) · [Quick Facts](#-quick-facts) · [Features](#-features) · [Gallery](#-project-gallery) · [Hardware](#-hardware-components) · [Architecture](#-system-architecture) · [Simulation](#-circuit-diagram--simulation) · [UI](#-user-interface) · [IoT Dashboard](#-iot-dashboard) · [Technologies](#-technologies-used) · [Repository](#-repository-structure) · [Getting Started](#-getting-started) · [Future Work](#-future-work) · [Team](#-team) · [License](#-license)

---

## 📖 Overview

**Ready2Go** is an ESP32-based smart departure assistant that eliminates forgotten belongings before leaving home. Unlike traditional reminder apps that rely on manual input, Ready2Go combines **destination-aware checklists**, **physical object verification via Hall-effect sensors**, and **real-time IoT connectivity** — ensuring critical items are actually taken, not just tapped through.

The system activates automatically on motion detection and guides the user through a verified departure flow via an LCD interface and Blynk cloud dashboard.

<p align="center">
  <img src="Images/prototype.jpeg" width="430" alt="Ready2Go Prototype">
</p>

---

## 🚀 Quick Facts

| Property | Details |
|---|---|
| **Microcontroller** | ESP32 DevKit V1 |
| **Language** | Arduino C++ |
| **IoT Platform** | Blynk IoT |
| **Simulation** | Wokwi |
| **IDE** | Arduino IDE |
| **Competition** | IEEE SSCS Arduino Contest 2026 |

---

## ✨ Features

| Feature | Description |
|---|---|
| ✅ **Dynamic Checklist** | Destination-specific item lists generated at runtime |
| 🧲 **Hall Sensor Verification** | Physical confirmation that items have been taken |
| 📊 **Readiness Score** | Quantified departure readiness shown on LCD and Blynk |
| 📍 **Custom Destinations** | User-defined destinations without firmware changes |
| ☁️ **Blynk IoT Dashboard** | Real-time monitoring and remote configuration |
| 🏃 **Auto-Activation** | PIR motion sensor triggers the system on presence |
| 🔔 **Continuous Alerts** | Audible buzzer warnings for missing critical items |
| 🔄 **Cloud Sync** | Live status updates to Blynk cloud |

---

## 🖼 Project Gallery

<p align="center">
  <img src="Images/prototype.jpeg" width="28%" alt="Physical Prototype">
  &nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="28%" alt="Destination Selection">
  &nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="28%" alt="Blynk Dashboard">
</p>
<p align="center">
  <sub>Physical Prototype &nbsp;·&nbsp; Destination Selection &nbsp;·&nbsp; Blynk IoT Dashboard</sub>
</p>

---

## 🛠 Hardware Components

| Component | Purpose |
|---|---|
| **ESP32 DevKit V1** | Main microcontroller |
| **PIR Motion Sensor** | Automatic presence detection |
| **LCD 16×2 I2C** | User interface display |
| **Analog Joystick** | Menu navigation |
| **Hall Effect Sensors** | Physical item verification |
| **Push Buttons** | User interaction |
| **Active Buzzer** | Audible departure alerts |

<p align="center">
  <img src="Images/hardware_connections.jpeg" width="500" alt="Hardware Wiring and Connections">
</p>
<p align="center"><sub>Hardware wiring and connections</sub></p>

---

## 🏗 System Architecture

### Software Architecture

<p align="center">
  <img src="Images/system_architecture.png" width="620" alt="System Architecture Diagram">
</p>

The firmware follows a modular pipeline:

> **Motion Detection → Destination Selection → Checklist Generation → Hardware Verification → Decision Engine → IoT Sync**

### Hardware Block Diagram

<p align="center">
  <img src="Images/hardware_block_diagram.png" width="620" alt="Hardware Block Diagram">
</p>

### ESP32 Pin Mapping

<p align="center">
  <img src="Images/pin_mapping.png" width="600" alt="ESP32 Pin Mapping">
</p>

---

## ⚡ Circuit Diagram & Simulation

<p align="center">
  <img src="Images/wokwi.png" width="620" alt="Wokwi Circuit Diagram">
</p>

The complete circuit was validated in **Wokwi** prior to physical prototyping.

<p align="center">
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/-%E2%9A%A1%20Open%20Simulation-7F52FF?style=for-the-badge&labelColor=7F52FF&color=7F52FF" alt="Open in Wokwi" height="32">
  </a>
</p>

---

## 🖥 User Interface

<p align="center">
  <img src="Images/welcome_back.jpeg" width="38%" alt="Welcome Screen">
  &nbsp;&nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="38%" alt="Destination Selection">
</p>
<p align="center">
  <sub>Startup / Welcome Screen &nbsp;·&nbsp; Destination Selection</sub>
</p>

The LCD guides users through: destination selection → item checklist → physical verification → readiness result.

---

## ☁️ IoT Dashboard

<p align="center">
  <img src="Images/connecting.jpeg" width="38%" alt="Connecting to Blynk">
  &nbsp;&nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="38%" alt="Blynk Live Dashboard">
</p>
<p align="center">
  <sub>Wi-Fi / Blynk Connection &nbsp;·&nbsp; Live Dashboard</sub>
</p>

The Blynk dashboard exposes: current destination, system status, readiness score, missing items, live activity log, and custom destination management — all without firmware changes.

---

## 💻 Technologies Used

| Technology | Purpose |
|---|---|
| **ESP32 DevKit V1** | Main microcontroller |
| **Arduino IDE / C++** | Firmware development |
| **Blynk IoT** | Cloud dashboard and remote configuration |
| **Wokwi** | Circuit simulation and pre-deployment validation |
| **Hall Effect Sensors** | Physical object detection |
| **PIR Motion Sensor** | Automatic system activation |
| **LCD I2C + Joystick** | Embedded user interface |

---

## 📂 Repository Structure

```
Ready2Go-Smart-Embedded-Departure-Assistant/
│
├── Source_Code/       # ESP32 Arduino firmware
├── Report/            # IEEE SSCS project report (PDF)
├── Images/            # Diagrams, screenshots, prototype photos
└── Resources/         # Datasheets, references, assets
```

---

## 🚀 Getting Started

**1. Clone the repository**

```bash
git clone https://github.com/your-username/Ready2Go-Smart-Embedded-Departure-Assistant.git
```

**2. Open in Arduino IDE**

```
File → Open → Source_Code/Ready2Go.ino
```

**3. Install required libraries** *(Arduino IDE Library Manager)*

```
Blynk
LiquidCrystal_I2C
ESP32 Board Package (Espressif)
```

**4. Configure Blynk credentials** in the sketch

```cpp
#define BLYNK_TEMPLATE_ID   "your_template_id"
#define BLYNK_DEVICE_NAME   "your_device_name"
#define BLYNK_AUTH_TOKEN    "your_auth_token"
```

**5. Select board → Upload**

```
Tools → Board → ESP32 Dev Module → Upload
```

---

## 🔮 Future Work

| Improvement | Description |
|---|---|
| 📡 **RFID Identification** | Automatic item detection without Hall sensors |
| 🎙 **Voice Assistant** | Hands-free checklist interaction |
| 🤖 **AI Recommendations** | Personalized checklist suggestions based on history |
| 📲 **Push Notifications** | Mobile alerts for missing critical items |
| 📊 **Cloud Analytics** | Departure pattern insights and usage history |
| 🔋 **Battery-Powered Mode** | Standalone portable version |

---

## 👥 Team

| Name | Role |
|---|---|
| **Ahmed Samir** | Embedded Software & System Design |
| **Ahmed Eltanany** | Hardware Integration |
| **Mohamed Aboelkasem** | Testing & Documentation |

<p align="center">
  Electronics and Communications Engineering · Nile University<br>
  <b>IEEE SSCS Arduino Contest 2026</b>
</p>

---

## 📜 License

This project is licensed under the **[MIT License](LICENSE)**.

---

<p align="center">
  ⭐ If you found this project useful, please consider giving it a star — it helps others discover it.<br><br>
  <sub>Made with ❤️ by Team Ready2Go · Nile University · IEEE SSCS 2026</sub>
</p>
