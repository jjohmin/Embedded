int car = 10;
int car2 = 9;
int sih = 8;
int ind = 7;
int ind2 = 6;
int echo = 5;
int trig = 4;
int inp = 3;

void setup() {
  pinMode(car, OUTPUT);
  pinMode(car2, OUTPUT);
  pinMode(sih, INPUT);
  pinMode(ind, OUTPUT);
  pinMode(ind2, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(inp, INPUT);
}

void loop() {
  int n = digitalRead(sih);
  int m = digitalRead(inp);
  float distance = guri();
  if (m == HIGH) {
    digitalWrite(car, LOW);
    digitalWrite(car2, HIGH);
    digitalWrite(ind, LOW);
    digitalWrite(ind2, HIGH);
  } else {
    if (distance <= 10) {
      digitalWrite(car, LOW);
      digitalWrite(car2, HIGH);
      digitalWrite(ind, LOW);
      digitalWrite(ind2, HIGH);
    } else {
      if (!n) {
        digitalWrite(car, LOW);
        digitalWrite(car2, HIGH);
        digitalWrite(ind, LOW);
        digitalWrite(ind2, HIGH);
      } else {
        digitalWrite(car, HIGH);
        digitalWrite(car2, LOW);
        digitalWrite(ind, HIGH);
        digitalWrite(ind2, LOW);
      }
    }
  }
}

float guri() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  float distanceCM = ((34000 * duration) / 1000000) / 2;

  return distanceCM;
}