const int relay = 3;
const int LIGHT = A0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);  // realy OUTPUT
  pinMode(LIGHT, INPUT);   // LIGHT INPUT
}

void loop() {
  int LIGHT = analogRead(LIGHT);  // LIGHT = LIGHT가 읽는 값(조도센서)

  if (LIGHT <= 300) {           // LIGHT가 300보다 같거나 낮다면
    digitalWrite(relay, HIGH);  // realy HIGH
    Serial.println("ON");
  }

  else {                       // 아니라면
    digitalWrite(relay, LOW);  // realy LOW
    Serial.println("소등");
  }

  Serial.println(LIGHT);
  delay(50);
}