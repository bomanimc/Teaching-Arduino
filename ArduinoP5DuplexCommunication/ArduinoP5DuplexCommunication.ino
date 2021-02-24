/*
 * Arduino & P5.js Duplex Communication
 * Bomani Oseni McClendon
 * 
 * Find the corresponding p5.js code here: https://editor.p5js.org/bomanimc/sketches/QJUjLFUIa
 */
 
void setup() {
  // Initialize serial communication with Baud rate of 9600.
  Serial.begin(9600);

  // Set pin A0 as an input.
  pinMode(A0, INPUT);

  // Set pin A1 as an input.
  pinMode(A1, INPUT);
}
 
void loop() {
  // Read the value from the potentiometers.
  int leftPotentiometerValue = analogRead(A0);
  int rightPotentiometerValue = analogRead(A1);
  
  // Write the potentiometer value to the serial port.
  Serial.print(leftPotentiometerValue);
  Serial.print(",");
  Serial.println(rightPotentiometerValue);
  
  // Add a delay to stabilize the ADC.
  delay(100);
}
