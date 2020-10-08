/*
* Ultrasonic Sensor (HC-SR04) Distance Detector
* Core Lab: Objects - Bomani Oseni McClendon
*
* The ultrasonic sensor emits and ultrasonic sound (a sound that is out of the 
* range of human hearing) and measures the time that it takes for that sound
* to bounce off an object and return to the sensor. Using this duration, along
* with the known speed of sound (343 meter/second), we can calculate the
* distance between the sensor and object in front of it!
* 
* The TRIG pin controls the emission of the ultrasonic sound (output) and the 
* ECHO pin will read the time it takes for the emitted sound wave to return to 
* return to the sensor.
*
* Ultrasonic Sensor Pins:
* VCC: +5VDC
* Trig : Trigger (INPUT) - Pin 11
* Echo: Echo (OUTPUT) - Pin 12
* GND: GND
* 
* Data Sheet: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
*/

int trigPin = 11; // Connect to TRIG on sensor
int echoPin = 12; // Connect to ECHO on sensor

long duration, meters, centimeters, inches;
 
void setup() {
  // Begin Serial Port
  Serial.begin (9600);
  
  //Define inputs & outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  // The HC-SR04 data sheet specifies that the sensor needs a HIGH pulse of at
  // least 10 microseconds to start its ranging process. We can create a 10
  // microsecond pulse by turning the trigPin HIGH for 10 microseconds and then
  // setting it low again. Once the sensors interprets the pulse, it will send
  // out its ultrasonic sound bursts for ranging.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // The ECHO pin on the sensor will produce a HIGH pulse with duration (in microseconds)
  // that is equal to the time it took for the ultrasonic sound burst to return to the
  // sensor after echoing off a nearby object. We can use the pulseIn() function to get
  // the length (in microseconds) of a pulse on the echoPin.
  duration = pulseIn(echoPin, HIGH);
 
  // We need to convert the duration of the pulse on the ECHO pin into a useful distance
  // using what we know about the speed of sound.
  // First, we need to halve the duration variable. Since the ECHO pin pulse is the duration
  // for the full round trip of the sound wave (i.e. sensor -> object, object -> sensor), we
  // will only need half of the duration to calculate the distance from the sensor to the
  // object.
  // Second, we need to convert the halved duration into a distance using the speed of sound.
  // The speed of sound travels at 0.0343 cm/microsecon and 0.0135 inches/microsecond. Let's
  // use these values to calculate the distance in centimeters and inches using the general
  // equation: distance = time * speed.
  centimeters = (duration / 2) * 0.0343;
  inches = (duration / 2) * 0.0135;
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(centimeters);
  Serial.print("cm");
  Serial.println();

  // Pause for 100ms before taking another distance reading.
  delay(100);
}
