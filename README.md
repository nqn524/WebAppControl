
# Robot Competition Controller

This is a custom made library and wireless controller accessible through a browser, designed to be compatable for every team in the Univerty of York Robot Competition. If you stumbled upon this repo and you're not part of the UoY then you're unlikekly to find use out of this controller.  
  
The controller is accessible from this link https://www-users.york.ac.uk/~nqn524

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
