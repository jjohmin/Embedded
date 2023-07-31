const int analogInPin = A0;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);  // 센서값 = 가변저항값
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);  // LED에 LED값만큼 출력

  Serial.print("sensor = ");
  Serial.print(sensorValue);  // 가변저항값
  Serial.print("\t output = ");
  Serial.println(outputValue);  // LED값
  delay(2);
}