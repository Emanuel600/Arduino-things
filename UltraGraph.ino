// Using define saves a little memory
#define trig 3
#define echo 2
// Declare variables
int tim; //time is a reserved word
int dis;

void setup() {
  // Set Serial up
  Serial.begin(9600);
  while(!Serial);
  // Set Pin Modes
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  // Create Timed Pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); // Time for trigger
  digitalWrite(trig, LOW);
  delay(320); // Time for all 8 cycles of ultrasonic waves to finish and echo to start
  
  // Measure time
  tim = pulseIn (echo, HIGH);
  // Calculate distance
  dis = (tim * 0.0343) / 2;
  
  // Create graph with Serial Plotter
  Serial.print(dis);
  Serial.println();
}
