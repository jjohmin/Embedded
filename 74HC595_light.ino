int Dat = 4;
int lat = 5;
int clo = 6;

void setup() {
  pinMode(Dat, OUTPUT);
  pinMode(lat, OUTPUT);
  pinMode(clo, OUTPUT);
}

void loop() {
  for (int j = 0; j < 9; j++) {
    digitalWrite(clo, HIGH);
    OFF();
    digitalWrite(clo, LOW);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(clo, HIGH);
    light();
    digitalWrite(clo, LOW);
}

void light() {
  digitalWrite(lat, LOW);
  digitalWrite(Dat, LOW);
  digitalWrite(Dat, HIGH);
  digitalWrite(lat, HIGH);
}

void OFF() {
  digitalWrite(lat, LOW);
  digitalWrite(Dat, HIGH);
  digitalWrite(Dat, LOW);
  digitalWrite(lat, HIGH);
}