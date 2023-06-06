int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int com[4] = { 10, 11, 12, 13 };
int arr[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 1 },
  { 0, 1, 1, 0, 0, 0, 0, 1 },
  { 1, 1, 0, 1, 1, 0, 1, 1 },
  { 1, 1, 1, 1, 0, 0, 1, 1 },
  { 0, 1, 1, 0, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1 }
};
int i, j, n;

void setup() {
  for (i = 0; i < 8; i++)
    pinMode(seg[i], OUTPUT);
  for (i = 0; i < 4; i++)
    pinMode(com[i], OUTPUT);
}

void loop() {
  for (i = 0; i < 4; i++) {
    for (n = 0; n < 4; n++)
      digitalWrite(com[n], LOW);
    digitalWrite(com[i], HIGH);
    for (j = 0; j < 8; j++)
      digitalWrite(seg[j], !arr[i + 1][j]);
    delay(100);
  }
}