bool flag = true;

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  attachInterrupt(0, func, FALLING);
  //digitalPinToInterrupt(2);    // 0을 2로 고치는 법
}
void func() {
  flag = !flag;
}
void loop() {
  digitalWrite(13, flag);
}