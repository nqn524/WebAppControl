#ifndef RCControl_h
#define RCControl_h

#include "Arduino.h"
#include <ArduinoBLE.h>

class RCControl
{
public:
	RCControl(char* Service_UUID, char* Chara_UUID, String name);
	void Begin();

	float JoyStickX;
	float JoyStickY;

	float slider;

	bool GetCentral();
	bool Connected();

	bool JoystickUpdated;

	String Dequeue();
	bool Full();
	bool Empty();
private:
	BLEService _serv;
	BLECharacteristic _char;
	String _name;

	BLEDevice central;

	void StartLoop();

	int _NumOfItems;
	int _frontPointer;
	int _backPointer;
	String _Queue[16];
	bool Enqueue(String data);
};

#endif