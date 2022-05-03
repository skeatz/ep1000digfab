/*
 * I2C LCD Operations
 * Simple operations that you can test your LCD
 */

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// LCD parameters
const int LCDADDR = 0x27;           // default address of LCD
LiquidCrystal_PCF8574 lcd(LCDADDR);  // instantiate a LCD



void setup() {
  // for debugging
  Serial.begin(9600);
  Serial.println("Ready - I2C LCD Test");
  // initialise LCD
  lcd.begin(16,2);                  // 16cols, 2 rows
  lcd.setBacklight(1);
  lcd.home();
  lcd.clear();
  lcd.noBlink();
  lcd.noCursor();
  lcd.setCursor(0,0);
  lcd.print("Ready");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("Counting: ");
  for (int i=0; i<1000; ++i){
    lcd.setCursor(10,1);
    lcd.print("    ");      // clear contents
    lcd.setCursor(10,1);
    lcd.print(i);
    delay(500);
  }

}
