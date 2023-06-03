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
int i, j, m;

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
    j++;
    m = j - 1;
    delay(1000);
  } else {
    for (i = 0; i < 8; i++)
      digitalWrite(seg[i], !arr[m][i]);
  }
}