#include "mbed.h"

#include <RCControl.h>
#include <MotorDriver.h>

RCControl RCC("12345678-1234-1234-1234-123456789abc", "abcdef01-1234-1234-1234-123456789abc", "libTest");
MotorDriver driver;

void setup() {  
  Serial.begin(115200);

  if (!BLE.begin()) {
    Serial.println("BLE failed!");
    while (1);
  }

  RCC.Begin();
  driver.Setup();

  Serial.println("BLE ready. Waiting for connection...");
}

void loop() {
  if (RCC.GetCentral()) {
    Serial.println("Connected!");

    while (RCC.Connected()) {

      if (RCC.JoystickUpdated) {
        float speedLeft = RCC.JoyStickY + RCC.JoyStickX;
        float speedRight = RCC.JoyStickY - RCC.JoyStickX;

        driver.UpdateMotors(speedLeft, speedRight);

        Serial.println(String(RCC.JoyStickX) + "   " + String(RCC.JoyStickY) + "   " + String(speedLeft) + "   " + String(speedRight));
      }

      if (!RCC.Empty()) {
        String data = RCC.Dequeue();
        if (data == "A") {
          driver.StopMotors();
        }
        Serial.println(data);
      }
    }

    Serial.println("Disconnected");
  }
}