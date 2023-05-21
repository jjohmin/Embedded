void setup() {
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(8, OUTPUT);
}

void loop(){
  int n=digitalRead(9);
  int m=digitalRead(10);
  if(n)
    digitalWrite(13,LOW);
  else
    digitalWrite(13,HIGH);
  if(m)
    digitalWrite(8,LOW);
  else
    digitalWrite(8,HIGH);
}