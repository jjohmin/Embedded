int x, y, z;  // 조이스틱
int inpin1 = 3;
int inpin2 = 4;
int enpin = 5;
int sok;
int time;

void setup() {
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(inpin1, OUTPUT);
  pinMode(inpin2, OUTPUT);
  attachInterrupt(0, func, FALLING);
}

void func() {
  digitalWrite(inpin1, HIGH);
  digitalWrite(inpin2, HIGH);
}

void loop() {
  if (sok > 255)
    sok = 255;
  if (sok < 0)
    sok = 0;
  analogWrite(enpin, sok);
  x = analogRead(A5);
  y = analogRead(A4);
  if (x < 300) {
    digitalWrite(inpin1, LOW);
    digitalWrite(inpin2, HIGH);
  } else if (x > 600) {
    digitalWrite(inpin1, HIGH);
    digitalWrite(inpin2, LOW);
  }

  if (y > 600) {
    sok--;
  } else if (y < 300) {
    sok++;
  }
}