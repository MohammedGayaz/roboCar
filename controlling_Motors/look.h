/*
 * Controlling Servo
 * The shield brings out the 16-bit PWM output 
 * pins D9 and D10 to two 3-pin headers, 
 * D10 is connected to Servo 1, 
 * D9 is connected to Servo 2
*/


int scan(){
  // sweeps from 0 degrees to 180 degrees
  for(pos = 0; pos <= 180; pos += 1) 
  {
    myservo.write(pos);
    delay(10);
  }
  // sweeps from 180 degrees to 0 degrees
  for(pos = 180; pos>=0; pos-=1)
  {
    myservo.write(pos);
    delay(10);
  }
}
