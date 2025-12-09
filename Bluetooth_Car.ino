#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// --- Motor Pin Mapping ---
int enableRightMotor = 25; 
int rightMotorPin1   = 27;
int rightMotorPin2   = 26;

int enableLeftMotor  = 33;
int leftMotorPin1    = 14;
int leftMotorPin2    = 12;

#define MAX_MOTOR_SPEED 255

// PWM Settings
const int PWMFreq = 1000; 
const int PWMResolution = 8;
const int rightMotorPWMSpeedChannel = 4;
const int leftMotorPWMSpeedChannel  = 5;

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  // Right motor direction
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
  else
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Left motor direction
  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }
  else
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // PWM duty
  ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
  ledcWrite(leftMotorPWMSpeedChannel,  abs(leftMotorSpeed));
}

void setUpPinModes()
{
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // PWM setup
  ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);
  ledcSetup(leftMotorPWMSpeedChannel, PWMFreq, PWMResolution);

  ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
  ledcAttachPin(enableLeftMotor,  leftMotorPWMSpeedChannel);

  rotateMotor(0, 0); 
}

void setup()
{
  setUpPinModes();
  Dabble.begin("MyBluetoothCar");
}

void loop()
{
  int rightMotorSpeed = 0;
  int leftMotorSpeed  = 0;

  Dabble.processInput();

  if (GamePad.isUpPressed())
  {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed  = MAX_MOTOR_SPEED;
  }
  else if (GamePad.isDownPressed())
  {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed  = -MAX_MOTOR_SPEED;
  }
  else if (GamePad.isLeftPressed())
  {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed  = -MAX_MOTOR_SPEED;
  }
  else if (GamePad.isRightPressed())
  {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed  = MAX_MOTOR_SPEED;
  }

  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}
