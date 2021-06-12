int led = 8;
int but = 7;
bool butt = false;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(but, INPUT);
digitalWrite(led, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  butt = digitalRead(but);
  digitalWrite(led, butt);
}
