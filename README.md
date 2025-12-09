🚗 ESP32 Bluetooth RC Car (4‑Motor Differential Drive)
📌 Overview
This project is a Bluetooth‑controlled RC car built using an ESP32, an L298N motor driver, and 4 DC motors (two motors per side). It uses the Dabble GamePad module for Bluetooth control and ESP32 PWM for smooth speed control.
✨ Features
• Bluetooth control via Dabble App
• 4‑motor drive (2 motors per side)
• Differential tank‑style turning
• PWM speed control using ESP32 LEDC
• Modular motor control using rotateMotor()
• Beginner‑friendly and easy to expand
🧠 How Movement Works
The robot controls two motor groups:

• Right Side Motors (2 motors)
• Left Side Motors (2 motors)

Movement behavior:
• **Forward:** right +speed, left +speed
• **Backward:** right -speed, left -speed
• **Turn Left:** right +speed, left -speed
• **Turn Right:** right -speed, left +speed
• **Stop:** right 0, left 0
🔌 Wiring (ESP32 → L298N)
Right Motors:
  • ENA → GPIO 25 (PWM)
  • IN1 → GPIO 27
  • IN2 → GPIO 26

Left Motors:
  • ENB → GPIO 33 (PWM)
  • IN3 → GPIO 14
  • IN4 → GPIO 12

Motors:
  • OUT1 & OUT2 → Right side motors
  • OUT3 & OUT4 → Left side motors

Power:
  • Motor Power → 7.4V Li‑ion/LiPo
  • ESP32 Power → USB or regulated 5V
📱 Bluetooth Controls (Dabble App)
• Up Arrow → Forward
• Down Arrow → Backward
• Left Arrow → Spin Left
• Right Arrow → Spin Right
💻 Code Overview
Key components:

PWM setup:
  • ledcSetup(4, 1000, 8);   // right side
  • ledcSetup(5, 1000, 8);   // left side

Direction + speed:
  • rotateMotor(rightMotorSpeed, leftMotorSpeed);

Gamepad logic assigns speeds based on the button pressed.
🎯 What I Learned
• Basics of DC motor control
• How H‑bridge drivers work
• PWM and ESP32 LEDC channels
• Bluetooth communication using Dabble
• Differential drive steering
• How to combine hardware + software
🚀 Future Improvements
• Smooth acceleration (PWM ramping)
• Joystick steering
• Line following
• Obstacle avoidance
• ESP32‑CAM for video streaming
• PID‑based straight driving
