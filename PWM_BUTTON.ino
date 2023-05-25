int a, mode = 1, cnt;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  int n = digitalRead(8);
  if (!n) {          // 버튼을 눌렀을 때
    if (!cnt) {      // 버튼을 한번 누른건지 검사
      mode = !mode;  // 1->0, 0->1
      cnt++;         // 버튼을 누르면 ++
    }
  } else      // 버튼을 안 눌렀을 때
    cnt = 0;  // 초기화
  if (mode)   // 밝기 올라가는 모드
    a += 1;
  else  // 밝기 내려가는 모드
    a -= 1;
  if (a > 255)  // 최대로 가면 고정
    a = 255;
  if (a < 0)  // 최소로 가면 고정
    a = -1;
  // PWM
  digitalWrite(9, HIGH);
  for (int i = 0; i <= 255; i++) {
    if (a < i)
      digitalWrite(9, LOW);
    delayMicroseconds(20);
  }
}