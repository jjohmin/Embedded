#define ROW1 7
#define COL1 15

unsigned char COL_PIN[4] = { 18, 17, 16, 15 };
unsigned char ROW_PIN[4] = { 7, 8, 9, 10 };

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ROW_PIN[i], INPUT);
    pinMode(COL_PIN[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(COL_PIN[i], LOW);
  }
}

unsigned char flag_up[4][4];
unsigned char flag_down[4][4];

unsigned long curr_millis;
unsigned long prev_millis;
int index;

void loop() {

  curr_millis = millis();

  if (curr_millis - prev_millis >= 2) {
    prev_millis = curr_millis;

    // all off
    for (int i = 0; i < 4; i++) {
      digitalWrite(COL_PIN[i], LOW);
    }
    //one on
    digitalWrite(COL_PIN[index], HIGH);

    //row read
    for (int i = 0; i < 4; i++) {
      int button_1 = digitalRead(ROW_PIN[i]);
      Serial.println(button_1);
      if (button_1 == 1) {
        if (flag_down[index][i] == 0) {
          flag_down[index][i] = 1;
          Serial.println(String(i * 4 + index) + " : Down");
          flag_up[index][i] = 0;
        }
      } else {
        if (flag_up[index][i] == 0) {
          flag_up[index][i] = 1;
          Serial.println(String(i * 4 + index) + " : Up");
          flag_down[index][i] = 0;
        }
      }
    }
  }
  index++;
  if (index == 4) index = 0;
}