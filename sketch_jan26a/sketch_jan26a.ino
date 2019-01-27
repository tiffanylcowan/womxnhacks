#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
////THESE NUMBERS WILL NEED TO CHANGE 
////ACCORDING TO SPACES
#define LEDPIN 13
#define SENSORPIN 8
int counter = 0;
double circum = 2*3.14*14;
double bikeSpeed = 0.0;
long previousMillis = 0;
//////////////////

int sensorState = 0, lastState = 0;

void setup(){
  //////////
  pinMode(LEDPIN, OUTPUT);
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH);
  Serial.begin(9600);
  //////////
  lcd.begin(16, 2);
  lcd.print("WOMXN/HACKS 2019");
  
}

void loop(){
  ///////////
  unsigned long currentMillis = millis();
  sensorState = digitalRead(SENSORPIN);
  if(sensorState == LOW){
    digitalWrite(LEDPIN, HIGH);
  }
  else{
    digitalWrite(LEDPIN, LOW);
  }
  if(sensorState && !lastState){
    Serial.println("Unbroken");
  }
  if(!sensorState && lastState){
    //put a counter in here
    //increment variable when light's broken
    //once coutner reaches 32, restart timer
    counter++;
    if(counter == 32){
      //display speed using time and circum
      bikeSpeed = circum/((currentMillis-previousMillis));
      bikeSpeed = (bikeSpeed*0.05681)*1000;
      lcd.setCursor(0, 1);
      //lcd.print(currentMillis);
      //delay(1000);
      //lcd.print(0);
      lcd.print(bikeSpeed,2);
      //lcd.print(currentMillis-previousMillis);
      previousMillis = currentMillis;
      counter = 0;
   }
    Serial.println("Broken");
  }
  lastState = sensorState; 
  ////////////
  
}
