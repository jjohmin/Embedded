#include <DFRobot_DHT11.h>

#define DHT_Pin 7
DFRobot_DHT11 DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read(DHT_Pin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("humidity: ");
  Serial.println(h);
}