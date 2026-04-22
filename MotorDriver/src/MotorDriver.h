#ifndef MotorDriver_h
#define MotorDriver_h

#include "Arduino.h"
#include "mbed.h"

using namespace mbed;

class MotorDriver
{
public:
	MotorDriver();
	void Setup();

	void StopMotors();
	void UpdateMotors(float speedLeft, float speedRight);

	volatile int leftEncoderCount;
	volatile int rightEncoderCount;

	DigitalOut leftMotorDir;
	PwmOut leftMotorPwm; 
	DigitalOut rightMotorDir;
	PwmOut rightMotorPwm;

private:
	int exist;
};

#endif