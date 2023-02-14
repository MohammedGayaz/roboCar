/*
 * simple robot car
 1) stable movement
*/

#include "movement.h"
#include "check_line.h"

const int fun_speed[] = {125, 125, 125, 125};

void setup(){
  motor1.setSpeed(125);
  motor1.run(RELEASE);

  motor2.setSpeed(125);
  motor2.run(RELEASE);
  
  motor3.setSpeed(125);
  motor3.run(RELEASE);

  motor4.setSpeed(125);
  motor4.run(RELEASE);
  
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  Serial.begin(9600);
}

void loop() {
  int dir = detect_line();
  Serial.println(dir);
  if(dir == 0){
    forward();
    Serial.println("moving forward");
  }
  else if(dir == 1){
    Serial.println("turning right");
    turn_right();
  }
  else if(dir == 2){
    Serial.println("turning left");
    turn_left();
  }
  else{
    Serial.println("reached dist");
    stop_motor();
  }
  
}
