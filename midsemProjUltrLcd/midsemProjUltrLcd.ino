//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include  <Ultrasonic.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Ultrasonic ultrasonic(14,27); // (Trig PIN,Echo PIN)

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Testing...");
 
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(ultrasonic.Ranging(CM)); // CM or INC
  lcd.print("cm");
  delay(100);
}
