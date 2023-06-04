int but = 1;
int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
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
int i, j, m, a;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
  }
  pinMode(but, INPUT);
}

void loop() {
  int n = digitalRead(but);
  if (n) {
    if (j == 10)
      j = 0;
    for (i = 0; i < 8; i++)
      digitalWrite(seg[i], !arr[j][i]);
    if (millis() - m == 1000) {
      m = millis();
      j++;
    }
    a = j - 1;
  } else {
    if (millis() - m == 1000)
      m = millis();
    for (i = 0; i < 8; i++)
      digitalWrite(seg[i], !arr[j][i]);
  }
}