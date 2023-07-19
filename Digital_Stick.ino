const int led[6] = { 3, 5, 6, 9, 10, 11 };
const int analogPin = A0;

void setup() {
  for (int x = 0; x <= 5; x++) {
    pinMode(led[x], OUTPUT);
  }
}

void loop() {
  int sensorInput = analogRead(analogPin);

  if (sensorInput > 1024 / 7 * (1 + 0))  // 146
    digitalWrite(led[0], HIGH);          // 가변저항이 146을 넘으면 첫번째 LED가 켜짐
  else digitalWrite(led[0], LOW);

  if (sensorInput > 1024 / 7 * (1 + 1))  // 292
    digitalWrite(led[1], HIGH);          // 가변저항이 292을 넘으면 두번째 LED도 켜짐
  else digitalWrite(led[1], LOW);

  if (sensorInput > 1024 / 7 * (1 + 2))  // 438
    digitalWrite(led[2], HIGH);          // 가변저항이 438을 넘으면 세번째 LED도 켜짐
  else digitalWrite(led[2], LOW);

  if (sensorInput > 1024 / 7 * (1 + 3))  // 584
    digitalWrite(led[3], HIGH);          // 가변저항이 584을 넘으면 네번째 LED도 켜짐
  else digitalWrite(led[3], LOW);

  if (sensorInput > 1024 / 7 * (1 + 4))  // 730
    digitalWrite(led[4], HIGH);          // 가변저항이 730을 넘으면 다섯번째 LED도 켜짐
  else digitalWrite(led[4], LOW);

  if (sensorInput > 1024 / 7 * (1 + 5))  // 876
    digitalWrite(led[5], HIGH);          // 가변저항이 876을 넘으면 여섯번째 LED도 켜짐
  else digitalWrite(led[5], LOW);
}