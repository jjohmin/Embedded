#include <Servo.h>
Servo servo;
int ser = 7;

void setup() {
  pinMode(ser, OUTPUT);
  servo.attach(ser);
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
}