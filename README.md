# 📱 ESP32 Environmental Station with OLED Display & Alert System

An embedded IoT environmental monitoring system built with ESP32, featuring local OLED graphic display rendering and automated hardware alert triggers based on temperature thresholds. Simulated via Wokwi.

## 🚀 Features
* **Graphical UI Display:** Real-time temperature (°C) and relative humidity (%) visualization on a 0.96" SSD1306 OLED via I2C interface.
* **Automated Threshold Alert:** Dynamic UI status indicator (`ALERT` / `NORMAL`) and automatic GPIO LED trigger when ambient temperature exceeds 28.0°C.
* **Modular Codebase:** Built using structured embedded C++ on the Arduino Framework with `Adafruit_SSD1306` and `DHT` libraries.

## 🛠️ Tech Stack
* **Microcontroller:** ESP32
* **Display:** 0.96" SSD1306 OLED (I2C)
* **Sensor:** DHT22 Temperature & Humidity Sensor
* **Language/Framework:** Embedded C++ (Arduino Framework)
* **Simulator:** Wokwi
