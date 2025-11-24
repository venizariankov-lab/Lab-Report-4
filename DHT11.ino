/* 

 DHT11 : 
 Goal of the program : Displays the temperature and humidity values on the LCD screen. 
 Main theme : Controlling a sensor and displaying results on the LCD.

*/

#include <LiquidCrystal.h>    // Includes LCD library
#include "DHT.h"              // Includes DHT sensor library

// LCD pin configuration (RS, E, D4, D5, D6, D7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// DHT11 sensor configuration
#define DHTPIN 7              // Pin where the DHT11 data pin is connected
#define DHTTYPE DHT11         // Specifies the sensor model (DHT11)


// Variables to store the temperature and humidity values
float hum;
float temp;


// Creates the DHT sensor object for the Arduino
DHT dht(DHTPIN, DHTTYPE);


void setup() {

  lcd.begin(16, 2);           // Establishes connection with the LCD screen (16 columns, 2 rows)

  dht.begin();                // Starts the DHT11 sensor

}


void loop() {

  delay(200);                 // Small delay to allow stable sensor readings

  hum = dht.readHumidity();   // Reads the humidity value and stores it in the variable
  temp = dht.readTemperature(); // Reads the temperature value in Celsius


  lcd.clear();                // Clears the LCD to update the displayed values

  // Prints the temperature on the first row
  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(temp);
  lcd.print(" C");

  // Prints the humidity on the second row
  lcd.setCursor(0, 1);
  lcd.print("Humid = ");
  lcd.print(hum);
  lcd.print(" %");

}

