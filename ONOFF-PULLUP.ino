void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int n = digitalRead(10);
  if (n)
    digitalWrtie(13, LOW);
  else
    digitalWrite(13, HIGH);
}