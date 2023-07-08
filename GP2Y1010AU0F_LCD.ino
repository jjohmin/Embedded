#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 생성
int measurePin = 0;                  // 먼지 측정에 사용되는 아날로그 핀 번호
int ledPower = 10;                   // LED 전원 제어에 사용되는 디지털 핀 번호
int samplingTime = 280;              // 센서에서 샘플링하는 시간 (마이크로초)
int deltaTime = 40;                  // 샘플 간 딜레이 시간 (마이크로초)
int sleepTime = 9680;                // 측정 사이의 대기 시간 (마이크로초)
float voMeasured = 0;                // 아날로그 입력에서 측정된 전압 값
float calcVoltage = 0;               // 계산된 전압 값
float dustDensity = 0;               // 계산된 먼지 밀도 값

void setup() {
  lcd.init();                 // LCD 초기화
  lcd.backlight();            // LCD 백라이트 활성화
  Serial.begin(9600);         // 시리얼 통신 시작
  pinMode(ledPower, OUTPUT);  // ledPower 핀을 출력으로 설정
}

void loop() {
  digitalWrite(ledPower, LOW);                // 먼지 측정을 위해 LED 전원 OFF
  delayMicroseconds(samplingTime);            // 샘플링 시간 대기
  voMeasured = analogRead(measurePin);        // 아날로그 핀에서 전압 값 측정
  delayMicroseconds(deltaTime);               // 측정 간 딜레이 시간 대기
  digitalWrite(ledPower, HIGH);               // LED 전원 ON
  delayMicroseconds(sleepTime);               // 대기 시간 대기
  calcVoltage = voMeasured * (5.0 / 1024.0);  // 전압 값 계산
  dustDensity = 0.17 * calcVoltage - 0.1;     // 먼지 밀도 계산

  // LCD에 결과 출력
  lcd.print("Voltage: ");
  lcd.print(calcVoltage);
  lcd.print("v");
  lcd.setCursor(0, 1);
  lcd.print("Dust: ");
  lcd.println(dustDensity);
  lcd.print("mg/m3");

  delay(1000);  // 1초 대기
}