// Import libraries for nRF24L01 radio module
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Initialise nRF24L01
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001"; // address for this node

int xPin = A0; // select the input pin for the potentiometer
int yPin = A1;
int xValue = 0; // variables to store the values coming from the joystick
int yValue = 0;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // read the joystick potentiometer values and set them to be within -100 to 100
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  xValue = map(xValue,9,1018,100,-100);
  yValue = map(yValue,9,1018,-100,100);
  String xOutput = String(constrain(xValue,-100,100));
  String yOutput = String(constrain(yValue,-100,100));
  String message = xOutput + "," + yOutput;
  Serial.println(message);
  radio.write(&message, sizeof(message));
  delay(50);
}
