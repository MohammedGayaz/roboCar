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


const int init_speed = 200; // initial speed of motor

/*
 * setSpeed(speed) controls the motor speed.
 * speed ranges form 0 -> 255
 * run(cmd) controls the motor spinning direciton
 * FORWARD   - spins forward direction
 * BACKWARD  - spins backward direction
 * RELEASE   - stops motor 
*/

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(5000);
  stop_motor();
  backward();
  delay(5000);
  stop_motor();
}

void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void backward(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
}


void stop_motor(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
