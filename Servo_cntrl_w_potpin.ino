#include <Servo.h>

Servo myServo;
int potPin = A0; 
int potVal;
int angle = 0; 
int buttonPin = 8;  

void setup() { 
  myServo.attach(9);  
  pinMode(buttonPin, INPUT);  
  Serial.begin(9600); 
} 

void loop() { 
  potVal = analogRead(potPin); 
  Serial.print("Potentiometer Value: ");
  Serial.print(potVal);  
  
  angle = map(potVal, 0, 1023, 0, 179); 
  myServo.write(angle);  
  delay(15); 
  
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {  
    Serial.println("Button pressed");
    myServo.write(90); 
  }
}
