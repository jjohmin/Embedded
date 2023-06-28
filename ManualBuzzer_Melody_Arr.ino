int piezo = 10;
int pins[] = { 2, 3, 4, 5 };
int tones[] = { 262, 294, 330, 349 };

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(pins[i]) == HIGH) {
      tone(piezo, tones[i], 20);
    }
  }
}