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

const int n_s = 125; // normal movement
const int h_s = 255; // max speed
const int l_s = 80; // slow speed





// port m1, m2 are connected to back wheels
// port m3, m4 are connected to front wheels
void forward(){
  motor1.setSpeed(l_s);
  motor1.run(FORWARD);

  motor2.setSpeed(l_s);
  motor2.run(FORWARD);

  motor3.setSpeed(l_s);
  motor3.run(FORWARD);

  motor4.setSpeed(l_s);
  motor4.run(FORWARD);
}


void backward(){
  motor1.setSpeed(l_s);
  motor1.run(BACKWARD);
  
  motor2.setSpeed(l_s);
  motor2.run(BACKWARD);

  motor3.setSpeed(l_s);
  motor3.run(BACKWARD);

  motor4.setSpeed(l_s);
  motor4.run(BACKWARD); 
}


// moving only back wheels for stablity
// right wheel forward left wheels backward
void turn_right(){
  motor1.setSpeed(h_s);
  motor1.run(FORWARD);

  motor2.setSpeed(h_s);
  motor2.run(BACKWARD);

  motor3.setSpeed(l_s);
  motor3.run(BACKWARD);

  motor4.setSpeed(l_s);
  motor4.run(FORWARD);
}


// left wheel forward right wheel backward
void turn_left(){
  motor1.setSpeed(h_s);
  motor1.run(BACKWARD);
  motor2.setSpeed(h_s);
  motor2.run(FORWARD);

  motor3.setSpeed(l_s);
  motor3.run(FORWARD);
  motor4.setSpeed(l_s);
  motor4.run(BACKWARD);
}


void stop_motor(){
  motor1.setSpeed(125);
  motor1.run(RELEASE);

  motor2.setSpeed(125);
  motor2.run(RELEASE);

  motor3.setSpeed(125);
  motor3.run(RELEASE);

  motor4.setSpeed(125);
  motor4.run(RELEASE);
}
