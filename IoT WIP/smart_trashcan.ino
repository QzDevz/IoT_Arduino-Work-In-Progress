// Smart Trashcan with Ultrasonic Sensor and Servo Motor
// This code uses an ultrasonic sensor to detect objects and opens the trashcan lid using a servo motor.

#include <Servo.h>

// Pin definitions
const int trigPin = 9;      // External ultrasonic sensor trigger pin
const int echoPin = 10;     // External ultrasonic sensor echo pin
const int servoPin = 11;    // Servo motor pin
const int trigPin2 = 12;    // Internal ultrasonic sensor trigger pin
const int echoPin2 = 13;    // Internal ultrasonic sensor echo pin
const int ledPin = 8;       // LED pin for full indication

// Servo object
Servo lidServo;

// Distance threshold in cm (adjust as needed)
const int thresholdDistance = 30;
const int fullThreshold = 10;  // Distance to consider trashcan full (adjust based on bin height)

// Servo angles
const int closedAngle = 0;   // Lid closed
const int openAngle = 90;    // Lid open

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach servo to pin
  lidServo.attach(servoPin);

  // Start with lid closed
  lidServo.write(closedAngle);
  delay(1000);  // Wait for servo to reach position
}

void loop() {
  // Measure distance from external sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Calculate distance in cm

  // Print distance for debugging
  Serial.print("External Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if object is detected within threshold
  static unsigned long lidOpenTime = 0;
  static bool lidIsOpen = false;

  if (distance > 0 && distance < thresholdDistance) {
    if (!lidIsOpen) {
      // Open the lid
      lidServo.write(openAngle);
      Serial.println("Lid opened");
      lidOpenTime = millis();
      lidIsOpen = true;
    }
  }

  if (lidIsOpen && (millis() - lidOpenTime > 5000)) {  // 5 seconds delay
    // Close the lid
    lidServo.write(closedAngle);
    Serial.println("Lid closed");
    lidIsOpen = false;
  }

  // Measure distance from internal sensor to check if trashcan is full
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;  // Calculate distance in cm

  // Print internal distance for debugging
  Serial.print("Internal Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Check if trashcan is full
  if (distance2 > 0 && distance2 < fullThreshold) {
    digitalWrite(ledPin, HIGH);  // Turn on LED to indicate full
    Serial.println("Trashcan is full!");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  // Small delay before next measurement
  delay(500);
}