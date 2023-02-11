/*
 * controlling and testing motors DC Motors
 * four DC motors can be contorlled at a time
 * M1, M2, M3, M4 are the terminals used to contorll motors
 * the operating voltage can be 4.5-25V
 * to contorll these motors we use AFMotor Library
*/

#include <AFMotor.h>


AF_DCMotor motor1(1); // it take motor port number M[1,2,3,4]
AF_DCMotor motor2(2); // M2
AF_DCMotor motor3(3); // M3
AF_DCMotor motor4(4); // M4


const int normal_speed = 200; // normal movement
const int high_speed = 255;   // max speed
const int slow_speed = 150;   // slow speed
/*
 * setSpeed(speed) controls the motor speed.
 * speed ranges form 0 -> 255
 * run(cmd) controls the motor spinning direciton
 * FORWARD   - spins forward direction
 * BACKWARD  - spins backward direction
 * RELEASE   - stops motor 
*/


void set_motorSpeed(int m1_speed, int m2_speed, int m3_speed, int m4_speed){
  motor1.setSpeed(m1_speed);
  motor2.setSpeed(m2_speed);
  motor3.setSpeed(m3_speed);
  motor4.setSpeed(m4_speed);
}


// moving all wheels in forward direction
void forward(){
  set_motorSpeed(normal_speed, normal_speed, normal_speed, normal_speed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


//moving all wheels in backward direction
void backward(){
  set_motorSpeed(normal_speed, normal_speed, normal_speed, normal_speed);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
}


// moving right side wheels forward 
// and left side wheels backwards
void turn_left(){
  set_motorSpeed(slow_speed, slow_speed, high_speed, high_speed);
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


// moving left side wheels forward 
// and right side wheels backwards
void turn_right(){
  set_motorSpeed(high_speed, high_speed, slow_speed, slow_speed);
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}


// stoping motor
void stop_motor(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
