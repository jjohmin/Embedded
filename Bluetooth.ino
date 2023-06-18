#include <SoftwareSerial.h>
SoftwareSerial bluetooth(8, 9);

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    Serial.println(bluetooth.read());
  }
}