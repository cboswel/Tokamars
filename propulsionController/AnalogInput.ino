/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int xPin = A0;    // select the input pin for the potentiometer
int yPin = A1;
int ledPin = 13;      // select the pin for the LED
int xValue = 0; // variable to store the value coming from the sensor
int yValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  /*// turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);*/
  xValue = map(xValue,9,1018,100,-100);
  int xConstrain = constrain(xValue,-100,100);
  yValue = map(yValue,9,1018,-100,100);
  int yConstrain = constrain(yValue,-100,100);
  Serial.print(xConstrain);
  Serial.print(",");
  Serial.println(yConstrain);
}
