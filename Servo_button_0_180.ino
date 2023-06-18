#include <Servo.h>
Servo servo;
int ser = 7;
int but = 6;
int cnt, mode;

void setup() {
  pinMode(ser, OUTPUT);
  pinMode(but, INPUT);
  servo.attach(ser);
}

void loop() {
  int n = digitalWrite(but);
  if (!n) {
    if (!cnt) {
      if (!mode) {
        servo.write(0);
        mode = !mode;
      } else {
        servo.write(180);
        mode = !mode;
      }
      cnt++;
    }
  } else
    cnt = 0;
}