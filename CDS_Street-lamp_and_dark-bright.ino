int jodo = A0;
int led = 13;
int led2 = 12;
int time, a, b;

void setup() {
  pinMode(jodo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(jodo);
  Serial.println(light);
  analogWrite(led, light / 3);
  a += 1;
  if (a > 255)
    a = 255;
  for (int i = 0; i < 255; i++) {
    if (a < i)
      digitalWrite(led, LOW);
    delayMicroseconds(20);
  }
  analogWrite(led2, -(light - 650));
  b += 1;
  if (b > 255)
    b = 255;
  for (int j = 0; j < 255; j++) {
    if (b < j)
      digitalWrite(led2, LOW);
    delayMicroseconds(20);
  }
}