/* 

 Stepper Motor : Joystick 
 Goal of the program : Controls the direction and speed of a stepper motor using a joystick. 
 Main Theme : Using analog inputs to control a motor.

*/

#include <Stepper.h>             // Includes the Stepper motor library


// Motor constants
const float STEPS_PER_REV = 32;  // Number of steps per internal revolution of the stepper
const float GEAR_RED = 64;       // Gear reduction ratio
const int STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;  // Total steps for one output shaft revolution


// Stepper motor object using the pins connected to your wiring
Stepper steppermotor(STEPS_PER_OUT_REV, 8, 9, 10, 11);


// Joystick pins
const int joyX = A1;             // X-axis controls direction (left-right)
const int joyY = A0;             // Y-axis controls speed (up-down)


// Dead zone for joystick to prevent unwanted movement
const int deadZone = 60;


// Usable speed range for 28BYJ-48 stepper motor
const int minSpeed = 5;          // Slowest RPM
const int maxSpeed = 20;         // Fastest RPM (safe maximum)


void setup() {
  // No additional setup required
}


void loop() {

  // Read the analog values from the joystick
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  int direction = 0;              // Stores the rotation direction of the motor

  // Determine motor direction based on joystick X-axis
  if (xVal < 512 - deadZone) {
    direction = -1;               // Rotate counter-clockwise
  }
  else if (xVal > 512 + deadZone) {
    direction = 1;                // Rotate clockwise
  }
  else {
    direction = 0;                // Joystick centered → motor stops
  }

  // Map the Y-axis value to a usable speed for the stepper motor
  int speed = map(yVal, 0, 1023, minSpeed, maxSpeed);

  // Apply motor control if there is a valid direction
  if (direction != 0) {
    steppermotor.setSpeed(speed);       
    steppermotor.step(direction * 2);  // Small tweak: 2 steps per loop for smoother, slightly faster motion
  }

}

