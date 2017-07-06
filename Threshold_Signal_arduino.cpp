////////////////////////////////////////
// Code to threshold signal and output signals
// Mode-1 Output Signals
// Mode-2 Output trigger
// Author :- Akshat and Chandan
////////////////////////////////////////
int sensorPin0 = A0,sensorPin1 = A1,sensorPin2 = A2;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue0 = 0,sensorValue1 = 0,sensorValue2 = 0; // variable to store the value coming from the sensor
int ch = 1;
unsigned long current_time;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  pinMode(11,OUTPUT);
  pinMode(8,INPUT_PULLUP);
 Serial.begin(9600); 
 current_time=millis();
}

void loop() {
  // read the value from the sensor: 
  //Serial.println(digitalRead(8));
  if(digitalRead(8)== LOW)
  {
    ch = 2;
   // current_time=millis();
  }
   else
    ch = 1;
  
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);  
  
  switch(ch)
  {
    case 1:
    if(sensorValue1 <= sensorValue2)
  {
   digitalWrite(ledPin,HIGH); 
  }
  else
  digitalWrite(ledPin,LOW);
  
   Serial.print(sensorValue0);
   Serial.print(",");
   Serial.print(sensorValue1);
   Serial.print(",");
   Serial.println(sensorValue2);
   delay(10);   
   current_time=millis();
   break;
   
   case 2:
   if(sensorValue1 <= sensorValue2)
  {
    //Serial.println("adas");
   if((unsigned long)(millis() - current_time) > 600)
    {
      Serial.println('a');
      digitalWrite(ledPin,HIGH);
      digitalWrite(11,HIGH);
      current_time = millis();
    }
  }
  else
  {
  digitalWrite(ledPin,LOW);
  digitalWrite(11,LOW);
  }
  }
  
}
