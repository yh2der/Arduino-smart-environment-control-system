# Arduino Smart Environment Control System

## Project Overview
This project implements an intelligent environment control system using Arduino for the turtle environment (but it could be transferred to any other environment), with a companion mobile app created using MIT App Inventor. It monitors temperature, humidity, and light intensity, and controls multiple lights and a heating mat either automatically or manually via Bluetooth.

## Hardware Requirements
- Arduino board
- DHT11 temperature and humidity sensor
- Photoresistor (light sensor)
- 2x Ultrasonic distance sensors
- 4x LED lights
- Bluetooth module

## Software Dependencies
- Arduino IDE
  - SimpleDHT library
  - SoftwareSerial library
- MIT App Inventor

## Features
- Temperature and humidity monitoring
- Light intensity detection
- Distance sensing
- Automatic and manual control modes
- Bluetooth communication for remote control
- Mobile app interface for easy control and monitoring

## Installation and Setup
### Arduino Setup
1. Connect the hardware components to the Arduino board according to the pin configurations in the code.
2. Install the required libraries in the Arduino IDE.
3. Upload the provided code to your Arduino board.

### Mobile App Setup
1. Download and unzip the `.aia` file for the mobile app.
2. Log in to MIT App Inventor (appinventor.mit.edu) and upload the `.aia` file in the projects section.
3. Compile the app into an APK.
4. Install the APK on your Android device.

## Usage Instructions

### Connecting to the System
1. Open the mobile application.
2. Click the button next to "Bluetooth Connection Status" to scan for Bluetooth devices.
3. Select the appropriate Bluetooth device from the list to connect.

### Switching Between Auto/Manual Modes
- On the main app interface, choose "Auto" or "Manual" to switch control modes.

### Operating in Automatic Mode
In automatic mode, the system adjusts based on environmental conditions:
- Heating devices turn on automatically when temperature falls below set value.
- Lights activate when light intensity is low.
- Relevant lights turn on when presence is detected nearby.

### Operating in Manual Mode
In manual mode, you can:
1. Use sliders to control the brightness of each heating lamp (Heating Lamps 1-4).
2. Use toggle switches to control the on/off status of the heating mat.
3. Click the "On/Off" button to control all devices simultaneously.

### Data Display
- The main app interface displays real-time temperature and humidity data.
- You can view the current status (on/off) of each device.

### Special Features
- Automated control allows for environment management based on predefined conditions.
- Manual control offers fine-tuned adjustment for each device.
- Bluetooth connection ensures stable remote control.

## Code Structure
### Arduino Code
- `setup()`: Initializes serial communication and pin modes.
- `loop()`: Main program loop, handles sensor readings and control logic.
- `readBT()`: Reads Bluetooth commands.
- `readNum()`: Interprets numeric commands.
- `ping()` and `ping2()`: Measure distances using ultrasonic sensors.

### Mobile App
- Created using MIT App Inventor
- Provides a user-friendly interface for controlling and monitoring the Arduino system
- Communicates with the Arduino via Bluetooth

## Testing
After installation, run the app on your Android device and test all functionalities as needed.

## Troubleshooting
1. If Bluetooth connection fails, ensure:
   - The Arduino system is powered on
   - The Bluetooth module is correctly connected and configured
   - Your phone's Bluetooth is turned on
2. If data display is abnormal, check if sensors are correctly connected.
3. If lights or heating mat can't be controlled, check corresponding wiring and power supply.

## Contributing
Contributions to improve the system are welcome. Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature.
3. Submit a pull request with a clear description of your changes.
