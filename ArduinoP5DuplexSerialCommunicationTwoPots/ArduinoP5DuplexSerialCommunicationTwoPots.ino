/*
 * Arduino & P5.js Duplex Communication
 * Bomani Oseni McClendon
 * 
 * Find the corresponding p5.js code here: https://editor.p5js.org/bomanimc/sketches/keQWv59Ug
 */

int leftPotPin = A0;
int rightPotPin = A1;
int ledPin = 7;
int incomingByte;
 
void setup() {
  // Initialize serial communication with Baud rate of 9600.
  Serial.begin(9600);
  Serial.setTimeout(10); // set the timeout for parseInt

  // Set pin A0 as an input.
  pinMode(leftPotPin, INPUT);

  // Set pin A1 as an input.
  pinMode(rightPotPin, INPUT);

  // Set pin 7 as an input.
  pinMode(ledPin, OUTPUT);
}
 
void loop() {
  // Read the value from the potentiometers.
  int leftPotentiometerValue = analogRead(leftPotPin);
  int rightPotentiometerValue = analogRead(rightPotPin);
  
  // Write the potentiometer value to the serial port.
  Serial.print(leftPotentiometerValue);
  Serial.print(",");
  Serial.println(rightPotentiometerValue);

  if (Serial.available() > 0) { // see if there's incoming serial data
    incomingByte = Serial.read(); // read it
    if (incomingByte == 'H') {    // if it's a capital H (ASCII 72),
      digitalWrite(ledPin, HIGH); // turn on the LED
    }
    if (incomingByte == 'L') {    // if it's an L (ASCII 76)
      digitalWrite(ledPin, LOW);  // turn off the LED
    }
  }
  
  // Add a delay to stabilize the ADC.
  delay(100);
}
