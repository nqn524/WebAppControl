#include "mbed.h"

#include <RCControl.h>

using namespace mbed;

RCControl RCC("12345678-1234-1234-1234-123456789abc", "abcdef01-1234-1234-1234-123456789abc", "libTest");

/////////////////////////////////////////////////////////////

DigitalOut leftMotorDir(P0_4);
PwmOut     leftMotorPwm(P0_27);

DigitalOut rightMotorDir(P0_5);
PwmOut     rightMotorPwm(P1_2);

//InterruptIn leftEncoder(P1_11);
//InterruptIn rightEncoder(P1_12);

//volatile int leftEncoderCount = 0;
//volatile int rightEncoderCount = 0;

/////////////////////////////////////////////////////////////

void setup() {

  // Set PWM frequency
  leftMotorPwm.period_us(2000);
  rightMotorPwm.period_us(2000);

  stopMotors();

  // Encoder interrupts
  //leftEncoder.rise(&onLeftEncoderRise);
  //rightEncoder.rise(&onRightEncoderRise);
  

  Serial.begin(115200);

  if (!BLE.begin()) {
    Serial.println("BLE failed!");
    while (1);
  }

  RCC.Begin();

  Serial.println("BLE ready. Waiting for connection...");
}

void loop() {
  if (RCC.GetCentral()) {
    Serial.println("Connected!");

    while (RCC.Connected()) {

      if (RCC.JoystickUpdated) {
        float speedLeft = (RCC.JoyStickY + RCC.JoyStickX) * RCC.slider;
        float speedRight = (RCC.JoyStickY - RCC.JoyStickX) * RCC.slider;

        updateMotors(speedLeft, speedRight);

        Serial.println(String(RCC.JoyStickX) + "   " + String(RCC.JoyStickY) + "   " + String(speedLeft) + "   " + String(speedRight));
      }

      if (!RCC.Empty()) {
        String data = RCC.Dequeue();
        Serial.println(data);
      }
    }

    Serial.println("Disconnected");
  }
}

void stopMotors() {
  leftMotorPwm.write(0.0);
  rightMotorPwm.write(0.0);
}

void updateMotors(float speedLeft, float speedRight) {

  if (speedLeft > 0) {
    leftMotorDir = 1;
  }
  else {
    leftMotorDir = 0;
  }

  if (speedRight > 0) {
    rightMotorDir = 1;
  }
  else {
    rightMotorDir = 0;
  }

  leftMotorPwm.write(abs(speedLeft));
  rightMotorPwm.write(abs(speedRight));
}

//void onLeftEncoderRise() {
//  leftEncoderCount++;
//}
//
//void onRightEncoderRise() {
//  rightEncoderCount++;
//}