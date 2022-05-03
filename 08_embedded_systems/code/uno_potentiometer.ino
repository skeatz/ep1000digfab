/*
 * Potentiomenter using analogRead
 */

// Uses LCD with I2C Library
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// LiquidCrystal
const int LCDADDR = 0x27;
int counter = 0;
LiquidCrystal_PCF8574 lcd(LCDADDR);

void lcd_init(String s){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();
  lcd.noBlink();
  lcd.noCursor();
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print(s);
}

// Potentiometer
const int POT = A0;
int oldreading = 0;

void setup() {
  // for debugging
  Serial.begin(9600);
  Serial.println("Potentiometer");
  //        0123456789012345
  lcd_init("Pot reading:");
  lcd.setCursor(0,1);
  //         0123456789012345
  lcd.print("Mapped: ");
  oldreading = 0;
}

void loop() {
  int reading = analogRead(POT);  
  if (oldreading != reading){
    // reading has changed
    lcd.setCursor(12,0);
    lcd.print("    ");
    lcd.setCursor(12,0);
    lcd.print(reading);
    // Map the input to 0..255
    int value = map(reading, 0, 1023, 0,255);
    lcd.setCursor(7,1);
    lcd.print("   ");
    lcd.setCursor(7,1);
    lcd.print(value);
    //
    oldreading = reading;
  }
}
