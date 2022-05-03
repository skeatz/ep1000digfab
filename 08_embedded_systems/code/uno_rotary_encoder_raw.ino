
#include <RotaryEncoder.h>

/*
  Raw Rotary Encoder without module, hence must use input pullups
  C, E are connected to GND
  D   switch
  A,B pulse inputs

  Library: RotaryEncoder
  Author:  Matthias Hertel
  Sample:  SimplePollRotator (https://github.com/mathertel/RotaryEncoder/tree/master/examples/SimplePollRotator)
*/

const int RSW = 6;        // Switch
const int R_A = 5;        // Pulse A
const int R_B = 4;        // Pulse B
int oldreading = HIGH;
int pos = 0;
int count = 0;

RotaryEncoder encoder(R_A, R_B);


void setup() {
  // Setup Rotary Encoder & SW
  pinMode(RSW, INPUT_PULLUP);
  pinMode(R_A, INPUT_PULLUP);
  pinMode(R_B, INPUT_PULLUP);
  // for debugging
  Serial.begin(9600);
  Serial.println("Rotary Encoder Raw");
}

void loop() {
  // check RE Switch
  int reading = digitalRead(RSW);
  if (reading == LOW){
    // someone pressed the switch
    if (oldreading == HIGH){
      count++;
      Serial.print("Pressed: ");
      Serial.println(count);
      oldreading = reading;
    }
  }
  else
  {
    oldreading = HIGH;
  }

  // Check encoder
  encoder.tick();
  int newPos = encoder.getPosition();
  if (pos != newPos){
    Serial.print("  Encoder: ");
    Serial.println(newPos);
    pos = newPos;
  }
}