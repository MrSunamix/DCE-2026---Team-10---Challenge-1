# Interstellar Escape: Designing Connected Experiences
This project is an interactive escape room module inspired by the tesseract scene in Christopher Nolan's *Interstellar*. It combines physical interaction through a "bookcase" interface with digital feedback to create a collaborative experience where players must work together to navigate a narrative puzzle.

## Project Overview
The module features a physical bookcase where players manipulate books to redirect a laser. Changes in the physical environment are captured by light sensors (LDRs) and transmitted via the OOCSI protocol to a digital visualization.

### Key Features

* **Physical Interaction**: A "bookcase" module built from accessible materials like cardboard and books, featuring a mirror-based laser redirection system.
* **Digital Visualization**: A modified "Voluma" display that provides live feedback based on sensor data.
* **Collaborative Gameplay**: Designed for pairs of players who must communicate to guide each other through tasks.
* **Integrated Communication**: Uses the OOCSI protocol for seamless data exchange between hardware and software.

## Technology Stack

* **Hardware**: ESP32 microcontroller.
* **Firmware**: C++ using PlatformIO or Arduino IDE.
* **Frontend**: HTML/JavaScript for the digital visualization.
* **Communication**: OOCSI protocol for real-time messaging.

## Hardware Requirements

To recreate the physical module, you will need:

* ESP32 (Wifi-capable) 
* Red Laser Module 
* LDR (Light Dependent Resistor) & Resistor 
* Small mirror 
* Cardboard box, books, and colored paper for the bookcase structure 

## Installation & Setup

### 1. Hardware Setup (Arduino/ESP32)

The ESP32 reads voltage from the LDR and sends the data to an OOCSI channel.

1. Connect the LDR to the ESP32 (default pin defined in code).
2. Open the provided C++ code in **PlatformIO** or **Arduino IDE**.
3. Configure your WiFi credentials (`ssid` and `password`) and the OOCSI server address (`oocsi.id.tue.nl`).
4. Flash the code to your ESP32.

### 2. Digital Visualization (Voluma)

The web interface displays live sensor values and a "Crystal Sphere" visualization.

1. Host the provided `index.html` and associated JS files (e.g., using DataFoundry).
2. Ensure the `oocsi-web.js` library is included.
3. Open the page in a browser, enter your OOCSI connection details, and click **CONNECT**.

## Communication Protocol

Data exchange is handled via **OOCSI** using JSON messages.

* **Sender**: ESP32 (LDR values).
* **Receiver**: Modified HTML Voluma parser.
* **Format**: The ESP32 sends a float value representing the LDR voltage to the designated channel.

## Team

* **Group 10** 
* Inspired by the OOCSI-things examples and Nolan's *Interstellar*.
