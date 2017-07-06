////////////////////////////////////////
// Servo control based on trigger signal
// Author :- Akshat and Chandan
////////////////////////////////////////
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int ch=1; 
boolean triger =false;
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(11,INPUT);
}

 
 
void loop() 
{ 
  if(digitalRead(11) == LOW)
  {
    if(ch==1)
    ch=2;
    else
    ch=1;
    triger =true;
  }
  if(triger)
  {
  switch(ch)
  {
    case 1:
    for(pos = 100; pos>=1; pos-=1)     // goes from 100 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   triger = false;
   break;
   
   case 2:
   for(pos = 0; pos < 100; pos += 1)  // goes from 0 degrees to 100 degrees 
   {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
   } 
   triger = false;
  }
  }
    
} 