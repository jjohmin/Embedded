#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BUZZER_PIN 8
#define SW_PIN 12
int echo = 6;
int trig = 7;
LiquidCrystal_I2C lcd(0x27, 20, 4);
int pushupCnt = 0;
int pushState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SW_PIN, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" PUSHUP COUNTER");
}

void loop() {
  float distance = ultraSonic();
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
  if (distance <= 10 && pushState == 0) {  // 초음파 센서 감지시
    pushState = 1;
    pushupCnt++;
    lcd.setCursor(8, 1);
    lcd.print("  ");
    lcd.setCursor(8, 1);
    lcd.print(pushupCnt);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  } else if (distance >= 30 && pushState == 1) {  // 초음파 센서 감지 해제시
    pushState = 0;
  }

  if (digitalRead(SW_PIN) == 0) {  // 버튼 클릭시
    pushupCnt = 0;
    lcd.setCursor(8, 1);
    lcd.print("  ");
    lcd.setCursor(8, 1);
    lcd.print(pushupCnt);
    delay(100);
  }
}

float ultraSonic() {  // 거리
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  float distanceCM = ((34000 * duration) / 1000000) / 2;

  return distanceCM;
}