int but = 8;

void setup() {
  Serial.begin(9600);
  pinMode(but, INPUT);
}

void loop() {
  int n = digitalRead(but);
  if (but) {
    Serial.println("no click");
    delay(500);
  } else {
    Serial.println("click");
    delay(500);
  }
}