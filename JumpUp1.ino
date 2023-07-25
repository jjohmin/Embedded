int t = 500;

void setup() {
  for (int i = 10; i <= 13; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  int j = 13;
  delay(t);
  for (int i = 10; i <= 13; i++)
    digitalWrite(i, 1);
  delay(t);
  for (int i = 10; i < 13; i++)
    digitalWrite(i, 0);
  delay(t);
  for (int i = 0; i < 4; i++) {
    digitalWrite(j, 0);
    digitalWrite(j - 1, 1);
    delay(t);
    j--;
  }
}