# Task 3 – Upgraded Smart Automatic Lighting System with IoT

## Overview

This project is an enhanced version of the **Task 2 – Automatic Light Detection System**.

In Task 2, the ESP32 monitored ambient light using an LDR sensor and automatically controlled an LED based on a predefined threshold.

For Task 3, the project has been upgraded by integrating **Blynk IoT**, enabling real-time cloud monitoring through both web and mobile dashboards.

---

## Enhancements Over Task 2

The following features were added to the previous project:

- IoT connectivity using Blynk Cloud
- Live monitoring of LDR sensor values
- Real-time Environment Status (BRIGHT/DARK)
- LED status monitoring
- Web Dashboard for remote monitoring
- Mobile Dashboard for remote monitoring
- Manual Override switch through the Blynk dashboard

---

## Components Used

- ESP32
- LDR Sensor Module
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- Blynk IoT Platform
- Wokwi Simulator

---

## Working

The ESP32 continuously reads the light intensity from the LDR sensor.

- If the light intensity falls below the threshold, the environment is detected as **DARK** and the LED turns ON.
- If the light intensity rises above the threshold, the environment is detected as **BRIGHT** and the LED turns OFF.

The ESP32 also sends the following information to the Blynk Cloud:

- LDR Value
- Environment Status
- LED Status

Users can monitor the system remotely using both the Blynk Web Dashboard and the Blynk Mobile App.

---

## Blynk Dashboard

### Datastreams

| Virtual Pin | Function |
|-------------|----------|
| V0 | LDR Value |
| V1 | Environment Status |
| V2 | LED Status |
| V3 | Manual Override |

---

## Project Features

- Automatic light detection
- Automatic LED control
- ESP32 Wi-Fi connectivity
- Real-time cloud monitoring
- Blynk Web Dashboard
- Blynk Mobile Dashboard
- Manual Override mode
- Serial Monitor output

---

## Project Files

- sketch.ino
- diagram.json
- libraries.txt
- circuit.png
- serial_monitor.png
- blynk_web_dashboard.png
- blynk_mobile_dashboard.png
- demo.mp4 *(Optional)*

---

## Future Improvements

- Push notifications for lighting events
- Automatic brightness control using PWM
- Data logging and analytics
- Energy consumption monitoring

---

## Author

**Shree Harshan K**
