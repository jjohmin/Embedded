#include <LiquidCrystal_I2C.h>
#include <DFRobot_DHT11.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Wire.h>

//#define DHT_Pin 7
#define WIFI_SSID "wi_dje21"
#define WIFI_PASSWORD "Djedsmhspw2015!"

#define FIREBASE_HOST "autopompomme-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "hxbXBYYM5kkWoIGdgtgdhfAxt1L0XqZTxl1eAOc4"

//LiquidCrystal_I2C lcd(0x27, 16, 2);

int waterPin = 4;  // 물 주는 핀 설정
int lightPin = 5;  // 빛 주는 핀 설정
int doorPin = 6;   // 문 여는 핀 설정
//DFRobot_DHT11 DHT;                     // 온습도를 알 수 있는 핀 설정
const int waterSensorPin = A0;              // 물 센서 핀 설정
int waterThreshold = 500;                   // 물 수치
bool alarmSent = false;                     // 알람 전송 여부
bool autoWatering = true;                   // 자동 물 주기 여부
unsigned long previousWateringTime = 0;     // 이전 물 주기 시간
unsigned long wateringInterval = 60000000;  // 물 주기 간격 (기본: 1000분)
FirebaseData fbdo;
FirebaseJson json;
void printResult(FirebaseData &data);
int times;

void setup() {
  //ESP.wdtDisable();
  Serial.begin(115200);
  Serial.println("h");
  //WiFi.disconnect();//기존 설정이 있을지 모르니 연결을 해제 합니다.
  lcd.init();
  lcd.backlight();

  pinMode(waterPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(doorPin, OUTPUT);

  WF();
}

char weather() {
  char data = Firebase.get(fbdo, "pampame");
  return data;
}

void sendAlarm() {
  if (!alarmSent) {
    Firebase.setString(fbdo, "Water", "Change");
    alarmSent = true;
  }
}

void startAutoWatering() {
  autoWatering = true;
  previousWateringTime = millis();
}

void stopAutoWatering() {
  autoWatering = false;
}

void WF() {
  // Serial.begin(115200);
  Serial.println("ha");
  //Serial.begin(115200);
  delay(1000);

  // 와이파이 연결하기
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println();
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  // 파이어베이스 시작
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set the size of WiFi rx/tx buffers in the case where we want to work with large data.
  fbdo.setBSSLBufferSize(1024, 1024);

  //Set the size of HTTP response buffers in the case where we want to work with large data.
  fbdo.setResponseSize(1024);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(fbdo, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(fbdo, "tiny");

  //optional, set the decimal places for float and double data to be stored in database
  Firebase.setFloatDigits(2);
  Firebase.setDoubleDigits(6);

  /*
    This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
    Firewall that allows only GET and POST requests.

    Firebase.enableClassicRequest(fbdo, true);
  */

  String path = "/Test";

  Serial.println("------------------------------------");
  Serial.println("Set double test...");

  for (uint8_t i = 0; i < 10; i++) {
    //Also can use Firebase.set instead of Firebase.setDouble
    if (Firebase.setDouble(fbdo, path + "/Double/Data" + (i + 1), ((i + 1) * 10) + 0.123456789)) {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      Serial.println("ETag: " + fbdo.ETag());
      Serial.print("VALUE: ");
      printResult(fbdo);
      Serial.println("------------------------------------");
      Serial.println();
    } else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Get double test...");

  for (uint8_t i = 0; i < 10; i++) {
    //Also can use Firebase.get instead of Firebase.setInt
    if (Firebase.getInt(fbdo, path + "/Double/Data" + (i + 1))) {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      Serial.println("ETag: " + fbdo.ETag());
      Serial.print("VALUE: ");
      printResult(fbdo);
      Serial.println("------------------------------------");
      Serial.println();
    } else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Push integer test...");

  for (uint8_t i = 0; i < 5; i++) {
    //Also can use Firebase.push instead of Firebase.pushInt
    if (Firebase.pushInt(fbdo, path + "/Push/Int", (i + 1))) {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.print("PUSH NAME: ");
      Serial.println(fbdo.pushName());
      Serial.println("ETag: " + fbdo.ETag());
      Serial.println("------------------------------------");
      Serial.println();
    } else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Push JSON test...");

  for (uint8_t i = 5; i < 10; i++) {

    json.clear().add("Data" + String(i + 1), i + 1);

    //Also can use Firebase.push instead of Firebase.pushJSON
    //Json string is not support in v 2.6.0 and later, only FirebaseJson object is supported.
    if (Firebase.pushJSON(fbdo, path + "/Push/Int", json)) {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.print("PUSH NAME: ");
      Serial.println(fbdo.pushName());
      Serial.println("ETag: " + fbdo.ETag());
      Serial.println("------------------------------------");
      Serial.println();
    } else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Update test...");

  for (uint8_t i = 0; i < 5; i++) {

    json.set("Data" + String(i + 1), i + 5.5);

    if (Firebase.updateNode(fbdo, path + "/float", json)) {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      printResult(fbdo);
      Serial.println("------------------------------------");
      Serial.println();
    } else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }
}

void printResult(FirebaseData &data) {

  if (data.dataType() == "int")
    Serial.println(data.intData());
  else if (data.dataType() == "float")
    Serial.println(data.floatData(), 5);
  else if (data.dataType() == "double")
    printf("%.9lf\n", data.doubleData());
  else if (data.dataType() == "boolean")
    Serial.println(data.boolData() == 1 ? "true" : "false");
  else if (data.dataType() == "string")
    Serial.println(data.stringData());
  else if (data.dataType() == "json") {
    Serial.println();
    FirebaseJson &json = data.jsonObject();
    //Print all object data
    Serial.println("Pretty printed JSON data:");
    String jsonStr;
    json.toString(jsonStr, true);
    Serial.println(jsonStr);
    Serial.println();
    Serial.println("Iterate JSON data:");
    Serial.println();
    size_t len = json.iteratorBegin();
    String key, value = "";
    int type = 0;
    for (size_t i = 0; i < len; i++) {
      json.iteratorGet(i, type, key, value);
      Serial.print(i);
      Serial.print(", ");
      Serial.print("Type: ");
      Serial.print(type == FirebaseJson::JSON_OBJECT ? "object" : "array");
      if (type == FirebaseJson::JSON_OBJECT) {
        Serial.print(", Key: ");
        Serial.print(key);
      }
      Serial.print(", Value: ");
      Serial.println(value);
    }
    json.iteratorEnd();
  } else if (data.dataType() == "array") {
    Serial.println();
    //get array data from FirebaseData using FirebaseJsonArray object
    FirebaseJsonArray &arr = data.jsonArray();
    //Print all array values
    Serial.println("Pretty printed Array:");
    String arrStr;
    arr.toString(arrStr, true);
    Serial.println(arrStr);
    Serial.println();
    Serial.println("Iterate array values:");
    Serial.println();
    for (size_t i = 0; i < arr.size(); i++) {
      Serial.print(i);
      Serial.print(", Value: ");

      FirebaseJsonData &jsonData = data.jsonData();
      //Get the result data from FirebaseJsonArray object
      arr.get(jsonData, i);
      if (jsonData.typeNum == FirebaseJson::JSON_BOOL)
        Serial.println(jsonData.boolValue ? "true" : "false");
      else if (jsonData.typeNum == FirebaseJson::JSON_INT)
        Serial.println(jsonData.intValue);
      else if (jsonData.typeNum == FirebaseJson::JSON_FLOAT)
        Serial.println(jsonData.floatValue);
      else if (jsonData.typeNum == FirebaseJson::JSON_DOUBLE)
        printf("%.9lf\n", jsonData.doubleValue);
      else if (jsonData.typeNum == FirebaseJson::JSON_STRING || jsonData.typeNum == FirebaseJson::JSON_NULL || jsonData.typeNum == FirebaseJson::JSON_OBJECT || jsonData.typeNum == FirebaseJson::JSON_ARRAY)
        Serial.println(jsonData.stringValue);
    }
  } else if (data.dataType() == "blob") {

    Serial.println();

    for (int i = 0; i < data.blobData()->size(); i++) {
      if (i > 0 && i % 16 == 0)
        Serial.println();


      if (i < 16)
        Serial.print("0");

      Serial.print((*data.blobData())[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  } else if (data.dataType() == "file") {

    Serial.println();

    File file = data.fileStream();
    int i = 0;

    while (file.available()) {
      if (i > 0 && i % 16 == 0)
        Serial.println();

      int v = file.read();

      if (v < 16)
        Serial.print("0");

      Serial.print(v, HEX);
      Serial.print(" ");
      i++;
    }
    Serial.println();
    file.close();
  } else {
    Serial.println(data.payload());
  }
}

void sendth(int te, int hu) {
  Firebase.setString(fbdo, "tem", te);
  Firebase.setString(fbdo, "hum", hu);
}

void loop() {
  //DHT.read(DHT_Pin);
  int waterLevel = analogRead(waterSensorPin);  // 물의 수위 측정

  if (waterLevel > waterThreshold) {  // 물이 수치를 넘었다면
    sendAlarm();
  } else {
    alarmSent = false;
  }

  if (Serial.available()) {
    int data = Firebase.get(fbdo, "pampame");
    if (data == '1') {               // 안드로이드에서 '1'을 수신하면 물을 주는 동작 실행
      digitalWrite(waterPin, HIGH);  // 물 주기
      delay(2000);                   // 유지
      digitalWrite(waterPin, LOW);   // 물 그만
    } else if (data == '2') {
      digitalWrite(lightPin, HIGH);  // 불 켜기
    } else if (data == '3') {
      digitalWrite(lightPin, LOW);  // 불 끄기
    } else if (data == '5') {
      stopAutoWatering();
    } else if (data >= '0' && data <= '9') {
      int interval = (data - '0') * 600000;
      wateringInterval = interval;
      if (autoWatering) {
        previousWateringTime = millis();
      }
    }
  }

  if (autoWatering) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousWateringTime >= wateringInterval) {
      previousWateringTime = currentMillis;
      digitalWrite(waterPin, HIGH);
      delay(2000);
      digitalWrite(waterPin, LOW);
    }
  }

  if (weather() == 'm')
    digitalWrite(doorPin, HIGH);
  else
    digitalWrite(doorPin, LOW);

  if (millis() - times > 1000) {
    times = millis();

    float t = DHT.temperature;
    float h = DHT.humidity;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature: ");  // 온도 출력
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");  // 습도 출력
    lcd.print(h);
    lcd.print("%");

    sendth(t, h);
  }
}