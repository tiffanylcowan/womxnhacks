int bLED = 13; 
int yLED = 8; 
int bbuttonpin = 3; 
int ybuttonpin = 4; 
bool bbuttonState, ybuttonState, lastyButtonState, lastbButtonState; 

unsigned long milliseconds = 0;

bool bState = false; 
bool yState = false; 

void setup() {

  pinMode(bLED, OUTPUT); 
  pinMode(yLED, OUTPUT);
  pinMode(bbuttonpin, INPUT); 
  pinMode(ybuttonpin, INPUT);
  lastbButtonState = bbuttonState = HIGH;
  lastyButtonState = ybuttonState = LOW;
}

void loop() {

  bbuttonState = digitalRead(bbuttonpin); 
  ybuttonState = digitalRead(ybuttonpin);

  milliseconds = millis();
  
  if (bbuttonState == LOW && lastbButtonState == HIGH) {
    bState = !bState;
  }

  if (bState == true && (int) floor(milliseconds / 500) % 2) {
    digitalWrite(bLED, HIGH);
  }
  else {
    digitalWrite(bLED, LOW);
  }

  if (ybuttonState == LOW && lastyButtonState == HIGH) {
    yState = !yState;
  }

  if (yState == true && (int) floor(milliseconds / 500) % 2) {
    digitalWrite(yLED, HIGH);
  }
  else {
    digitalWrite(yLED, LOW);
  }

  lastbButtonState = bbuttonState;
  lastyButtonState = ybuttonState;
}
