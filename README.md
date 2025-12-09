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

ENA → GPIO 25 (PWM)
IN1 → GPIO 27
IN2 → GPIO 26


### 🟩 Left Motor Group


ENB → GPIO 33 (PWM)
IN3 → GPIO 14
IN4 → GPIO 12


### 🟧 Motor Outputs (L298N)


OUT1 & OUT2 → Right motors
OUT3 & OUT4 → Left motors


### 🔋 Power Setup


Motor Power → 7.4V Li-ion / LiPo
ESP32 → USB 5V / regulated 5V
COMMON GND between battery, driver, and ESP32 (VERY important)


---

## 📱 Dabble GamePad Controls

| Button | Action |
|--------|--------|
| ⬆️ Up | Forward |
| ⬇️ Down | Backward |
| ⬅️ Left | Spin Left |
| ➡️ Right | Spin Right |

---

## 💻 Code Overview

### PWM Setup
```cpp
ledcSetup(4, 1000, 8);  // Right side PWM
ledcSetup(5, 1000, 8);  // Left side PWM

Running Motors
rotateMotor(rightMotorSpeed, leftMotorSpeed);

GamePad Input Logic

Speed values are assigned based on button presses.

🎯 What I Learned

How H-bridge motor drivers reverse motors

Why PWM is required for speed control

ESP32 LEDC PWM channels

Bluetooth communication using Dabble

Differential drive (tank turning)

Hardware + software integration

🚀 Future Improvements

Smooth acceleration (PWM ramping)

Joystick steering mode

Ultrasonic obstacle avoidance

ESP32-CAM live video streaming

PID-based straight driving

Encoder-based speed correction
