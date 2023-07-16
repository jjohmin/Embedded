const unsigned int led[6] = { 3, 5, 6, 9, 10, 11 };
const int buttonPin = 2;

void setup() {
  for (int x = 0; x <= 5; x++) {
    pinMode(led[x], OUTPUT);  // 모든 배열 OUTPUT
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);  // 버튼 입력값
  if (buttonInput == LOW) {                  // 버튼 누를 때
    for (int x = 0; x <= 5; x++) {
      for (int x = 0; x <= 5; x++) {
        digitalWrite(led[x], LOW);  // 배열 순서대로 끈다
      }
      digitalWrite(led[x], HIGH);  // 한 개를 킨다
      buttonInput = digitalRead(buttonPin);
      if (buttonInput == HIGH) break;  // 버튼 안 누를 때
      delay(50);                       // 버튼 바뀌는 속도
    }
  }
}