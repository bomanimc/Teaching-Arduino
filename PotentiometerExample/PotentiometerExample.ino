int ledPin = 13;      // select the pin for the LED
int sensorPin = A0;
int sensorValue = 0;
int delayPeriod = 0;

void setup() {
  Serial.begin(9600); //  setup serial
  
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  // declare the sensorPin as an INPUT:
  pinMode(sensorPin, INPUT); //analog input
}

void loop() {
  sensorValue = analogRead(sensorPin);
  delayPeriod = map(sensorValue, 0, 1023, 250, 2000);

  Serial.println(sensorValue); // debug value
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  delay(delayPeriod);
  
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);           
}
