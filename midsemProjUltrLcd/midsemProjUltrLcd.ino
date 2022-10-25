//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define LEDRED (4)


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
  pinMode(LEDRED, OUTPUT);
 
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Water Level(cm)");
  lcd.setCursor(4, 1);
  lcd.print(ultrasonic.Ranging(CM)); // CM or INC
  lcd.print("cm");
  delay(100);

  if(ultrasonic.Ranging(CM)=< 15){
    digitalWrite(LEDRED, HIGH); 
    delay(1000); 
    digitalWrite(LEDRED,LOW);
  }
}
