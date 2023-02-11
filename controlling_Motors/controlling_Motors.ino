/*
 * simple robot car
*/

#include "movement.h"


void setup() {
  // put your setup code here, to run once:

  // initilizing all motors with normal speed
  set_motorSpeed(normal_speed, normal_speed, normal_speed, normal_speed);

  // stoping all the motors
  stop_motor();
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(3000);
  stop_motor();

  delay(1000);
  
  turn_right();
  delay(2000);
  stop_motor();

  delay(1000);
  
  backward();
  delay(3000);
  stop_motor();

  delay(1000);

  turn_left();
  delay(2000);
  stop_motor();

  delay(1000);

}
