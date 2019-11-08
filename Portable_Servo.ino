//Portable Button Controled Sero
//Josie Muss and Ian Novotne
//Controls a continuous servo with two different buttons.


#include <Servo.h>

Servo myServo;
//Variables
int btn1Pin = 3;
int btn2Pin = 2;
int servoPin = 9;
int btn1State;
int btn2State;
int pos = 90; // The starting position of the Servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 myServo.attach(servoPin); //Necessary to use the servo
}

void loop() {
  // put your main code here, to run repeatedly:
 btn1State = digitalRead(btn1Pin); //Sets the button states equal to the buton pins
 btn2State = digitalRead(btn2Pin);
  if (btn1State == HIGH) { //If the button is on
    Serial.println("Button 1 is on");
    Serial.println(pos);
    myServo.write(pos = 50); //Sets the position to 50, so that the servo rotates clockwise
  }
  if (btn2State == HIGH) { //If the button is on
   Serial.println("Button 2 is on");
   Serial.println(pos);
   myServo.write(pos = 130); //Sets the position to 130, so that the servo rotates counter-clockwise
  }
  if (btn1State == LOW && btn2State == LOW) { //If BOTH buttons are off
   Serial.println("Both buttond are off");
   Serial.println(pos);
   myServo.write(pos = 90); //Sets the position to 90, so that the servo doesn't rotate
  }
}
