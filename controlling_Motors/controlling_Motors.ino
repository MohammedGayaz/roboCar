/*
 * simple robot car
 1) stable movement
*/

#include "movement.h"
#include "check_line.h"

const int fun_speed[] = {150, 150, 150, 150};

void setup(){
  // initilizing all motors with normal speed
  set_motorSpeed(fun_speed);
  // stoping all the motors
  stop_motor();
  Serial.begin(9600);
}

void loop() {
  int dir = detect_line();
  Serial.println(dir);
  if(dir == -1){
    forward();
  }
  else if(dir == 1){
    turn_right();
  }
  else if(dir == 2){
    turn_left(); 
  }
  else{
    stop_motor();
  }
  
}
