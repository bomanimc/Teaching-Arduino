/*
 * H-Bridge Motor Controller (L293D)
 * Bomani Oseni McClendon
 * 
 * The L293D is an IC that makes it easier to switch the polarity of
 * a DC motor using digital signals from an Arduino. Internally,
 * it uses an arrangement of transistors, as well as diodes that protect
 * against reverse current spikes from the motor.
 * 
 * Each side of the L293D IC can support bidirectional rotation for a DC motor.
 * 
 * L293D Pins (for functionality on one side):
 * ENABLE 1: +5VDC (Setting to 0V will disable any motor movement)
 * INPUT 1: Digital control for rotation direction 1 i.e. CW/CCW (OUTPUT) - Pin 8
 * OUTPUT 1: Output voltage for rotation direction 1 i.e. CW/CCW - Connect to Motor 
 * GND: 0VDC
 * OUTPUT 2: Output voltage for rotation direction 1 i.e. CW/CCW - Connect to Motor 
 * INPUT 2: Digital control for rotation direction 2 i.e. CW/CCW (OUTPUT) - Pin 9
 * VSS: Voltage for digital logic. +5VDC.
 * VS: Supply voltage for the motor, if different from VSS. Use +5VDC for simplicity.
 * 
 * Truth Table:
 * If INPUT 1 & INPUT 2 are both set to the same state, stop the motor
 * If INPUT 1 is HIGH and INPUT 2 is LOW, turn in INPUT 1's direction.
 * If INPUT 1 is LOW and INPUT 2 is HIGH, turn in INPUT 2's direction.
 * If ENABLE 1 is LOW, stop regardless of INPUT 1 and INPUT 2 signals.
 * 
 * Datasheet: https://www.arduino.cc/documents/datasheets/H-bridge_motor_driver.PDF
 */
const int input1 = 8;
const int input2 = 9;

void setup() {
  // Set INPUT 1 & 2 as output pins.
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop() {
  // Turn in INPUT 1's direction.
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(2000);

  // By making INPUT 1 the same as INPUT 2, we stop the motor.
  digitalWrite(input1, LOW);
  delay(1000);

  // Turn in INPUT 2's direction.
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  delay(2000);

  // By making INPUT 2 the same as INPUT 1, we stop the motor.
  digitalWrite(input2, LOW);
  delay(1000);
}
