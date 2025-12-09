🚗 ESP32 Bluetooth RC Car (4-Motor Differential Drive)

This project is a Bluetooth-controlled RC car built using an ESP32, an L298N motor driver, and 4 DC motors (two motors per side).
Control is done through the Dabble App Gamepad, and the robot uses PWM for smooth motor speed control.

This is my first robotics project, where I learned motor drivers, PWM, Bluetooth control, and differential steering.

⭐ Features

Bluetooth control using Dabble (GamePad Module)

4-motor drive system (2 motors per side)

Differential steering (tank-style turns)

PWM-based speed control (smooth acceleration)

Simple, modular motor control using rotateMotor()

ESP32 LEDC (PWM channels) for motor speed

🧠 How Movement Works

The robot doesn’t control 4 motors individually.
Instead, it controls two sides:

Right Motor Group (2 motors)

Left Motor Group (2 motors)

Movement logic:

Command	Right Side	Left Side
Forward	+Speed	+Speed
Backward	-Speed	-Speed
Turn Left	+Speed	-Speed
Turn Right	-Speed	+Speed
Stop	0	0

These speed values are passed into:

rotateMotor(rightSpeed, leftSpeed);


which handles:

motor direction

motor speed (PWM)

🔌 Wiring Diagram (ESP32 → L298N)
Right Motors
ENA → GPIO 25  (PWM)
IN1 → GPIO 27  (Direction 1)
IN2 → GPIO 26  (Direction 2)

Left Motors
ENB → GPIO 33  (PWM)
IN3 → GPIO 14  (Direction 1)
IN4 → GPIO 12  (Direction 2)

Motors

OUT1 & OUT2 → Right side motors

OUT3 & OUT4 → Left side motors

Power

7.4V Li-ion / LiPo battery → motor input

ESP32 powered separately via USB or 5V regulator

📱 Bluetooth Control (Dabble App)

Install the Dabble app → choose GamePad Module.

Controls:

Up Arrow → Move Forward

Down Arrow → Move Backward

Left Arrow → Spin Left

Right Arrow → Spin Right

📄 Code Overview

The full code is in main.ino.

Key parts:

✔ Setup PWM Channels
ledcSetup(4, 1000, 8);   // Right motor PWM
ledcSetup(5, 1000, 8);   // Left motor PWM

✔ Direction + Speed Control Function
rotateMotor(rightMotorSpeed, leftMotorSpeed);

✔ Gamepad Logic

Depending on the button pressed, motor speeds are assigned.
