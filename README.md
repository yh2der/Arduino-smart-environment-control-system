# Arduino Smart Environment Control System

## Project Overview
This project implements an intelligent environment control system using Arduino, with a companion mobile app created using MIT App Inventor. It monitors temperature, humidity, and light intensity, and controls multiple lights and a heating mat either automatically or manually via Bluetooth.

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
1. Run the mobile app on your Android device.
2. Connect to the Arduino system via Bluetooth using the app.
3. Use the app interface to:
   - Switch between manual and automatic modes
   - Control individual lights and the heating mat in manual mode
   - Monitor temperature, humidity, and light intensity
   - View the current status of all devices

### Manual Mode
- Use the app to send commands for controlling individual lights and the heating mat.
- Option to turn on all lights and the heating mat simultaneously.

### Automatic Mode
- The system will adjust lighting and heating based on environmental conditions:
  - Lights adjust based on temperature and detected presence.
  - Heating mat activates when light intensity is low.

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

## Contributing
Contributions to improve the system are welcome. Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature.
3. Submit a pull request with a clear description of your changes.