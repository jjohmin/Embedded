int mSensor = A0;
int ledPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int readValue = analogRead(mSensor);
  int lightValue = readValue / 4;
  Serial.print("Read Value = ");
  Serial.println(readValue);
  Serial.print("Light Value = ");
  Serial.println(lightValue);
  analogWrite(ledPin, lightValue);
  delay(200);
}