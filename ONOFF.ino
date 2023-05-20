void setup(){
	pinMode(10,INPUT);
	pinMode(13,OUTPUT);
}

void loop(){
	int n=digitalRead(10);
	if(n)
		digitalWrite(13,LOW);
	else
		digitalWrite(13,HIGH);
}