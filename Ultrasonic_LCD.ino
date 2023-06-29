#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// 16 chars and 2 line 디스플레이를 위해 LCD 주소를 0x27 또는 0x3f로 설정
LiquidCrystal_I2C lcd(0x27, 20, 4);

// defines arduino pins numbers
const int trigPin = 3;
const int echoPin = 4;
// defines variables
long duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);  // trigPin을 출력으로 설정
  pinMode(echoPin, INPUT);   // echoPin을 입력으로 설정
  Serial.begin(9600);        // Starts the serial communication
}

void loop() {
  // trigPin 초기화
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // 10 마이크로초 동안 trigPin을 HIGH 상태로 설정
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // echoPin을 읽고 음파 이동 시간을 마이크로초 단위로 반환합니다.
  duration = pulseIn(echoPin, HIGH);
  // 거리 계산
  distance = duration * 0.034 / 2;
  // 거리 출력
  Serial.print(distance);
  Serial.println(" cm");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Distance in cm ");
  lcd.setCursor(6, 1);
  lcd.print(distance);
  delay(150);
}