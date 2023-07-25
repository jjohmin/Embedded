int seg[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int arr[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
int i;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  for (int j = 0; j <= 9; j++) {
    for (i = 0; i < 8; i++) {
      digitalWrite(seg[i], bitRead(arr[j], i));  // bitRead : 매개변수를 비트로 변환
    }
    delay(1000);
  }
}