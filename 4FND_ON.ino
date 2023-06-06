int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int com[4] = { 10, 11, 12, 13 };
int i, j;

void setup() {
  for (i = 0; i < 8; i++)
    pinMode(seg[i], OUTPUT);
  for (i = 0; i < 4; i++)
    pinMode(com[i], OUTPUT);
}

void loop() {
  for (i = 0; i < 4; i++)
    digitalWrite(com[i], HIGH);
  for (i = 0; i < 8; i++)
    digitalWrite(seg[i], LOW);
}