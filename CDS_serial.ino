int jodo = A0;
int led = 13;
int time;

void setup() {
  pinMode(jodo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(jodo);
  if (millis() - time > 500) {
    time = millis();
    Serial.println(light);
  }
}