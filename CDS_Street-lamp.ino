int jodo = A0;
int led = 13;
int time;

void setup() {
  pinMode(jodo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int light = analogRead(jodo);
  if (light < 300)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}