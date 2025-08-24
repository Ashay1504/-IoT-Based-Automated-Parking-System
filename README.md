# IoT-Based Automated Parking System

## Overview
This project demonstrates an **IoT-based automated parking gate system** using an Arduino Nano, an ultrasonic sensor, and a servo motor. The system automatically detects vehicles and opens/closes the gate based on their presence, improving parking efficiency and security.

## Features
- Automatic detection of vehicles using the **HC-SR04 ultrasonic sensor**.
- **Servo-controlled gate** opens when a vehicle is detected and closes when the parking spot is empty.
- Real-time monitoring via **Serial output**.
- Simple, cost-effective, and expandable for IoT integration.

## Hardware Required
- Arduino Nano (or compatible clone)
- HC-SR04 Ultrasonic Sensor
- MG90S Micro Servo Motor
- Jumper wires
- Breadboard (optional)
- USB cable for Arduino

## Circuit Diagram
- **VCC** of HC-SR04 → **5V** on Arduino  
- **GND** of HC-SR04 → **GND** on Arduino  
- **TRIG** → Arduino pin 2  
- **ECHO** → Arduino pin 3  
- **Servo Signal** → Arduino pin 5  
- **Servo VCC/GND** → Arduino 5V/GND or external 5V power if servo is under load

> ⚠ Note: Avoid connecting devices to Arduino pins 0 and 1 during uploads, as they are used for communication.

## Software Required
- Arduino IDE
- CH340 Driver (for Nano clones)

## How It Works
1. The **ultrasonic sensor** continuously measures distance.  
2. When a vehicle/object is detected within 25 cm, the servo moves to **90°** to open the gate.  
3. The gate remains open as long as the object is detected.  
4. After the vehicle leaves and no object is sensed for several consecutive readings, the gate closes automatically.

## Usage
1. Connect the hardware as described above.  
2. Open the Arduino IDE and select **Arduino Nano** and **ATmega328P (Old Bootloader)**.  
3. Select the correct COM port and upload the code.  
4. Monitor distance readings in the Serial Monitor if desired.

## Code
The Arduino code for this project is available in `ParkingSystem.ino`.

---

## Author
Archisha Bodhmage

## License
This project is open-source under the MIT License.
