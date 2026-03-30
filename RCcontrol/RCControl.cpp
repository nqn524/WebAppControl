#include "Arduino.h"
#include <ArduinoBLE.h>
#include "RCControl.h"

RCControl::RCControl(string Service_UUID, string Chara_UUID, string name) {
	_service = BLEService(Service_UUID);
	_characteristic = BLECharacteristic(Chara_UUID);
	_name = name;
}