int cnt, m;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("Arduino");
  if (millis() - m >= 500) {
    m = millis();
    if (cnt) {
      digitalWrite(13, HIGH);
      cnt = 0;
    } else {
      digitalWrite(13, LOW);
      cnt = 1;
    }
  }
}