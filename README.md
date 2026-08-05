<p align="center">
  <img src="Images/cover.png" width="100%" alt="Ready2Go Hero Banner" style="border-radius: 10px;">
</p>

<h1 align="center">Ready2Go</h1>

<p align="center">
  <b>Smart Embedded Departure Assistant</b><br>
  <i>An ESP32-powered embedded assistant that physically verifies your essentials before you leave.</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Microcontroller-ESP32--WROOM--32-E7352C?style=flat-square&logo=espressif&logoColor=white" alt="ESP32">
  <img src="https://img.shields.io/badge/Arduino_IDE-00979D?style=flat-square&logo=arduino&logoColor=white" alt="Arduino IDE">
  <img src="https://img.shields.io/badge/IoT%20Platform-Blynk%20Cloud-23C48E?style=flat-square&logo=blynk&logoColor=white" alt="Blynk">
  <img src="https://img.shields.io/badge/Simulation-Wokwi-7F52FF?style=flat-square" alt="Wokwi">
  <img src="https://img.shields.io/badge/Contest-IEEE%20SSCS%202026-00629B?style=flat-square&logo=ieee&logoColor=white" alt="IEEE SSCS">
  <img src="https://img.shields.io/badge/License-MIT-green?style=flat-square" alt="License">
</p>

<p align="center">
  <a href="https://youtu.be/xozcsi4o3Z0?si=FPg_Io4ks2JNHsAm" target="_blank">
    <img src="https://img.shields.io/badge/▶_Watch_Demo_Video-FF0000?style=for-the-badge&logo=youtube&logoColor=white" alt="Watch Demo Video">
  </a>
  &nbsp;
  <a href="https://wokwi.com/projects/470927609513027585" target="_blank">
    <img src="https://img.shields.io/badge/⚡_Live_Wokwi_Simulation-00A8E8?style=for-the-badge&logo=wokwi&logoColor=white" alt="Wokwi Simulation">
  </a>
  &nbsp;
  <a href="Report/Ready2Go_Report.pdf" target="_blank">
    <img src="https://img.shields.io/badge/📄_Project_Report-3C3C3C?style=for-the-badge&logo=adobeacrobatreader&logoColor=white" alt="Project Report">
  </a>
</p>

<p align="center">
<i>ESP32 • Embedded Systems • IoT • IEEE SSCS Arduino Contest 2026</i>
</p>

---

## 📌 Table of Contents
<p align="center">

<a href="#-overview">Overview</a> •
<a href="#-key-features">Features</a> •
<a href="#-quick-facts">Quick Facts</a> •
<a href="#-system-architecture">Architecture</a> •
<a href="#-hardware-design">Hardware</a>

<br>

<a href="#-embedded-user-interface">UI</a> •
<a href="#-iot-dashboard">IoT</a> •
<a href="#-wokwi-simulation">Simulation</a> •
<a href="#-getting-started">Getting Started</a>

</p>

---

## 📖 Overview

**Ready2Go** is an intelligent, ESP32-powered embedded assistant designed to solve a universal problem: leaving home and accidentally forgetting critical personal items such as keys, wallets, or student IDs.

Unlike passive smartphones or software-only reminder apps, Ready2Go actively verifies your belongings through **physical sensing**, **destination-aware dynamic checklists**, and **real-time cloud synchronization**.

> [!NOTE]
> **How It Works:**
> 1. **Proximity Trigger:** As you approach the doorway, a PIR motion sensor automatically wakes up the system.
> 2. **Destination Selection:** Select your destination (e.g., *University*, *Gym*, *Work*) using an analog joystick.
> 3. **Physical Verification:** Place essential items near integrated **Hall-effect magnetic sensors** to physically prove they are present.
> 4. **Readiness Evaluation:** The system calculates a live readiness score, triggering audible buzzer alerts if critical items are missing before you step out.
> 5. **Cloud Sync:** Live data syncs effortlessly with the **Blynk IoT Platform**, allowing remote status checks and dynamic checklist updates without reflashing firmware.
<p align="center">
  <img src="Images/prototype.jpeg" width="270" alt="Ready2Go Hardware Prototype">
  <br>
  <sub><i>Ready2Go Prototype</i></sub>
</p>

---

## 🚀 Key Features

| Feature | Benefit |
| :--- | :--- |
| 🧠 **Dynamic Destination Checklists** | Tailors required checklist items based on selected destination |
| 🧲 **Hardware Verification** | Hall-effect sensors ensure items are physically taken, not just checked off |
| 📊 **Real-Time Readiness Score** | Evaluates departure safety status live on display & cloud |
| ☁️ **Blynk IoT Cloud Sync** | Seamless two-way remote monitoring & custom destination creation |
| 🏃 **Passive PIR Wake-Up** | Auto-activates upon human motion near the exit door |
| 🔔 **Intelligent Audible Alerts** | Continuous multi-tone buzzer feedback for unfulfilled safety checks |
| 🕹️ **Intuitive Embedded Control** | Zero-latency navigation via 16x2 I2C LCD and analog joystick |

---

## ⚡ Quick Facts

| Property | Details |
| :--- | :--- |
| **Project Type** | Embedded Systems & Internet of Things (IoT) |
| **Main Controller** | ESP32 DevKit V1 (Tensilica Xtensa Dual-Core 32-bit LX6) |
| **Programming Language** | Arduino C++ |
| **IoT Platform** | Blynk Cloud IoT |
| **Simulation Tool** | Wokwi Embedded Simulator |
| **IDE** | Arduino IDE 2.x |
| **Competition** | IEEE SSCS Arduino Contest 2026 |

---
---

## 📈 Project Statistics

| Metric | Value |
|:-------|:------|
| Lines of Code | ~1,000+ |
| Hardware Modules | 7 |
| Supported Destinations | 6 + Custom |
| Verified Critical Items | Keys • Wallet • Student ID |
| IoT Connectivity | Blynk Cloud |
| Platform | ESP32 |
| Cloud Platform | Blynk IoT |
| Hardware Verification | Hall Sensors |
---

## 🏗 System Architecture

The software architecture follows a modular, non-blocking event loop design ensuring smooth concurrency between sensor acquisition, LCD rendering, menu navigation, and Blynk cloud telemetry.

<p align="center">
  <img src="Images/system_architecture.png" width="68%" alt="Ready2Go System Architecture"><br>
  <sub><i>System Architecture</i></sub>
</p>

---

## 🔩 Hardware Overview

### High-Level Block Diagram

The system interfaces digital motion sensors, analog joysticks, magnetic sensors, visual LCD displays, acoustic buzzers, and Wi-Fi telemetry around the ESP32 core.

<p align="center">
  <img src="Images/hardware_block_diagram.png" width="72%" alt="Hardware Block Diagram"><br>
  <sub><i>Hardware Block Diagram</i></sub>
</p>

<br>

### Pin Mapping & Physical Assembly

<table align="center" width="82%">
  <tr>
    <td align="center" width="54%" valign="top">
      <img src="Images/pin_mapping.png" width="100%" alt="ESP32 Pin Mapping"><br>
      <sub><i>ESP32 GPIO Mapping</i></sub>
    </td>
    <td align="center" width="46%" valign="top">
      <img src="Images/hardware_connections.jpeg" width="62%" alt="Hardware Breadboard Connections"><br>
      <sub><i>Hardware Assembly</i></sub>
    </td>
  </tr>
</table>

---

## 🖥 Embedded User Interface

The embedded UI uses a 16x2 I2C Liquid Crystal Display paired with a 2-axis analog joystick, offering smooth menu transitions and instant visual status confirmation.

<table align="center" width="100%">
  <tr>
    <td align="center" width="50%">
      <img src="Images/welcome_back.jpeg" width="86%" alt="Welcome Screen"><br>
      <b>1. Motion Detection & Welcome Screen</b>
    </td>
    <td align="center" width="50%">
      <img src="Images/where_to.jpeg" width="86%" alt="Destination Selection Screen"><br>
      <b>2. Interactive Destination Menu</b>
    </td>
  </tr>
</table>

---

## ☁️ IoT Dashboard

Powered by **Blynk IoT Cloud**, users can monitor departure status remotely and customize checklists on the fly.

<table align="center" width="100%">
  <tr>
    <td align="center" width="58%" valign="middle">
      <img src="Images/connecting.jpeg" width="82%" alt="Cloud Connection Status Screen"><br>
      <b>Wi-Fi & Blynk Telemetry Sync Status (5:4)</b>
    </td>
    <td align="center" width="42%" valign="middle">
      <img src="Images/blynk_dashboard.jpeg" width="52%" alt="Blynk Mobile Dashboard App"><br>
      <b>Blynk Mobile Live Dashboard (9:16)</b>
    </td>
  </tr>
</table>

> [!TIP]
> **No Reflashing Needed:** You can add new destination profiles and edit item checklists directly through the Blynk Mobile App interface without uploading new code to the ESP32!

---

## ⚡ Wokwi Simulation

The complete hardware layout and embedded firmware were thoroughly validated in **Wokwi** prior to physical assembly.

<p align="center">
  <img src="Images/wokwi.png" width="60%" alt="Wokwi Interactive Simulation"><br><br>
  <a href="https://wokwi.com/projects/470927609513027585" target="_blank">
    <img src="https://img.shields.io/badge/▶_Launch_Interactive_Wokwi_Simulation-7F52FF?style=for-the-badge&logo=wokwi&logoColor=white" alt="Launch Simulation">
  </a>
</p>

---

## ⚙️ Technologies Used

| Category | Component / Technology |
| :--- | :--- |
| **Hardware Core** | ESP32 DevKit V1 (Wi-Fi / BLE Board) |
| **Sensors** | PIR Motion Sensor (HC-SR501), Hall-Effect Magnetic Sensors |
| **Human Interface** | 16x2 I2C Character LCD, 2-Axis Analog Joystick Module |
| **Actuators** | Active Piezoelectric Buzzer |
| **Cloud Telemetry** | Blynk IoT Cloud Platform |
| **Development IDE** | Arduino IDE 2.x |
| **Simulation** | Wokwi Online Circuit Simulator |

---

## 🔮 Future Improvements

- RFID-based automatic item identification
- Voice assistant integration
- AI-powered recommendation engine
- Push notifications
- Battery-powered standalone version
- Mobile application with analytics

---

## 📂 Repository Structure

```text
Ready2Go-Smart-Embedded-Departure-Assistant/
│
├── Images/                         # Project Documentation Images
│   ├── cover.png                   # Banner Hero Image (16:9)
│   ├── prototype.jpeg              # Assembled Hardware Prototype (4:5)
│   ├── hardware_block_diagram.png  # System Block Diagram (16:9)
│   ├── system_architecture.png     # Software Architecture (5:4)
│   ├── pin_mapping.png             # GPIO Pinout Table (5:4)
│   ├── hardware_connections.jpeg   # Breadboard Circuit (1:1)
│   ├── welcome_back.jpeg           # LCD Welcome Screen (5:4)
│   ├── where_to.jpeg               # LCD Menu Screen (5:4)
│   ├── connecting.jpeg             # LCD Cloud Connection Screen (5:4)
│   ├── blynk_dashboard.jpeg        # Blynk Mobile App Dashboard (9:16)
│   └── wokwi.png                   # Wokwi Simulation Screenshot (5:4)
│
├── Source_Code/                    # Firmware Source Files
│   └── Ready2Go.ino                # Main ESP32 Arduino Sketch
│
├── Report/                         # IEEE Official Documentation
│   └── Ready2Go_Report.pdf         # Complete Technical Paper PDF
│
├── README.md                       # Repository Overview & Setup Guide
└── LICENSE                         # MIT License

---

## 🚀 Getting Started

### Clone the Repository

```bash
git clone https://github.com/AhmedSamirNU/Ready2Go-Smart-Embedded-Departure-Assistant.git
```

### Open the Project

Open the project using **Arduino IDE 2.x**.

### Install Required Libraries

- Blynk
- LiquidCrystal_I2C

### Install ESP32 Board Package

Boards Manager → Espressif ESP32

### Upload

Select:

ESP32 Dev Module

Upload the firmware and configure your Blynk credentials.

---

## 👥 Team

| Name | Role |
|------|------|
| Ahmed Samir | Embedded Software • System Design |
| Ahmed Eltanany | Hardware Integration |
| Mohamed Aboelkasem | Testing • Documentation |

---

## 📜 License

This project is licensed under the MIT License.

---

<p align="center">

Made with ❤️ by Team Ready2Go

</p>

<p align="center">

ESP32 • Embedded Systems • IoT • Nile University • IEEE SSCS 2026

</p>
