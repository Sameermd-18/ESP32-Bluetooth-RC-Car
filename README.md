<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Bluetooth%20RC%20Car-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Motor%20Driver-L298N-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Control-Dabble%20App-green?style=for-the-badge" />
</p>

<h1 align="center">🚗 ESP32 Bluetooth RC Car (4-Motor Differential Drive)</h1>

<p align="center">
A beginner-friendly robotics project using an ESP32, L298N motor driver, PWM motor control, and Bluetooth control using the Dabble GamePad app.
</p>

---

## ✨ Features
- 🚀 Bluetooth control via **Dabble App**
- ⚙️ 4-motor drive (2 motors per side)
- 🧭 Differential tank-style turning
- 🎚 Smooth PWM speed control
- 🔧 Modular motor control using `rotateMotor()`
- 👶 Perfect for beginners learning robotics + embedded systems

---

## 🌸 How Movement Works

The robot does NOT control 4 motors separately —  
It controls **two motor groups**:

- **Right Side Motors (2 motors)**  
- **Left Side Motors (2 motors)**  

These two sides create differential steering (tank-style movement):

| Movement | Right Side | Left Side |
|----------|------------|-----------|
| **Forward** | +Speed | +Speed |
| **Backward** | -Speed | -Speed |
| **Turn Left** | +Speed | -Speed |
| **Turn Right** | -Speed | +Speed |
| **Stop** | 0 | 0 |

This makes the robot simple, stable, and easy to control.

---

## 🔌 Wiring (ESP32 → L298N Motor Driver)

### **Right Motor Group**
