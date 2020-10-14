const int motorPin = 8;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  analogWrite(motorPin, 255);
  delay(1000);
  analogWrite(motorPin, 0);
  delay(1000);
}
