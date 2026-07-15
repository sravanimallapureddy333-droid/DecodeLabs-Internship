# 🌱 Project 2 – Automated Irrigation Controller

## 📌 Objective

To monitor soil moisture levels and automatically control irrigation using an ESP32.

## 🛠️ Components Used

- ESP32
- Soil Moisture Sensor (Simulated using Potentiometer)
- Relay Module
- Water Pump (Simulated)
- Arduino IDE
- Wokwi Simulator

## ✨ Features

- Real-Time Soil Moisture Monitoring
- Automatic Pump ON/OFF Control
- Dry, Normal and Wet Soil Detection
- Relay-Based Irrigation Control
- Moisture Percentage Calculation
- Non-Blocking Programming using `millis()`
- Serial Monitor Output

## 🚀 Working

The ESP32 continuously reads the soil moisture value from the sensor. Based on predefined moisture thresholds, it determines whether the soil is dry, normal, or wet. When the soil becomes dry, the relay turns the water pump ON automatically. Once sufficient moisture is detected, the pump turns OFF, ensuring efficient water usage.

## 📁 Files Included

- `Automated Irrigation Controller.ino`
- `Circuit.png`
- `Project execution output.png`

## 💻 Technologies Used

- Embedded C/C++
- ESP32
- Arduino IDE
- Wokwi IoT Simulator

## 📷 Output

The system successfully automates irrigation by monitoring soil moisture and controlling the water pump automatically.
