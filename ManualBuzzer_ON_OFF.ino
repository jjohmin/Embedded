const int BUZZER = 10;

void setup() {
  for (int cnt = 0; cnt <= 2; cnt++) {  // 2번반복
    tone(BUZZER, 262);                  // 262주파수 음 연주
    delay(1000);
    tone(BUZZER, 294);  // 294주파수 음 연주
    delay(1000);
  }
  noTone(BUZZER);
}

void loop() {
}