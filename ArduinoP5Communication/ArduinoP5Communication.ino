/*
 * Arduino to P5.js Communication
 * Bomani Oseni McClendon
 * 
 * Find the corresponding p5.js code here: https://editor.p5js.org/bomanimc/sketches/QJUjLFUIa
 */
 
void setup() {
  // Initialize serial communication with Baud rate of 9600.
  Serial.begin(9600);

  // Set pin A0 as an input.
  pinMode(A0, INPUT);
}
 
void loop() {
  // Read the value from the potentiometer.
  int potentiometerValue = analogRead(A0);

  // Map the potentiometer value so that it fits into one byte.
  // A byte is 8 bits. Remember that 2^8 - 1 = 255.
  int mappedPot = map(potentiometerValue, 0, 1023, 0, 255);
  
  // Write the potentiometer value to the serial port.
  Serial.write(mappedPot);
  
  // Add a delay to stabilize the ADC.
  delay(100);     
}
