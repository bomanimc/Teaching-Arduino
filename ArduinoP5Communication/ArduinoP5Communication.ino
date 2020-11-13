/*
 * Arduino to P5.js Communication
 * Bomani Oseni McClendon
 *
 */
 
void setup() {
  // Initialize serial communication.
  Serial.begin(9600);

  // Set pin A0 as an input.
  pinMode(A0, INPUT);
}
 
void loop() {
  // Read the value from the potentiometer.
  int potentiometer = analogRead(A0);

  // Map the potentiometer value so that it fits into one byte.
  // A byte is 8 bits. Remember that 2^8 - 1 = 255.
  int mappedPot = map(potentiometer, 0, 1023, 0, 255);
  
  // Write the potentiometer value to the serial port.
  Serial.write(mappedPot);
  
  // Add a delay to stabilize the ADC.
  delay(100);                             
}
