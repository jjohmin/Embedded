#define TRIG 9;
#define ECHO 8;

void setup() {
	Serial.begin(9600);
	pinMode(TRIG,OUTPUT);
	pinMode(ECHO,INPUT);
}

void loop() {
	long duration, distance;
	digitalWrite(TRIG,LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG,HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG,LOW);
	duration = pulseIn(ECHO,HIGH);
	distance = duration * 17 / 1000;
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}