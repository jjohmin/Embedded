int a=0;
void setup(){
	pinMode(13,OUTPUT);
}

void loop(){
	digitalWrite(13,HIGH);
	a+=1;
	if(a>255)
		a=0;
	for(int i=0;i<=255;i++){
		if(a<i)
			digitalWrite(13,LOW);
		delayMicroseconds(20);    // delay(1000)==1s  // delayMicroseconds(20)==0.000005s
	}
}