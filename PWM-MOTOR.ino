int inpin1 = 3;
int inpin2 = 4;
int enpin = 5;
int a = 0, i;
int total = 1;

void setup() {
  pinMode(inpin1, OUTPUT);
  pinMode(inpin2, OUTPUT);
  // 정방향으로 고정
  digitalWrite(inpin1, HIGH);
  digitalWrite(inpin2, LOW);
}

void loop() {
  // PWM
  if (total)
    a += 1;
  else
    a -= 1;
  if (a > 255)
    total = 0;
  else if (a == 0)
    total = 1;
  digitalWrite(enpin, HIGH);
  for (i = 0; i <= 255; i++) {
    if (a < i)
      digitalWrite(enpin, LOW);
    delayMicroseconds(20);
  }
}