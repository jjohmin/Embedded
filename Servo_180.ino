#include <Servo.h>
Servo servo;
int ser = 7;

void setup() {
  pinMode(ser, OUTPUT);
  servo.attach(ser);
}

void loop() {
  servo.write(180);
}