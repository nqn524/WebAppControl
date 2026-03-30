#ifndef "RCControl_h"
#define "RCControl_h"

#include "Arduino.h"
#include <ArduinoBLE.h>

class RCControl
{
public:
	RCControl(string Service_UUID, string Chara_UUID, string name);
private:
	BLEService _service;
	BLECharacteristic _characteristic;
	string _name;
};

#endif