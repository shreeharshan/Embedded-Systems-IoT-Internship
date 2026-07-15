# Task 3 – Smart Automatic Lighting System

## Objective
Develop an IoT-based automatic lighting system using an ESP32 and an LDR sensor. The system automatically controls an LED based on ambient light intensity and provides real-time monitoring through the Blynk IoT platform.

## Components Used
- ESP32
- LDR Sensor Module
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- Blynk IoT Platform
- Wokwi Simulator

## Working Principle
The ESP32 continuously reads the light intensity from the LDR sensor.

- If the LDR value is below the threshold, the environment is considered DARK and the LED turns ON.
- If the LDR value is above the threshold, the environment is considered BRIGHT and the LED turns OFF.

The sensor value and device status are displayed on:
- Serial Monitor
- Blynk Web Dashboard
- Blynk Mobile Dashboard

## Features
- Automatic lighting control
- Real-time LDR monitoring
- Web dashboard monitoring
- Mobile dashboard monitoring
- ESP32 Wi-Fi connectivity
- Cloud-based IoT using Blynk

## Blynk Datastreams

| Virtual Pin | Purpose |
|-------------|---------|
| V0 | LDR Value |
| V1 | Environment (DARK/BRIGHT) |
| V2 | LED Status |

## Threshold
```
2000
```

## Output

### DARK Environment
- LED ON
- Environment = DARK

### BRIGHT Environment
- LED OFF
- Environment = BRIGHT

## Project Files

- sketch.ino
- diagram.json
- libraries.txt
- circuit.png
- serial_monitor.png
- blynk_web_dashboard.png
- blynk_mobile_dashboard.png

## Author

Shree Harshan
