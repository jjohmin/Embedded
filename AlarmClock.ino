#include <core_build_options.h>
#include <swRTC.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

swRTC rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);
extern volatile unsigned long timer0_millis;
int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int com[4] = { 10, 11, 12, 13 };
int arr[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, 1 },
  { 0, 1, 1, 0, 0, 0, 0, 1 },
  { 1, 1, 0, 1, 1, 0, 1, 1 },
  { 1, 1, 1, 1, 0, 0, 1, 1 },
  { 0, 1, 1, 0, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1 }
};
int but = 1;
void setup() {
  pinMode(but, INPUT_PULLUP);
  for (int i = 0; i < 8; i++)
    pinMode(seg[i], OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(com[i], OUTPUT);
  Serial.begin(9600);
  // 수정: A0 핀을 출력으로 설정합니다.
  pinMode(A0, OUTPUT);
  lcd.init();
  lcd.backlight();
  rtc.stopRTC();
  rtc.setTime(2, 28, 10);  //시, 분, 초
  rtc.startRTC();
}

void loop() {
  int n = digitalRead(but);
  one();
  if (Serial.available()) {
    // 수정: 입력된 문자열을 숫자로 변환합니다.
    int num = Serial.parseInt();
    if (num > 9960) {
      Serial.println("ERROR - 9960안의 숫자를 입력해주세요.");
    } else {
      alarm(num += 1);
      num = 0;
      for (int k = 0; k < 4; k++) {
        digitalWrite(com[k], LOW);
      }
      while (n) {
        n = digitalRead(but);
        tone(A0, 264);
      }
      noTone(A0);
    }
  }
}

void alarm(int n) {
  int ti = 0;
  int tim = 0;
  int j = n;
  int c = 0, b = 0, s = 0, l = 0;
  if (n >= 1000) {
    c = n / 1000;
    n -= c * 1000;
  }
  if (n >= 60) {
    b = n / 60;
    n -= b * 60;
  }
  if (n >= 10) {
    s = n / 10;
    n -= s * 10;
  }
  if (n >= 0) {
    l = n;
    n = 0;
  }

  while (j > -1) {
    int nu[4] = { c, b, s, l };
    if (millis() - ti >= 2) {
      ti = millis();
      for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
          digitalWrite(com[k], LOW);
        }
        digitalWrite(com[i], HIGH);
        if (i != 1) {
          for (int p = 0; p < 8; p++) {
            // 수정: HIGH를 LOW로 변경하여 세그먼트 활성화
            digitalWrite(seg[p], !arr[nu[i]][p]);
          }
          // 수정: 7번 핀을 LOW로 설정하여 공통 어노드 활성화
          digitalWrite(seg[7], HIGH);
        } else {
          for (int p = 0; p < 8; p++) {
            digitalWrite(seg[p], !arr[nu[i]][p]);
          }
        }
        delay(1);
      }
    }
    if (millis() - tim >= 1000) {
      timer0_millis = 0;
      j--;
      if (l != 0) {
        l--;
      } else if (s != 0) {
        s--;
        l += 9;
      } else if (b != 0) {
        b--;
        s += 5;
        l += 9;
      } else if (c != 0) {
        c--;
        b += 9;
        s += 5;
        l += 9;
      }
    }
  }
}

void one() {
  int nt = 0;
  if (millis() - nt >= 1000) {
    timer0_millis = 0;
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Now Clock");
    lcd.setCursor(4, 1);
    lcd.print(rtc.getHours(), DEC);
    lcd.print(":");
    lcd.print(rtc.getMinutes(), DEC);
    lcd.print(":");
    lcd.print(rtc.getSeconds(), DEC);
  }
}