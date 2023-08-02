int sensorPin = A0;   // sensor핀을 아날로그0으로 지정
int ledPin = 13;      // led핀을 13(내장led)으로 지정
int sensorValue = 0;  // 센서값

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // 센서값 = 센서핀이 읽는 값
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);  // 센서값만큼 정지
  digitalWrite(ledPin, LOW);
  delay(sensorValue);  // 센서값만큼 정지
}