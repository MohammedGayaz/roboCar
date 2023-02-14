/*
 * simple robot car
 1) stable movement
*/

#include "movement.h"

const int fun_speed[] = {150, 150, 150, 150};

void setup()
  // initilizing all motors with normal speed
  set_motorSpeed(fun_speed);
  // stoping all the motors
  stop_motor();
  Serial.begin(9600);
}

void loop() {
  
}
