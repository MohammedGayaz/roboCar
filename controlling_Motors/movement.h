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

/*
 * setSpeed(speed) controls the motor speed.
 * speed ranges form 0 -> 255
 * run(cmd) controls the motor spinning direciton
 * FORWARD   - spins forward direction
 * BACKWARD  - spins backward direction
 * RELEASE   - stops motor 
*/

const int n_s = 150; // normal movement
const int h_s = 255; // max speed
const int l_s = 100; // slow speed


void set_motorSpeed(int *mspeed){
  motor1.setSpeed(mspeed[0]);
  motor2.setSpeed(mspeed[1]);
  motor3.setSpeed(mspeed[2]);
  motor4.setSpeed(mspeed[3]);
}


// port m1, m2 are connected to back wheels
// port m3, m4 are connected to front wheels
void forward(){
  int fun_speed[] = {n_s, n_s, n_s, n_s};
  set_motorSpeed(fun_speed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void backward(){
   int fun_speed[] = {n_s, n_s, n_s, n_s};
  set_motorSpeed(fun_speed);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
}


// moving only back wheels for stablity
// right wheel forward left wheels backward
void turn_right(){
  int fun_speed[] = {l_s, l_s, 0, 0};
  set_motorSpeed(fun_speed);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


// left wheel forward right wheel backward
void turn_left(){
  int fun_speed[] = {l_s, l_s, 0, 0};
  set_motorSpeed(fun_speed);
  
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void stop_motor(){
  int fun_speed[] = {0, 0, 0, 0};
  set_motorSpeed(fun_speed);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
