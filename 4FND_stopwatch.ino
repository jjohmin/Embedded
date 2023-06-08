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
unsigned long i, j, n, k, m, t;
int num, mo, cnt;
int th, hu, te, on;
int but = 1;
void setup() {
  pinMode(but, INPUT);
  for (i = 0; i < 8; i++)
    pinMode(seg[i], OUTPUT);
  for (i = 0; i < 4; i++)
    pinMode(com[i], OUTPUT);
}

void loop() {
  Number(num);
  if (num >= 6060)
    num = 0;
}

void Number(int n) {
  int bu = digitalRead(but);
  th = 0, hu = 0, te = 0, on = 0;
  if (n >= 1000) {
    th = n / 1000;
    n -= th * 1000;
  }
  if (n >= 60) {
    hu = n / 60;
    n -= hu * 60;
  }
  if (n >= 10) {
    te = n / 10;
    n -= te * 10;
  }
  if (n >= 0) {
    on = n;
    n = 0;
  }
  int nu[4] = { th, hu, te, on };
  if (!mo) {
    if (millis() - t >= 1000) {
      t = millis();
      num++;
    }
  }
  if (!bu) {
    if (!mo) {
      if (!cnt) {
        cnt++;
        mo = 1;
      }
    } else {
      if (!cnt) {
        cnt++;
        mo = 0;
      }
    }
  } else
    cnt = 0;
  if (millis() - m >= 2) {
    m = millis();
    for (i = 0; i < 4; i++) {
      for (k = 0; k < 4; k++)
        digitalWrite(com[k], LOW);
      digitalWrite(com[i], HIGH);
      if (i != 1) {
        for (j = 0; j < 8; j++) {
          digitalWrite(seg[j], !arr[nu[i]][j]);
          digitalWrite(seg[7], HIGH);
        }
      } else {
        for (j = 0; j < 8; j++) {
          digitalWrite(seg[j], !arr[nu[i]][j]);
        }
      }
      delay(3);
    }
  }