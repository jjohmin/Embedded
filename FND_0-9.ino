int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int i;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], LOW);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], HIGH);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], HIGH);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], HIGH);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], HIGH);
  digitalWrite(seg[6], HIGH);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], HIGH);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], LOW);
  digitalWrite(seg[5], HIGH);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], HIGH);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], HIGH);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], HIGH);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], HIGH);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], HIGH);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], LOW);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], HIGH);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], HIGH);
  digitalWrite(seg[6], HIGH);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], LOW);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);

  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], HIGH);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
  digitalWrite(seg[7], LOW);
  digitalWrite(seg[8], HIGH);
  delay(1000);
}