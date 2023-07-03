/*
 * MotorKnob
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 */

#include <Stepper.h>
// 이것을 모터의 단계 수로 변경
#define STEPS 100
Stepper stepper(STEPS, 8, 9, 10, 11);
// 아날로그 입력의 이전 판독값
int previous = 0;
void setup() {
  // 모터 속도를 30RPM으로 설정
  stepper.setSpeed(30);
}
void loop() {
  // 센서 값 얻기
  int val = analogRead(0);
  // 의 변화와 같은 수의 단계를 이동합니다.
  // 센서 판독
  stepper.step(val - previous);
  // 센서의 이전 값을 기억
  previous = val;
}