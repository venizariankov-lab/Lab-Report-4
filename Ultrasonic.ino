/* 

 Ultrasonic Sensor :  
 Goal of the program : Measures distance using an ultrasonic sensor and displays the value on the LCD. 
 Main theme : Reading sensor value and displaying it on a LCD screen.

*/

#include <LiquidCrystal.h>     // Includes the LCD library

// LCD pin configuration (RS, E, D4, D5, D6, D7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Ultrasonic sensor pins
#define trigPin 7
#define echoPin 13

float duration, distance;      // Variables to store pulse duration and calculated distance


void setup() {

  Serial.begin(9600);         // Starts communication with Serial Monitor
  lcd.begin(16, 2);           // Initializes the LCD screen (16 columns, 2 rows)

  pinMode(trigPin, OUTPUT);   // Sets the trigger pin as output
  pinMode(echoPin, INPUT);    // Sets the echo pin as input

}


void loop() {

  // Start distance measurement with an ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);       // Short delay to stabilize the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);      // Sends a 10µs pulse
  digitalWrite(trigPin, LOW);

  // Reads the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculates distance in cm
  distance = (duration / 2) * 0.0343;

  lcd.setCursor(0, 0);        // Sets cursor to the first row

  lcd.print("Distance = ");   

  // Checks if the measured distance is valid
  if (distance >= 400 || distance <= 2) {   
    lcd.println("Out of range");             // Prints out of range if distance is invalid
  }
  else {
    lcd.print(distance);                      // Prints the distance in cm
    lcd.println(" cm");
    delay(500);                               // Delay to make reading stable
  }

  delay(500);                                 // Delay between measurements

}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
