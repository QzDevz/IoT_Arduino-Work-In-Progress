# Smart Trashcan with Ultrasonic Sensors and Servo Motor

This project implements a smart trashcan that automatically opens its lid when an object (like a hand) 
is detected nearby using an ultrasonic sensor. The lid closes after 5 seconds. 
Additionally, an internal ultrasonic sensor monitors the trash level and 
lights an LED when the bin is full.

## Components Required

- Arduino Uno (or compatible board) (Aquired)
- 2 x HC-SR04 Ultrasonic Sensors (Aquired)
- 1 x Servo Motor (e.g., SG90) (Aquired)
- 1 x LED (any color) (Aquired)
- 1 x 220Ω Resistor (for LED) (Not Yet)
- Jumper wires (Aquired MtM Only)
- Breadboard (optional) (Not Yet)
- USB cable for programming (Aquired)

## Wiring Diagram

### External Ultrasonic Sensor (for lid opening)
- VCC → 5V on Arduino
- GND → GND on Arduino
- Trig → Pin 9
- Echo → Pin 10

### Internal Ultrasonic Sensor (for fullness detection)
- VCC → 5V on Arduino
- GND → GND on Arduino
- Trig → Pin 12
- Echo → Pin 13

### Servo Motor
- Red (VCC) → 5V on Arduino
- Brown/Black (GND) → GND on Arduino
- Orange/Yellow (Signal) → Pin 11

### LED
- Anode (+) → Pin 8 (through 220Ω resistor)
- Cathode (-) → GND on Arduino

## Setup Instructions

1. Connect all components according to the wiring diagram above.
2. Download and install the Arduino IDE from https://www.arduino.cc/en/software
3. Open the `smart_trashcan.ino` file in Arduino IDE.
4. Select your Arduino board type (e.g., Arduino Uno) from Tools > Board.
5. Select the correct COM port from Tools > Port.
6. Click the Upload button to compile and upload the code to your Arduino.

## Usage

1. Power the Arduino using USB or external power supply.
2. Open the Serial Monitor in Arduino IDE (Tools > Serial Monitor) at 9600 baud to see debug messages.
3. Place your hand or object within 30 cm of the external ultrasonic sensor - the lid should open.
4. The lid will automatically close after 5 seconds.
5. When trash fills up and the internal distance is less than 10 cm, the LED will light up indicating the bin is full.

## Code Explanation

- **External Sensor**: Measures distance to detect approaching objects and controls the servo to open/close the lid.
- **Internal Sensor**: Measures distance inside the bin to detect fullness level.
- **Servo Motor**: Rotates to open (90°) and close (0°) the trashcan lid.
- **LED**: Indicates when the trashcan is full.
- **Thresholds**: External detection at 30 cm, fullness at 10 cm (adjust in code as needed).

## Customization

- Adjust `thresholdDistance` for external detection range.
- Adjust `fullThreshold` for fullness detection (based on your bin height).
- Modify servo angles if needed for your lid mechanism.
- Add more features like buzzer for full indication.

## Troubleshooting

- Ensure ultrasonic sensors are not interfering with each other (position them appropriately).
- Check wiring connections if sensors don't work.
- Verify power supply (5V for all components).
- Use Serial Monitor to debug distance readings.

## License

This project is open-source. Feel free to modify and distribute.
- Yoruhsika 2025