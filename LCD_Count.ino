#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤더파일 열기

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(주소, 가로, 세로)
int n;

void setup() {
  lcd.init();       // lcd 초기화
  lcd.backlight();  // 배경 초기화
}

void loop() {
  n++;
  lcd.setCursor(1, 0);  // 앞 공백 (1칸, 0번쨰줄)
  lcd.print(n);         // lcd에 출력
  delay(1000);
}