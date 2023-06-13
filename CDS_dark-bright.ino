int jodo = A0;
int led = 13;

void setup() {
  pinMode(jodo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int light = analogRead(jodo);
  analogWrite(led, -(light - 700));
}