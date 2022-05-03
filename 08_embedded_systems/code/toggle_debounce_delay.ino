// toggle_nodebounce.ino
// toggle LED with switch without debouncing

const int SW = 4;
const int LED = 10;
int state = 0;            // we start at state 0
int ledState = HIGH;      // original state of the LED

void setup() {
  pinMode(SW, INPUT_PULLUP);      // using internal pullup
  pinMode(LED,OUTPUT);
  digitalWrite(LED, ledState);    // switch ON the LED
}

void loop() {
  int reading = digitalRead(SW);    // read the switch

  if (reading == LOW && state == 0){      // SW = LOW if pressed
      delay(100);                     // wait a bit for bouncing to end
      ledState = ! ledState;          // toggle the LED
      digitalWrite(LED, ledState);
      state = 1;                      // change to state 1
    }
  }
  else {
    if (state == 1 && reading == HIGH){
      // switch back to normal, we are ready to check SW again
      state = 0;
    }
  }

}