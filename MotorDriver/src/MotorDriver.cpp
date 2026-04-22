#include "Arduino.h"
#include "MotorDriver.h"
#include "mbed.h"

MotorDriver::MotorDriver():
	leftMotorDir(P0_4),
	leftMotorPwm(P0_27),
	rightMotorDir(P0_5),
	rightMotorPwm(P1_2)
{

}

void MotorDriver::Setup() {
	leftEncoderCount = 0;
	rightEncoderCount = 0;

	leftMotorPwm.period_us(2000);
	rightMotorPwm.period_us(2000);
}

void MotorDriver::StopMotors() {
	leftMotorPwm.write(0.0);
	rightMotorPwm.write(0.0);
}

void MotorDriver::UpdateMotors(float speedLeft, float speedRight) {
	if (speedLeft > 0) {
		leftMotorDir = 0;
	}
	else {
		leftMotorDir = 1;
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
