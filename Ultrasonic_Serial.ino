int trigPin = 2;
int echoPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  // trig를 출력모드로 설정
  pinMode(echoPin, INPUT);   // echo를 입력모드로 설정
}

void loop() {
  float duration, distance;     // 실수형 duration, distance 지정
  digitalWrite(trigPin, HIGH);  // 초음파를 보내고 대기
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  // echoPin이 HIGH를 유지한 시간 저장
  distance = ((float)(340 * duration) / 10000) / 2;
  // 초음파를 보내고 다시 돌아온 시간을 측정해 거리 계산
  Serial.print(distance);  // 거리 출력
  Serial.println("cm");
  delay(500);
}