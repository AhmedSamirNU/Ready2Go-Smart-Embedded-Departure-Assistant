<p align="center">
  <img src="Images/cover.png" width="100%" alt="Ready2Go Hero Banner">
</p>

<h1 align="center">Ready2Go</h1>

<p align="center">
  <b>Smart Embedded Departure Assistant</b><br>
  Helping you leave home with confidence — never forget your essentials again.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-E7352C?style=flat-square&logo=espressif&logoColor=white" alt="ESP32">
  <img src="https://img.shields.io/badge/Embedded_Systems-0A66C2?style=flat-square" alt="Embedded Systems">
  <img src="https://img.shields.io/badge/Blynk_IoT-23C48E?style=flat-square&logo=blynk&logoColor=white" alt="Blynk">
  <img src="https://img.shields.io/badge/Wokwi_Simulation-7F52FF?style=flat-square" alt="Wokwi">
  <img src="https://img.shields.io/badge/IEEE_SSCS_2026-00629B?style=flat-square&logo=ieee&logoColor=white" alt="IEEE SSCS">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square" alt="License">
</p>

<p align="center">
  <a href="Report/Ready2Go_Report.pdf">
    <img src="https://img.shields.io/badge/📄_Project_Report-0A66C2?style=flat-square" alt="Project Report">
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://youtu.be/xozcsi4o3Z0?si=FPg_Io4ks2JNHsAm">
    <img src="https://img.shields.io/badge/▶_Demo_Video-E62117?style=flat-square" alt="Demo Video">
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/⚡_Wokwi_Simulation-7F52FF?style=flat-square" alt="Wokwi Simulation">
  </a>
</p>

---

## 📑 Table of Contents

[Overview](#-overview) • [Quick Facts](#-quick-facts) • [Highlights](#-highlights) • [Architecture](#-architecture) • [Hardware Design](#-hardware-design) • [User Interface](#-embedded-user-interface) • [IoT Dashboard](#️-iot-dashboard) • [Simulation](#-simulation) • [Technologies](#-technologies) • [Repository Structure](#-repository-structure) • [Getting Started](#-getting-started) • [Future Improvements](#-future-improvements) • [Team](#-team)

---

<p align="center">
  <img src="Images/prototype.jpeg" width="400" alt="Ready2Go Prototype">
</p>

<p align="center">
  <b>ESP32-based Embedded Smart Departure Assistant</b><br>
  <i>Designed for the IEEE SSCS Arduino Contest 2026</i>
</p>

---

## 📖 Overview

**Ready2Go** is an ESP32-powered smart embedded assistant that helps users avoid leaving home without their essential belongings. 

Instead of relying on manual reminder applications, the system combines **destination-aware checklists**, **physical object verification**, and **real-time IoT monitoring** to ensure important items have actually been taken before departure.

Whenever a person approaches the entrance, a PIR sensor automatically activates the system. The user selects a destination using a joystick, receives a customized checklist, and confirms each required item. 

Critical belongings such as keys, wallet, and student ID are physically verified using Hall-effect sensors before the departure session is completed.

The system is also connected to the **Blynk IoT platform**, enabling real-time monitoring, readiness tracking, and custom destination management directly from a mobile device without modifying the firmware.

---

## 🚀 Quick Facts

| Property | Details |
|-----------|---------|
| **Project Type** | Embedded Systems + IoT |
| **Microcontroller** | ESP32 DevKit V1 |
| **Programming Language** | Arduino C++ |
| **IoT Platform** | Blynk |
| **Simulation** | Wokwi |
| **Development Environment** | Arduino IDE |
| **Competition** | IEEE SSCS Arduino Contest 2026 |

---

## ✨ Highlights

| Feature | Description |
|:--|:--|
| 🧠 **Dynamic Checklist** | Automatically generates destination-specific checklists |
| 🧲 **Physical Verification** | Hall-effect sensors verify important belongings |
| 📊 **Readiness Score** | Calculates departure readiness in real time |
| ☁️ **IoT Dashboard** | Live synchronization with Blynk Cloud |
| 📍 **Custom Destinations** | Create new destinations without updating firmware |
| 🔔 **Smart Alerts** | Continuous buzzer notifications for forgotten items |
| 🏃 **Automatic Activation** | PIR sensor starts the system when someone approaches |
| 📱 **Mobile Monitoring** | View system status remotely using Blynk |

---

## 🏗 Architecture

Ready2Go is built around a modular embedded architecture where sensing, decision-making, hardware verification, user interaction, and cloud communication operate as independent modules.

### Software Architecture

<p align="center">
  <img src="Images/system_architecture.png" width="600" alt="System Architecture">
  <br>
  <sub><i>Overall software architecture of the Ready2Go system.</i></sub>
</p>

### Hardware Block Diagram

<p align="center">
  <img src="Images/hardware_block_diagram.png" width="600" alt="Hardware Block Diagram">
  <br>
  <sub><i>High-level interaction between all hardware modules.</i></sub>
</p>

### ESP32 Pin Mapping

<p align="center">
  <img src="Images/pin_mapping.png" width="550" alt="ESP32 Pin Mapping">
  <br>
  <sub><i>GPIO allocation used throughout the prototype.</i></sub>
</p>

---

## 🔩 Hardware Design

The prototype combines the ESP32 with multiple sensors and peripherals to provide an intelligent departure assistant capable of physical object verification.

<p align="center">
  <img src="Images/hardware_connections.jpeg" width="500" alt="Hardware Assembly">
  <br>
  <sub><i>Physical hardware assembly used during prototype development.</i></sub>
</p>

---

## 🖥 Embedded User Interface

The LCD and joystick provide a simple embedded interface for navigating destinations, checklist items, and system feedback.

<p align="center">
  <img src="Images/welcome_back.jpeg" width="40%" alt="Welcome Screen">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="40%" alt="Destination Selection">
</p>
<p align="center">
  <sub><i>Startup / Welcome Screen • Destination Selection</i></sub>
</p>

---

## ☁️ IoT Dashboard

Using the Blynk platform, users can monitor the system remotely, view readiness status, and create custom destinations without updating the firmware.

<p align="center">
  <img src="Images/connecting.jpeg" width="40%" alt="Cloud Connection">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="40%" alt="Live Dashboard">
</p>
<p align="center">
  <sub><i>Wi-Fi Connection • Live Dashboard</i></sub>
</p>

---

## ⚡ Simulation

The complete embedded system was validated in **Wokwi** before hardware implementation.

<p align="center">
  <img src="Images/wokwi.png" width="600" alt="Wokwi Simulation">
</p>

<p align="center">
  <a href="https://wokwi.com/projects/470927609513027585">
    <img src="https://img.shields.io/badge/⚡_Open_Interactive_Simulation-7F52FF?style=flat-square" alt="Open Simulation">
  </a>
</p>

---

## 🛠 Technologies

| Technology | Purpose |
|------------|---------|
| **ESP32 DevKit V1** | Main embedded controller |
| **Arduino IDE** | Firmware development |
| **Arduino C++** | Embedded programming |
| **Blynk IoT** | Cloud communication |
| **Wokwi** | Circuit simulation |
| **Hall Effect Sensors** | Physical object verification |
| **PIR Motion Sensor** | Motion detection |
| **LCD 16×2 I2C** | Embedded user interface |
| **Analog Joystick** | User navigation |
| **Active Buzzer** | Audible alerts |

---

## 📂 Repository Structure

```text
Ready2Go-Smart-Embedded-Departure-Assistant/
│
├── Images/
│   ├── cover.png
│   ├── prototype.jpeg
│   ├── hardware_connections.jpeg
│   ├── hardware_block_diagram.png
│   ├── system_architecture.png
│   ├── pin_mapping.png
│   ├── wokwi.png
│   ├── welcome_back.jpeg
│   ├── where_to.jpeg
│   ├── connecting.jpeg
│   └── blynk_dashboard.jpeg
│
├── Source_Code/
│   └── Ready2Go.ino
│
├── Report/
│   └── Ready2Go_Report.pdf
│
├── Resources/
│
└── README.md
