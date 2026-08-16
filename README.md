# Road Accident Detection & Emergency Alert System

## Overview

This project is an **IoT-based road accident detection and emergency alert system** designed to improve emergency response in case of a road accident.

The system uses an **ESP32 LILYGO TTGO with SIM800L** to send an emergency SMS when an accident is detected. An **accelerometer** is used to detect impact or abnormal vibration, while a **GPS module** is used to retrieve the current location.

A **mobile application** is also included to provide a user interface for user information and system interaction.

This project combines **embedded systems, IoT communication, GPS/GSM technologies and mobile development** in one practical safety solution.

---

## Main Features

- Accident detection using an **accelerometer**
- Emergency SMS alert sending using **SIM800L**
- GPS location acquisition
- Google Maps location sharing
- ESP32-based embedded implementation
- Mobile application interface
- Compact integrated hardware prototype

---

## Hardware Prototype

### Project Enclosure

<img src="docs/images/project-case.jpg" alt="Project Enclosure" width="320">

### Internal Electronics

<img src="docs/images/project-board.jpg" alt="Project Board" width="320">
<img src="docs/images/project-inside.jpg" alt="Project Inside View" width="320">
<img src="docs/images/project-side.jpg" alt="Project Side View" width="320">

This prototype integrates the embedded electronics inside a custom enclosure.  
The hardware includes the **ESP32 LILYGO TTGO**, **SIM800L**, **accelerometer**, and **GPS-related connectivity**.

---

## Mobile Application & Alert Example

### Emergency SMS Alert

<img src="docs/images/sms-alert.jpg" alt="SMS Alert Example" width="300">

The system sends an emergency SMS containing the accident alert and a **Google Maps location link** to help responders identify the accident location quickly.

### Mobile Application Interface

<img src="docs/images/mobile-app-form.jpg" alt="Mobile App Interface" width="300">

The mobile application provides a user interface for entering user-related information and interacting with the system.

> For public sharing, demo data or anonymized screenshots are recommended.

---

## Hardware Components

- **ESP32 LILYGO TTGO**
- **SIM800L GSM/GPRS module**
- **Accelerometer sensor**
- **GPS module**
- Power supply / battery system
- Custom enclosure / prototype assembly

---

## Software Components

- **Embedded C / Arduino**
- **Flutter**
- **Dart**
- **GPS communication**
- **GSM / SMS communication**

---

## How It Works

1. The accelerometer continuously monitors vibration and sudden impact.
2. When a strong impact is detected, the system identifies it as a possible accident.
3. The GPS module retrieves the current position.
4. The ESP32 LILYGO TTGO processes the event.
5. The SIM800L sends an emergency SMS alert.
6. The alert includes a location link that can be opened in Google Maps.
7. The mobile application supports the user-side interaction of the system.

---

## System Architecture

```text
Accelerometer
      ↓
 Accident Detection
      ↓
ESP32 LILYGO TTGO
      ↓
GPS Location
      ↓
SIM800L
      ↓
SMS Emergency Alert
      ↓
Emergency Contact

      +

Flutter Mobile Application
