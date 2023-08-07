void setup() {
  pinMode(7, OUTPUT);  // pinMode도 for문으로 축약 가능
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  for (int i = 7; i <= 12; i++) {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
    delay(1000);
  }
}