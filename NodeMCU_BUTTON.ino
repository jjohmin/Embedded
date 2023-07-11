const int buttonFLASH = D3;

void setup() {
  Serial.begin(115200);
  pinMode(buttonFLASH, INPUT);
}

void loop() {
  int buttonValue = digitalRead(buttonFLASH);
  Serial.println(buttonValue);
}