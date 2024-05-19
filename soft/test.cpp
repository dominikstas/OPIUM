#include <Servo.h>

// TEST CODE
// RC
// TO ADD: Flight recorder

// Pin definitions
const int redLedPin = 2;
const int greenLedPin = 3;
const int servoPin1 = 9;
const int servoPin2 = 10;
const int rcChannel1 = A0;
const int rcChannel2 = A1;

// Variables for LED blinking
unsigned long previousMillis = 0;
const long interval = 500; // interval at which to blink (milliseconds)
bool ledState = false;

// Servo objects
Servo servo1;
Servo servo2;

void setup() {
  // Initialize LEDs
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // Initialize servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Blink LEDs
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(redLedPin, ledState);
    digitalWrite(greenLedPin, ledState);
  }

  // Read RC channels
  int channel1Value = analogRead(rcChannel1);
  int channel2Value = analogRead(rcChannel2);

  // Map RC values to servo positions
  int servo1Pos = map(channel1Value, 0, 1023, 0, 180);
  int servo2Pos = map(channel2Value, 0, 1023, 0, 180);

  // Set servo positions
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);

  // Print values to serial monitor (for debugging)
  Serial.print("Channel 1: ");
  Serial.print(channel1Value);
  Serial.print(" | Servo 1: ");
  Serial.print(servo1Pos);
  Serial.print(" | Channel 2: ");
  Serial.print(channel2Value);
  Serial.print(" | Servo 2: ");
  Serial.println(servo2Pos);

  // Small delay to prevent overwhelming the serial output
  delay(20);
}
