int inpin1 = 3;
int inpin2 = 4;
int enpin = 5;

void setup() {
  pinMode(inpin1, OUTPUT);
  pinMode(inpin2, OUTPUT);
  analogWrite(enpin, 255);  // 최고속도
}

void loop() {
  // 정방향
  digitalWrite(inpin1, HIGH);
  digitalWrite(inpin2, LOW);
  delay(1000);
  // 멈춤
  digitalWrite(inpin1, HIGH);
  digitalWrite(inpin2, HIGH);
  delay(1000);
}