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
}

void loop() {
  for (i = 0; i < 8; i++)
    digitalWrite(seg[i], !arr[m][i]);
  a += 1;
  if (a > 255) {
    a = 0;
    m = 0;
  }
  if (a % 25 == 0)
    m++;
  if (m == 10)
    m = 0;
  for (j = 0; j <= 255; j++) {
    if (a < j) {
      for (i = 0; i < 8; i++)
        digitalWrite(seg[i], HIGH);
    }
    delayMicroseconds(20);
  }
}