#include <Servo.h>

Servo myServo;

int btn1Pin = 3;
int btn2Pin = 2;
int servoPin = 9;
int btn1State;
int btn2State;
int pos = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
 btn1State = digitalRead(btn1Pin);
 btn2State = digitalRead(btn2Pin);
  if (btn1State == HIGH) {
    Serial.println("Button 1 is on");
    Serial.println(pos);
    myServo.write(pos);
    pos = 50; 
    myServo.write(pos);
  }
  if (btn2State == HIGH) {
   Serial.println("Button 2 is on");
   Serial.println(pos);
   myServo.write(pos);
   pos = 130; 
   myServo.write(pos);
  }
  if (btn1State == LOW && btn2State == LOW) {
   Serial.println("Both buttond are off");
   Serial.println(pos);
   myServo.write(pos);
   pos = 90; 
   myServo.write(pos);
  }
}
