int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;//sensor is attached to the A5 analog pin of arduino
int sensorThres = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(smokeA0,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A5:");
  Serial.println(analogSensor);
  if(analogSensor > sensorThres)
  {
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    tone(buzzer,1000,200);
  }
  else
  {
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
  }
  delay(100);
}
