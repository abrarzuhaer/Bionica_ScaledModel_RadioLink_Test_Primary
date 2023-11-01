/*
     Servo Motor Control using the Arduino Servo Library
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9,600,2300);  // (pin, min, max)
}

void loop() {
  myservo.write(0);  // tell servo to go to a particular angle
  delay(1000);
  
  myservo.write(90);              
  delay(500); 
  
  myservo.write(135);              
  delay(500);
  
  myservo.write(180);              
  delay(1500);                     
}


/*
     Servo Motor Control - 50Hz Pulse Train Generator
*/

// #define servoPin 9

// void setup() {
//   pinMode(servoPin, OUTPUT);
// }

// void loop() {
//    // A pulse each 20ms
//     digitalWrite(servoPin, HIGH);
//     delayMicroseconds(1450); // Duration of the pusle in microseconds
//     digitalWrite(servoPin, LOW);
//     delayMicroseconds(18550); // 20ms - duration of the pusle
//     // Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
// }