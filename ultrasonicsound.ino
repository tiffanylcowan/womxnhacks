#define echo 7
#define trig 8
#define RLED 10
#define GLED 11


long duration;
long distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  digitalWrite(GLED, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH); 

  distance = duration/58.2; //conversion to cm

  Serial.println(distance);
  delay(25);

  if(distance < 90){
  digitalWrite(GLED, LOW);
  digitalWrite(RLED, HIGH);
  }
  else{
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  }
  
}
