#include "Arduino.h"
#include <ArduinoBLE.h>
#include "RCControl.h"

RCControl::RCControl(char* Service_UUID, char* Chara_UUID, String name):
	    _serv(Service_UUID),
	    _char(Chara_UUID, BLEWrite, 20)
    {
	_name = name;
}

void RCControl::Begin() {
    String fullName = String("RC-Car ") + _name;
    BLE.setLocalName(fullName.c_str());
    BLE.setAdvertisedService(_serv);
    _serv.addCharacteristic(_char);
    BLE.addService(_serv);

    BLE.advertise();
}

bool RCControl::GetCentral() {
	central = BLE.central();
	return central;
}

bool RCControl::Connected() {
    if (central.connected()) {
        StartLoop();
    }

    return central.connected();
}

void RCControl::StartLoop() {
    JoystickUpdated = false;

	if (_char.written() && _char.valueLength() >= 1) {
        int length = _char.valueLength();
        const uint8_t* raw = _char.value();

        String data = "";
        for (int i = 0; i < length; i++) {
            data += (char)raw[i];
        }

        if (data.startsWith("js,")) {
            JoystickUpdated = true;

            data = data.substring(3);

            String splitData[1];
            int index = 0;
            String cur;
            for (int i = 0; i < data.length(); i++) {
                if (data.substring(i, i + 1) == ",")
                {
                    splitData[index] = cur;
                    cur = "";
                    index += 1;
                }
                else
                {
                    cur = cur + data[i];
                }
            }

            JoyStickX = (splitData[0].toFloat()) / 128 - 1;
            JoyStickY = (splitData[1].toFloat()) / 128 - 1;
        }
        else {
            Enqueue(data);
        }
	}
}

String RCControl::Dequeue() {
    if (!Empty()) {
        String DataToReturn = _Queue[_frontPointer];

        _frontPointer += 1;

        if (_frontPointer >= 16) {
            _frontPointer = 0;
        }

        _NumOfItems -= 1;

        return DataToReturn;
    }
    else {
        return "";
    }
}

bool RCControl::Enqueue(String data) {
    if (!Full()) {
        _Queue[_backPointer] = data;
        _backPointer += 1;
        if (_backPointer >= 16) {
            _backPointer = 0;
        }

        _NumOfItems += 1;

        return true;
    }
    else { return false; }
}

bool RCControl::Full() {
    return _NumOfItems == 16;
}

bool RCControl::Empty() {
    return _NumOfItems == 0;
}