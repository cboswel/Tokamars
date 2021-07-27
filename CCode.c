#include <stdio.h>

#define DEADSPOT 10                                    //range around neutral point to count as the neutral point, so imperfectly callibrated joysticks dont cause the Rover to move
#define NEUTRALPOINT 50                               // Value returned from the receiver when the stick is in the neutral position

/*************************************
IN1 IN2 PWM STBY OUT1 OUT2 Mode
H   H   H/L H    L    L    Short brake
L   H   H   H    L    H    CCW
L   H   L   H    L    L    Short brake
H   L   H   H    H    L    CW
H   L   L   H    L    L    Short brake
L   L   H   H    OFF       Stop
H/L H/L H/L L    OFF       Standby
**************************************/

int move(int y, int x) {
// function to set motors according to joystick state


// if both sticks are within the DEADSPOT (the neutral position in the centre):
  if (NEUTRALPOINT - (DEADSPOT / 2) <= y && y <= NEUTRALPOINT + (DEADSPOT / 2) && (NEUTRALPOINT - (DEADSPOT / 2) <= x && x <= NEUTRALPOINT + (DEADSPOT / 2))) {

// both motors stop.
      printf("\n Right stop");
      printf("\n Left stop");
      return 0;
  }
  

// if left stick is within DEADSPOT but right stick is turning left:
  if (NEUTRALPOINT - (DEADSPOT / 2) <= y && y <= NEUTRALPOINT + (DEADSPOT / 2) && x < NEUTRALPOINT - (DEADSPOT / 2)) {

// turn left on the spot: right goes forwards and left goes backwards, speed of x
      float position = (NEUTRALPOINT - x) * 2;
      int speed = (position * 255.0) / 100;
      printf("\n Right forwards: %d", speed);
      printf("\n Left backwards: %d", speed);

      return 0;
  }


// if left stick is within DEADSPOT but right stick is turning right:
  if (NEUTRALPOINT - (DEADSPOT / 2) <= y && y <= NEUTRALPOINT + (DEADSPOT / 2) && (x > NEUTRALPOINT + (DEADSPOT / 2))) {
// turn right on the spot: left goes forwards and right goes backwards, speed of x
      float position = (x - NEUTRALPOINT) * 2;
      int speed = (position * 255.0) / 100;
      printf("\n Right backwards: %d", speed);
      printf("\n Left forwards: %d", speed);

      return 0;
  }


// if left stick is forwards and right stick is within DEADSPOT:
  if (y > NEUTRALPOINT + (DEADSPOT / 2) && (NEUTRALPOINT - (DEADSPOT / 2) <= x && x <= NEUTRALPOINT + (DEADSPOT / 2))) {
// Go dead straight with both motors
      float position = (y - NEUTRALPOINT) * 2;
      int speed = (position * 255.0) / 100;
      printf("\n Right backwards: %d", speed);
      printf("\n Left forwards: %d", speed);
     return 0;
  }
 

// if left stick is forwards and right stick is turning left:
  if (y > NEUTRALPOINT + (DEADSPOT / 2) && (x < NEUTRALPOINT - (DEADSPOT / 2))) {
// Go forwards, arcing left
// To arc left, right wheel goes at max speed and left wheel goes at a percentage of max speed depending on how hard the turn is 
      float position = (y - NEUTRALPOINT) * 2;
      int speed = (position * 255.0) / 100;
      float np = NEUTRALPOINT;
      float scalar = (x / np);
      printf("\n Right backwards: %d", speed);

      speed = (speed * scalar);
      printf("\n Left forwards: %d", speed);

      return 0;
  }


// if left stick is forwards and right stick is turning right:
  if (y > (NEUTRALPOINT + (DEADSPOT / 2)) && NEUTRALPOINT - (x > NEUTRALPOINT + (DEADSPOT / 2))) {
// Go forwards, arcing right
// To arc right, left wheel goes at max speed and right wheel goes at a percentage of max speed depending on how hard the turn is 
      float position = (y - NEUTRALPOINT) * 2;
      int speed = (position * 255.0) / 100;
      float np = NEUTRALPOINT;
      float scalar = (1 - ((x - np) / np));
      speed = (speed * scalar);
      printf("\n Right backwards: %d", speed);

      speed = (position * 255.0) / 100;
      printf("\n Left forwards: %d", speed);
      return 0;
  }


// if left stick is reverse and right stick is within DEADSPOT:
  if (y < NEUTRALPOINT - (DEADSPOT / 2) && (NEUTRALPOINT - (DEADSPOT / 2) <= x && x <= NEUTRALPOINT + (DEADSPOT / 2))) {
// Reverse dead straight with both motors
      float position = (NEUTRALPOINT - y) * 2;
      int speed = (position * 255.0) / 100;
      printf("\n Right backwards: %d", speed);
      printf("\n Left forwards: %d", speed);
      return 0;
  }


// if left stick is reverse and right stick is turning left:
  if (y < (NEUTRALPOINT - (DEADSPOT / 2)) && x < (NEUTRALPOINT - (DEADSPOT / 2))) {
// Reverse while arcing left
// To arc left, right wheel goes at max speed and left wheel goes at a percentage of max speed depending on how hard the turn is 
      float position = (NEUTRALPOINT - y) * 2;
      int speed = (position * 255.0) / 100;
      float np = NEUTRALPOINT;
      float scalar = (x / np);
      printf("\n Right backwards: %d", speed);

      speed = (speed * scalar);
      printf("\n Left forwards: %d", speed);
      return 0;
  }


// if left stick is reverse and right stick is turning right:
  if (y < (NEUTRALPOINT - (DEADSPOT / 2)) && x > (NEUTRALPOINT + (DEADSPOT / 2))) {
// Reverse while arcing right
// To arc right, left wheel goes at max speed and right wheel goes at a percentage of max speed depending on how hard the turn is 
      float position = (NEUTRALPOINT - y) * 2;
      int speed = (position * 255.0) / 100;
      float np = NEUTRALPOINT;
      float scalar = (1 - ((x - np) / np));
      speed = (speed * scalar);
      printf("\n Right backwards: %d", speed);

      speed = (position * 255.0) / 100;
      printf("\n Left forwards: %d", speed);
      return 0;
  }
}



void main() {
  // put your main code here, to run repeatedly:

// *** insert function to calculate x and y values from receiver signals here***  
  printf("\n \n stop");
  move(50, 50);

  printf("\n \n forwards slowly");
  move(60, 50);

  printf("\n \n forwards fast");
  move(100, 50);

  printf("\n \n slow reverse");
  move(40, 50);

  printf("\n \n fast reverse");
  move(0, 50);

  printf("\n \n left on spot");
  move(50, 25);

  printf("\n \n right on spot");
  move(50, 75);

  printf("\n \n forwards, arc left");
  move(80, 27);

  printf("\n \n forwards, arc right");
  move(80, 80);

  printf("\n \n reverse, arc left");
  move(0, 27);

  printf("\n \n reverse, arc left");
  move(44, 27);

  printf("\n \n forwards, arc left");
  move(80, 27);

  printf("\n \n forwards, arc left");
  move(80, 27);








}
