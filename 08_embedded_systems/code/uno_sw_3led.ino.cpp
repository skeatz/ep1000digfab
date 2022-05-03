// Switch & 3 LED sequencer

const int SW = 2;
const int RED = 8;
const int YEL = 9;
const int GRE = 10;

int state = 0;                  // original state
int swState = 0;                // state of switch

void setup()
{
    // put your setup code here, to run once:
    pinMode(SW, INPUT_PULLUP);
    pinMode(RED, OUTPUT);
    pinMode(YEL, OUTPUT);
    pinMode(GRE, OUTPUT);
    // initialise Serial monitor for debugging
    Serial.begin(9600);
    Serial.println("SWLEDSequencer start");
}

void loop()
{
    // check for keypress using debouncing
    int reading = digitalRead(SW);
    if (reading == LOW && swState == 0) {
        delay(50);      // debounce
        swState = 1;
        state = (state + 1) % 5;      // only 5 state
        displayState(state);
    }
    else {
        if (swState == 1 && reading == HIGH){
            swState = 0;
        }
    }
}


void displayState(int s){
    switch(s){
        case 0: digitalWrite(RED, LOW);
                digitalWrite(YEL, LOW);
                digitalWrite(GRE, LOW);
                break;
        case 1: digitalWrite(RED, HIGH);
                digitalWrite(YEL, LOW);
                digitalWrite(GRE, LOW);
                break;
        case 2: digitalWrite(RED, LOW);
                digitalWrite(YEL, HIGH);
                digitalWrite(GRE, LOW);
                break;
        case 3: digitalWrite(RED, LOW);
                digitalWrite(YEL, LOW);
                digitalWrite(GRE, HIGH);
                break;
        case 4: digitalWrite(RED, HIGH);
                digitalWrite(YEL, HIGH);
                digitalWrite(GRE, HIGH);
                break;
    }
}
