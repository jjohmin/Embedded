int piezo = 10;
int tones[] = { 262, 294, 330, 349, 392, 440, 494, 523 };

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    tone(piezo, tones[0], 20);
  }
  if (digitalRead(3) == HIGH) {
    tone(piezo, tones[1], 20);
  }
  if (digitalRead(4) == HIGH) {
    tone(piezo, tones[2], 20);
  }
  if (digitalRead(5) == HIGH) {
    tone(piezo, tones[3], 20);
  }
}