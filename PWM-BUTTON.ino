int a = 0;
int toggle = 1;
int i;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int n = digitalRead(8);
  int m = digitalRead(9);

  if (n == 0) {
    digitalWrite(13, HIGH);
    a += 1;
    if (a > 255)
      a = 0;
    for (int i = 0; i <= 255; i++) {
      if (i > a)
        digitalWrite(13, LOW);
      delayMicroseconds(20);
    }
  }

  if (m == 0) {
    digitalWrite(13, HIGH);
    a -= 1;
    if (a == 0)
      a = 255;
    for (int i = 0; i <= 255; i++) {
      if (i > a)
        digitalWrite(13, LOW);
      delayMicroseconds(20);
    }
  }
}