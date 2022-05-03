/*
    Rotary Encoder displays Volume (0-50)
    Display is on LCD, shows changes of the 
    rotary encoder as well
*/

// Uses LCD with I2C Library
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// Uses RotaryEncoder Lirbary
#include <RotaryEncoder.h>

// LiquidCrystal
const int LCDADDR = 0x27;
int counter = 0;
LiquidCrystal_PCF8574 lcd(LCDADDR);

// Rotary Encoder
const int CLK=4;
const int DT=5;
RotaryEncoder encoder(CLK, DT);
int pos;
int volume;
const int MINVALUE = 0;
const int MAXVALUE = 50;

void init_lcd(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.noBlink();
  lcd.noCursor();  
}


void setup() {
    // for debugging
    Serial.begin(9600);
    Serial.println("Ready");
    // for Rotary Encoder
    pinMode(DT, INPUT);
    pinMode(CLK, INPUT);
    pos = 0;
    volume = 0;
    // initialise LCD
    init_lcd();
    lcd.setCursor(0,0);
    lcd.print("Rotary: ");
    lcd.setCursor(8,0);
    lcd.print(counter);
    lcd.setCursor(0,1);
    lcd.print("Volume: ");
    lcd.setCursor(8,1);
    lcd.print(volume);
}

void loop() {
   
    encoder.tick();

    int newPos = encoder.getPosition();
    if (pos != newPos){
        lcd.setCursor(8,0);
        lcd.print("   ");
        lcd.setCursor(8,0);
        lcd.print(newPos);

        // determine whether +ve or -ve
        int inc = newPos - pos;
        volume = volume + inc;
        // check limits
        if (volume < MINVALUE)
            volume = MINVALUE;
        if (volume > MAXVALUE)
            volume = MAXVALUE;
        lcd.setCursor(8,1);
        lcd.print("   ");
        lcd.setCursor(8,1);
        lcd.print(volume);
        
        pos = newPos;
    }
}
