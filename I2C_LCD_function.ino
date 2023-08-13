| lcd.begin( ); | LCD를 사용을 시작 |
| --- | --- |
| lcd.display( ); | LCD에 내용을 표시 |
| lcd.noDisplay( ); | LCD에 내용을 숨김 |
| lcd.setCursor(col,row); | row, col의 좌표로 커서를 위치 |
| lcd.cursor( ); | LCD에 커서를 표시 |
| lcd.noCursor( ); | LCD에 커서를 숨김 |
| lcd.home( ); | 커서의 위치를 0,0으로 이동 |
| lcd.blink( ); | 커서를 깜빡임 |
| lcd.noBlink( ); | 커서를 깜빡이지 않음 |
| lcd.backlight( ); | LCD backlight을 킴 |
| lcd.noBacklight( ); | LCD backlight를 끔 |
| lcd.write(val); | LCD 화면에 val 출력                                                      (아스키 코드 입력 시에는 아스키 코드에 해당하는 문자출력) |
| lcd.print(val); | LCD 화면에 val 출력 |
| lcd.clear( ); | LCD 화면의 모든 내용 지움 |
| lcd.scrollDisplayRight( ); | 내용을 우측으로 1칸 이동 |
| lcd.scrollDisplayLeft( ); | 내용을 좌측으로 1칸 이동 |
| lcd.autoscroll( ); | 내용을 자동으로 우에서 좌로 스크롤 |