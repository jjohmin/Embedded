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
int i, cnt, m;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
  }
  pinMode(but, INPUT);
}

void loop() {
  int n = digitalRead(but);
  if (!n) {
    if (!m) {
      m = 1;
      cnt++;
    }
    delay(50);
  } else
    m = 0;
  if (cnt == 10)
    cnt = 0;
  for (i = 0; i < 8; i++) {
    digitalWrite(seg[i], !arr[cnt][i]);
  }
}