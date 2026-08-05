<p align="center">
  <img src="Images/cover.png" width="100%">
</p>

<h1 align="center">Ready2Go</h1>
<p align="center"><b>Smart Embedded Departure Assistant</b></p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Microcontroller-E7352C?logo=espressif&logoColor=white" alt="ESP32">
  <img src="https://img.shields.io/badge/Arduino_IDE-C++-00979D?logo=arduino&logoColor=white" alt="Arduino IDE">
  <img src="https://img.shields.io/badge/Blynk-IoT_Platform-23C48E?logo=blynk&logoColor=white" alt="Blynk">
  <img src="https://img.shields.io/badge/Wokwi-Simulation-7F52FF" alt="Wokwi">
  <img src="https://img.shields.io/badge/IEEE-SSCS_2026-00629B?logo=ieee&logoColor=white" alt="IEEE SSCS">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey" alt="MIT License">
</p>

<p align="center">
  <a href="Report/Ready2Go_Report.pdf">
    <img src="https://img.shields.io/badge/📄_Project_Report-Read_Now-4A90D9?style=for-the-badge" alt="Project Report">
  </a>
  &nbsp;
  <a href="https://youtu.be/xozcsi4o3Z0?si=FPg_Io4ks2JNHsAm">
    <img src="https://img.shields.io/badge/▶_Demo_Video-Watch_Now-FF0000?style=for-the-badge&logo=youtube&logoColor=white" alt="Demo Video">
  </a>
  &nbsp;
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/⚡_Wokwi_Simulation-Open-7F52FF?style=for-the-badge" alt="Wokwi Simulation">
  </a>
</p>

---

## 📑 Table of Contents

- [Overview](#-overview)
- [Quick Facts](#-quick-facts)
- [Features](#-features)
- [Project Gallery](#-project-gallery)
- [Hardware Components](#-hardware-components)
- [System Architecture](#-system-architecture)
- [User Interface](#-user-interface)
- [IoT Dashboard](#-iot-dashboard)
- [Technologies Used](#-technologies-used)
- [Repository Structure](#-repository-structure)
- [Getting Started](#-getting-started)
- [Future Work](#-future-work)
- [Team](#-team)
- [License](#-license)

---

## 📖 Overview

**Ready2Go** is an ESP32-based smart departure assistant designed to eliminate the frustration of forgetting essential belongings before leaving home.

Unlike traditional reminder apps that rely solely on manual input, Ready2Go combines **destination-aware checklists**, **physical object verification via Hall-effect sensors**, and **real-time IoT connectivity** to ensure critical items are actually taken — not just checked off. The system activates automatically on motion detection and guides the user through a verified departure flow via an LCD interface and Blynk dashboard.

<p align="center">
  <img src="Images/prototype.jpeg" width="500">
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
  <img src="Images/prototype.jpeg" width="30%" alt="Prototype">
  &nbsp;
  <img src="Images/where_to.jpeg" width="30%" alt="Destination Selection">
  &nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="30%" alt="Blynk Dashboard">
</p>
<p align="center">
  <sub>Left: Physical Prototype &nbsp;|&nbsp; Center: Destination Selection &nbsp;|&nbsp; Right: Blynk IoT Dashboard</sub>
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
  <img src="Images/hardware_connections.jpeg" width="600" alt="Hardware Connections">
</p>
<p align="center"><sub>Hardware wiring and connections</sub></p>

---

## 🏗 System Architecture

<p align="center">
  <img src="Images/system_architecture.png" width="700" alt="System Architecture">
</p>

The firmware follows a modular pipeline:

> **Motion Detection → Destination Selection → Checklist Generation → Hardware Verification → Decision Engine → IoT Sync**

<p align="center">
  <img src="Images/hardware_block_diagram.png" width="700" alt="Hardware Block Diagram">
</p>

<p align="center">
  <img src="Images/pin_mapping.png" width="650" alt="ESP32 Pin Mapping">
</p>
<p align="center"><sub>ESP32 pin mapping</sub></p>

---

## ⚡ Circuit Diagram & Simulation

<p align="center">
  <img src="Images/wokwi.png" width="700" alt="Wokwi Circuit Diagram">
</p>

The complete circuit was validated in **Wokwi** prior to physical prototyping.

<p align="center">
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/⚡_Open_Simulation-Wokwi-7F52FF?style=for-the-badge" alt="Open Wokwi">
  </a>
</p>

---

## 🖥 User Interface

<p align="center">
  <img src="Images/welcome_back.jpeg" width="42%" alt="Welcome Screen">
  &nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="42%" alt="Destination Selection">
</p>
<p align="center">
  <sub>Left: Startup / Welcome Screen &nbsp;|&nbsp; Right: Destination Selection</sub>
</p>

The LCD guides users through: destination selection → item checklist → physical verification → readiness result.

---

## ☁️ IoT Dashboard

<p align="center">
  <img src="Images/connecting.jpeg" width="42%" alt="Connecting to Blynk">
  &nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="42%" alt="Blynk Dashboard">
</p>
<p align="center">
  <sub>Left: Wi-Fi / Blynk Connection &nbsp;|&nbsp; Right: Live Dashboard</sub>
</p>

The Blynk dashboard exposes:

- Current destination and system status
- Readiness score and missing items
- Live activity log
- Custom destination management (no firmware required)

---

## 💻 Technologies Used

| Technology | Role |
|---|---|
| **ESP32 DevKit V1** | Main microcontroller |
| **Arduino IDE / C++** | Firmware development |
| **Blynk IoT** | Cloud dashboard and remote config |
| **Wokwi** | Circuit simulation and validation |
| **Hall Effect Sensors** | Physical object detection |
| **PIR Motion Sensor** | Automatic system activation |
| **LCD I2C + Joystick** | Embedded user interface |

---

## 📂 Repository Structure

```
Ready2Go-Smart-Embedded-Departure-Assistant/
│
├── Source_Code/          # ESP32 Arduino firmware
├── Report/               # IEEE SSCS project report (PDF)
├── Images/               # Diagrams, screenshots, prototype photos
└── Resources/            # Datasheets, references, assets
```

---

## 🚀 Getting Started

```bash
# 1. Clone the repository
git clone https://github.com/your-username/Ready2Go-Smart-Embedded-Departure-Assistant.git

# 2. Open in Arduino IDE
#    File → Open → Source_Code/Ready2Go.ino

# 3. Install required libraries (Arduino IDE Library Manager)
#    - Blynk
#    - LiquidCrystal_I2C
#    - ESP32 Board Package (Espressif)

# 4. Configure Blynk credentials
#    Edit BLYNK_TEMPLATE_ID, BLYNK_DEVICE_NAME, and BLYNK_AUTH_TOKEN in the sketch

# 5. Select board: ESP32 Dev Module → Upload
```

---

## 🔮 Future Work

| Improvement | Description |
|---|---|
| 📡 **RFID Identification** | Automatic item detection without Hall sensors |
| 🎙 **Voice Assistant** | Hands-free checklist interaction |
| 🤖 **AI Recommendations** | Personalized checklist suggestions |
| 📲 **Push Notifications** | Mobile alerts for missing items |
| 📊 **Cloud Analytics** | Usage history and departure pattern insights |
| 🔋 **Battery-Powered Mode** | Standalone portable version |

---

## 👥 Team

<p align="center">

| Name | Role |
|---|---|
| **Ahmed Samir** | Embedded Software & System Design |
| **Ahmed Eltanany** | Hardware Integration |
| **Mohamed Aboelkasem** | Testing & Documentation |

</p>

<p align="center">
  Electronics and Communications Engineering — Nile University<br>
  <b>IEEE SSCS Arduino Contest 2026</b>
</p>

---

## 📜 License

This project is licensed under the **[MIT License](LICENSE)**.

---

<p align="center">
  <sub>Built with ❤️ by Team Ready2Go · Nile University · IEEE SSCS 2026</sub>
</p>
