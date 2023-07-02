#include <Stepper.h>
const int STEPS = 2048;
Stepper stepper(STEPS, 11, 9, 10, 8);

void setup() {
  stepper.setSpeed(14);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.parseInt();      // 회전각 int형으로 읽기
    val = map(val, 0, 360, 0, 2048);  // 회전각 스템수
    stepper.step(val);
    Serial.println(val);
    delay(10);
  }
}