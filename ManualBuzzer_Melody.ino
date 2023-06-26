const int BUZZER = 10;
const int melody[8] = { 262, 294, 330, 349, 393, 440, 494, 523 };  // 도레미파솔라시도

void setup() {
  for (int i = 0; i <= 7; i++) {
    tone(BUZZER, melody[i]);  // 연주
    delay(500);
  }
  noTone(BUZZER);  // 연주 멈춤
}

void loop() {
}