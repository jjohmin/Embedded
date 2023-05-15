void setup(){
	pinMode(13,OUTPUT);      // pinMode(핀 번호,형식)
}

void loop(){
	digitalWrite(13,HIGH);   // digitalWrite(핀 번호,HIGH(1) or LOW(0))
	digitalWrite(13,LOW);
}