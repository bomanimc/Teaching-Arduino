/*
* Button (Sensor)
* Bomani Oseni McClendon
*
* You can think of a button as a simple digital sensor. The state
* of the button can be read as a digital input by the Arduino.
* In this example, we'll (trivially) turn on and off two LEDs
* based on whether or not the button is pressed.
*
* Consider finding the appropriate datasheet for your sensor.
*
*/
int buttonState = 0;

void setup() {
  //  Begin Serial Port
  Serial.begin(9600);  

  //  Setup digital input for reading the button's state.
  pinMode(10, INPUT);

  //  Setup digital outputs for turning on LEDs connected
  //  to pins 6 and 7.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // Read the sate of the button and save it in a global variable.
  buttonState = digitalRead(10);

  //  Print the reading to the Serial monitor.
  Serial.println(buttonState);

  //  Use an if-else statement to define how the program should
  //  respond when the button is pressed or or unpressed.
  if (buttonState == HIGH) {
    // If the button is pressed, turn on the LEDs.
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  } 
  else {
    //  If the button is not pressed, turn off the LEDs.
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
}
