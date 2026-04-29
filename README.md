# Robot Competition Controller

This is a custom made library and wireless controller accessible through a browser, designed to be compatable for every team in the Univerty of York Robot Competition. This will only work on the Arduino Nano 33 BLE sense that every team has been provided. If you stumbled upon this repo and you're not part of the UoY then you're unlikekly to find use out of this controller.  
  
The controller is accessible from this link https://www-users.york.ac.uk/~nqn524

# Disclaimer
The webapp is not compatable with IOS devices due to Apple's higher security concerns, limiting websites from accessing Bluetooth devices

# How to install the library

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software/)
2. Install the `ArduinoBLE` library through the Arduino IDE library manager
    - You will be asked if you want to install `Arduino_SpiNINA` library, select `Install all`
3. Downlaod and extract the zip file from the Github's [releases](releases) page
4. Copy the `RCContol` folder into `Documents > Arduino > libraries`. The file structre should look like the following:  

└── Arduino/  
│    └── libraries/  
│    │    ├── Arduino_SpiNINA/  
│    │    ├── ArduinoBLE/  
│    │    └── RCControl/  
│    │    │    ├── examples/  
│    │    │    ├── src/  
│    │    │    ├── Keywords.txt  
│    │    │    └── library.properties  

5. You will now want to restart the Arduino IDE to allow it to recognise the RCContol library
6. Everything should now be setup. 
 - There is an example that you can access through the Arduino IDE, open it by going:  
`File > Examples > RobotCompControl > ExampleMotorControl`  
Assuming everything is installed correctly this should work immedietly when you upload to your Arduino
 - Alternatively you can access it from the Github [here](RCControl/examples/ExampleMotorControl/ExampleMotorControl.ino)
7. `Example` in the following line is the broadcasted name of the Arduino. Change this to something reasonable like your team name or something similar  
`RCControl RCC("12345678-1234-1234-1234-123456789abc", "abcdef01-1234-1234-1234-123456789abc", "Example");`

# How to use website

1. Connect your Arduino to power
2. Ensure Bluetooth is enabled on your device
3. On the website press connect. A small window will appear, when your Arduino shows up in the list select it and connect to it.
4. After a moment the website should show the connection successful, move the joystick around and it should start moving the motors.

# Author and Maintainer

The Author and Maintainer of this Github, the RCContol library and the website is Karl Smirthwaite, if you need to contact me for any reason, please email me at nqn524@york.ac.uk
