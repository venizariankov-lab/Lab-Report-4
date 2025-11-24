/* 

 Servo : Joystick 
 Goal of the program : Controls a servo using a joystick. 
 Main Theme : Using Analog Input to control a servo.

*/

#include <Servo.h>           // Includes the Servo library

Servo myservo;               // Creates a Servo object to control the servo


int joyX = A0;               // Analog pin connected to the joystick X-axis
int xVal;                     // Variable to store the analog reading from the joystick
int deg;                      // Variable to store the mapped angle for the servo


void setup() {

  myservo.attach(9);          // Attaches the servo on pin 9 to the Servo object
  pinMode(joyX, INPUT);       // Sets the joystick pin as an input

}


void loop() {

  xVal = analogRead(joyX);                  // Reads the joystick value (0–1023)

  deg = map(xVal, 0, 1023, 0, 180);        // Maps the joystick value to a servo angle (0–180)

  myservo.write(deg);                       // Sets the servo to the mapped angle

  delay(15);                                // Small delay to allow the servo to reach the position

}
