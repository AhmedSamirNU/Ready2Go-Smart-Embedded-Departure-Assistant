<p align="center">
  <img src="Images/cover.png" width="100%" alt="Ready2Go Cover Image">
</p>

<h1 align="center">Ready2Go</h1>
<p align="center"><b>Smart Embedded Departure Assistant</b></p>

<p align="center">
  <img src="https://img.shields.io/badge/ESP32-E7352C?style=flat-square&logo=espressif&logoColor=white" alt="ESP32">
  <img src="https://img.shields.io/badge/Arduino_C++-00979D?style=flat-square&logo=arduino&logoColor=white" alt="Arduino IDE">
  <img src="https://img.shields.io/badge/Blynk_IoT-23C48E?style=flat-square&logo=blynk&logoColor=white" alt="Blynk">
  <img src="https://img.shields.io/badge/Wokwi-7F52FF?style=flat-square" alt="Wokwi">
  <img src="https://img.shields.io/badge/IEEE_SSCS_2026-00629B?style=flat-square&logo=ieee&logoColor=white" alt="IEEE SSCS">
  <img src="https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square" alt="MIT License">
</p>

<p align="center">
  <a href="Report/Ready2Go_Report.pdf">
    <img src="https://img.shields.io/badge/📄_Project_Report-1A73E8?style=flat-square" alt="Project Report">
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

<br>

## 📑 Table of Contents

[Overview](#-overview) • [Quick Facts](#-quick-facts) • [Features](#-features) • [Project Gallery](#-project-gallery) • [Hardware Components](#-hardware-components) • [System Architecture](#-system-architecture) • [Circuit Diagram & Simulation](#-circuit-diagram--simulation) • [User Interface](#-user-interface) • [IoT Dashboard](#️-iot-dashboard) • [Technologies Used](#-technologies-used) • [Repository Structure](#-repository-structure) • [Getting Started](#-getting-started) • [Future Work](#-future-work) • [Team](#-team) • [License](#-license)

---

## 📖 Overview

**Ready2Go** is an ESP32-based smart departure assistant that eliminates forgotten belongings before leaving home. 

Unlike traditional reminder apps that rely on manual input, Ready2Go combines destination-aware checklists, physical object verification via Hall-effect sensors, and real-time IoT connectivity. This ensures critical items are physically verified, not just tapped through.

The system activates automatically on motion detection and guides the user through a verified departure flow via a dedicated LCD interface and a Blynk cloud dashboard.

<p align="center">
  <img src="Images/prototype.jpeg" width="400" alt="Ready2Go Prototype">
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
  <img src="Images/prototype.jpeg" width="27%" alt="Physical Prototype">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="27%" alt="Destination Selection">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="27%" alt="Blynk Dashboard">
</p>
<p align="center">
  <sub><i>Physical Prototype • Destination Selection • Blynk IoT Dashboard</i></sub>
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
  <br>
  <sub><i>Physical hardware assembly used during prototype development.</i></sub>
</p>

---

## 🏗 System Architecture

### Software Architecture

<p align="center">
  <img src="Images/system_architecture.png" width="600" alt="System Architecture Diagram">
  <br>
  <sub><i>Modular firmware pipeline processing motion detection to IoT synchronization.</i></sub>
</p>

### Hardware Block Diagram

<p align="center">
  <img src="Images/hardware_block_diagram.png" width="600" alt="Hardware Block Diagram">
  <br>
  <sub><i>High-level hardware interaction and component bridging.</i></sub>
</p>

### ESP32 Pin Mapping

<p align="center">
  <img src="Images/pin_mapping.png" width="550" alt="ESP32 Pin Mapping">
  <br>
  <sub><i>Detailed ESP32 microcontroller pin assignments and I/O layout.</i></sub>
</p>

---

## ⚡ Circuit Diagram & Simulation

<p align="center">
  <img src="Images/wokwi.png" width="600" alt="Wokwi Circuit Diagram">
</p>

The complete circuit was validated in **Wokwi** prior to physical prototyping, ensuring safety and accurate signal routing before physical deployment.

---

## 🖥 User Interface

<p align="center">
  <img src="Images/welcome_back.jpeg" width="40%" alt="Welcome Screen">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/where_to.jpeg" width="40%" alt="Destination Selection">
</p>
<p align="center">
  <sub><i>Startup / Welcome Screen • Destination Selection</i></sub>
</p>

The LCD guides users seamlessly through a predefined loop: destination selection, item checklist, physical verification, and finally, a readiness result.

---

## ☁️ IoT Dashboard

<p align="center">
  <img src="Images/connecting.jpeg" width="40%" alt="Connecting to Blynk">
  &nbsp;&nbsp;&nbsp;&nbsp;
  <img src="Images/blynk_dashboard.jpeg" width="40%" alt="Blynk Live Dashboard">
</p>
<p align="center">
  <sub><i>Wi-Fi / Blynk Connection • Live IoT Dashboard</i></sub>
</p>

The Blynk dashboard provides real-time exposure to the current destination, system status, readiness score, missing items, and live activity logs. Custom destinations can be managed remotely without altering firmware.

---

## 💻 Technologies Used

| Technology | Purpose |
|---|---|
| **ESP32 DevKit V1** | Main microcontroller processing unit |
| **Arduino IDE / C++** | Core embedded firmware development |
| **Blynk IoT** | Cloud dashboard telemetry and remote configuration |
| **Wokwi** | Circuit simulation and pre-deployment validation |
| **Hall Effect Sensors** | Physical object detection and validation |
| **PIR Motion Sensor** | Automatic environmental system activation |
| **LCD I2C + Joystick** | Interactive embedded user interface |

---

## 📂 Repository Structure

```text
Ready2Go-Smart-Embedded-Departure-Assistant/
│
├── Source_Code/       # ESP32 Arduino firmware
├── Report/            # IEEE SSCS project report (PDF)
├── Images/            # Diagrams, screenshots, prototype photos
└── Resources/         # Datasheets, references, assets
