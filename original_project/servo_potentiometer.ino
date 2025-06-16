#include <Servo.h>

Servo myServo;
int potPin = A0;
int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  
  myServo.write(servoAngle);
  
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(servoAngle);
  
  delay(15);
}