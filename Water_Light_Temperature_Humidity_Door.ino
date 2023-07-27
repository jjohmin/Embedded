#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <DFRobot_DHT11.h>

#define DHT_Pin 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial bluetoothSerial(2, 3);  // 블루투스 모듈의 RX, TX 핀 설정
int waterPin = 4;                      // 물 주는 핀 설정
int lightPin = 5;                      // 빛 주는 핀 설정
int doorPin = 6;                       // 문 여는 핀 설정
DFRobot_DHT11 DHT;                    // 온습도를 알 수 있는 핀 설정

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(waterPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(doorPin, OUTPUT);
}

String weather() {

  return "맑음";
}

void loop() {
  DHT.read(DHT_Pin);

  if (bluetoothSerial.available()) {
    char data = bluetoothSerial.read();  // 블루투스로부터 데이터 수신
    if (data == '1') {                   // 안드로이드에서 '1'을 수신하면 물을 주는 동작 실행
      digitalWrite(waterPin, HIGH);      // 물 주기
      delay(2000);                       // 유지
      digitalWrite(waterPin, LOW);       // 물 그만
    } else if (data == '2') {
      digitalWrite(lightPin, HIGH);  // 불 켜기
    } else if (data == '3') {
      digitalWrite(lightPin, LOW);  // 불 끄기
    }
  }

  if (weather() == "맑음")
    digitalWrite(doorPin, HIGH);
  else
    digitalWrite(doorPin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");  // 온도 출력
  lcd.print(DHT.temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");  // 습도 출력
  lcd.print(DHT.humidity);
  lcd.print("%");

  delay(2000);  // 2초 대기
}
