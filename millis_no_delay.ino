int m;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - m >= 500) {
    m = millis();
    Serial.println(m);
  }
}