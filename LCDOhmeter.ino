/* 

 LCD : Ohmmeter 
 Goal of the program : Measures the resistance of an unknown resistor and displays the value in ohms on the LCD screen. 
 Main Theme : Analog Input displayed on screen.

*/

#include <LiquidCrystal.h>      // Includes the LCD library

// LCD pin configuration (RS, E, D4, D5, D6, D7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Selects the analog pin used to read the voltage divider output  
int sensorPin = A0;
int sensorValue = 0;            // Stores the raw value from the analog pin


// Custom Ohm symbol to display on the LCD  
byte ohmSymbol[8] = {
  B01110,  
  B10001,  
  B10001,  
  B10001,  
  B01010,  
  B01010,  
  B11011,  
  B00000   
};


void setup() {

  lcd.begin(16, 2);             // Establishes communication with the LCD (16 columns, 2 rows)

  lcd.createChar(0, ohmSymbol); // Creates the custom ohm symbol at memory position 0

  Serial.begin(9600);           // Opens communication with the Serial Monitor
  pinMode(sensorPin, INPUT);    // Sets the analog pin as an input

}


void loop() {

  sensorValue = analogRead(sensorPin);      // Reads the analog value (0–1023)

  // Calculates the voltage using the 5V reference
  float voltage = sensorValue * (5.0 / 1023.0);

  // Calculates the current through the known resistor (9.96kΩ measured value)
  float I = (5.0 - voltage) / 9960.0;

  // Calculates the resistance of the unknown resistor
  float R = voltage / I;


  Serial.print("R = ");         // Serial output for testing
  Serial.print(R);
  Serial.println(" Ω");


  lcd.clear();                  // Clears previous display to refresh the value
  lcd.setCursor(0, 0);          // Moves cursor to the first row, first column
  lcd.print("R = ");
  lcd.print(R);                 // Prints the calculated resistance
  lcd.write(byte(0));           // Prints the custom ohm symbol


  delay(100);                   // Makes the LCD display smoother
  lcd.blink();                  // Visual blinking effect on the LCD cursor
  delay(100);

}
