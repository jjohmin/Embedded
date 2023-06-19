#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo;
SoftwareSerial bluetooth(8, 9);
int ser = 7, ch;

void setup() {
  pinMode(ser, OUTPUT);
  servo.attach(ser);
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    ch = bluetooth.read();
    if (ch == 48)
      servo.write(0);
    else if (ch == 49)
      servo.write(180);
  }
}