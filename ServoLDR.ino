/* 

 Servo : LDR 
 Goal of the program : Controls a servo using the light level measured by an LDR. 
 Main Theme : Using Analog Input to control a servo.

*/

#include <Servo.h>           // Includes the Servo library

Servo myservo;               // Creates a Servo object to control the servo

int ldrPin = A0;             // Analog pin connected to the LDR
int val;                     // Variable to store the analog reading from the LDR
int deg;                     // Variable to store the mapped angle for the servo


void setup() {

  myservo.attach(9);         // Attaches the servo on pin 9 to the Servo object
  Serial.begin(9600);        // Starts communication with the Serial Monitor
  pinMode(ldrPin, INPUT);    // Sets the LDR pin as an input

}


void loop() {

  val = analogRead(ldrPin);                  // Reads the analog value from the LDR (e.g., 560–960)

  deg = map(val, 560, 960, 0, 180);         // Maps the LDR value to a servo angle (0–180)

  myservo.write(deg);                        // Sets the servo to the mapped angle

  delay(100);                                // Small delay to allow the servo to reach the position

  Serial.println(val);                       // Prints the raw LDR value to the Serial Monitor

}

