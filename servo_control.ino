#include <Servo.h>
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;  
const int echoPin = 4;
const int pingPin = 5;  
 
void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
  Serial.begin(9600);
} 
  
void loop() 
{ 
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delay(2);
  digitalWrite(pingPin, HIGH);
  delay(5);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  if (cm<=8) {
    for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
    {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(5);                       
    } 
  
    for(angle = 180; angle>=0; angle-=1)     // command to move from 180 degrees to 0 degrees 
    {                                
      servo_test.write(angle);              //command to rotate the servo to the specified angle
      delay(5);                       
    } 
}

}

                  
