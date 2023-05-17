int a=0;
int toggle=1;

void setup(){
	pinMode(13,OUTPUT);
}

void loop(){
	digitalWrite(13,HIGH);
	if(toggle)
		a+=1;
	else
		a-=1;
	if(a>255)
		toggle=0;
	else if(a==0)
		toggle=1;
	for(int i=0;i<=255;i++){
		if(a<i)
			digitalWrite(13,LOW);
		delayMicroseconds(20);
	}
}