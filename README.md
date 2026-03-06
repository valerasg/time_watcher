# Time Watcher (MVP)

A simple, modular Arduino-based system to track and display the duration of presence detected by an ultrasonic sensor. This project is an Minimum Viable Product (MVP) designed to count seconds consecutively while a person is within a specific range and stop when no presence is detected.

## 🚀 Overview

The **Time Watcher** uses an HC-SR04 ultrasonic sensor to monitor a defined area (default < 50cm). When someone is detected, a counter starts on a 4-digit, 7-segment display. If the person leaves, the counter pauses. It also features a manual reset button.

## 🛠 Hardware Requirements

- **Microcontroller**: ESP32 / Arduino compatible (configured for ESP32-style pins).
- **Sensor**: HC-SR04 Ultrasonic Sensor.
- **Display**: 4-Digit, 7-Segment Display (Multiplexed).
- **Button**: 1x Push button (for Reset).
- **Others**: Resistors, jumper wires, and a breadboard.

## 🔌 Pin Configuration

Defined in `config.h`:

| Component | Pin | Description |
|-----------|-----|-------------|
| **HC-SR04 TRIG** | 12 | Trigger pin |
| **HC-SR04 ECHO** | 14 | Echo pin |
| **Reset Button** | 13 | Manual reset (Pull-up) |
| **Display Digits**| 25, 26, 32, 33 | D1, D2, D3, D4 |
| **Display Segments**| 15, 2, 4, 16, 17, 5, 18, 19 | A, B, C, D, E, F, G, DP |

## ⚙️ How It Works

1. **Detection**: The system polls the HC-SR04 every 100ms.
2. **Counting**: If the measured distance is less than `DISTANCIA_UMBRAL` (50cm), it starts/continues a second counter.
3. **Display**: The current count is shown in real-time on the 7-segment display.
4. **Reset**: Holding the reset button for 2 seconds will zero out the counter and display "RESE".
5. **Logging**: Serial output provides status updates for presence detection and total session duration.

## 📁 Project Structure

- `time_watcher.ino`: Main logic and state machine.
- `config.h`: Centralized pin definitions and operational parameters.
- `sensor_logic.h`: Logic for distance measurement.
- `display_logic.h`: Multiplexing and character mapping for the 7-segment display.

## 🛠 Setup

1. Connect the hardware according to the [Pin Configuration](#-pin-configuration).
2. **Library Installation**: In the Arduino IDE, go to **Tools** > **Manage Libraries** and install the **SevSeg** library by Dean Reading.
3. Open `time_watcher.ino` in the Arduino IDE.
4. Ensure you have the necessary board support installed (e.g., ESP32 by Espressif).
5. Upload the code to your microcontroller.
6. Open the Serial Monitor at **115200 baud** to see debug logs.

## 🗺 Roadmap (Post-MVP)

- [ ] Integration with Google Cloud (GCloud) for data persistence.
- [ ] Wi-Fi configuration for remote monitoring.
- [ ] Adjustable threshold via a web interface.

---
*Developed as a modular prototype for presence-based time tracking.*
