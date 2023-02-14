/*
 * IR Sensor
 * it has three pins 
 * vcc -> take 5V as input
 * GND -> is connected to groung
 * OUT -> if light reflected 
 *        then HIGH
 *        else LOW
*/

const int left_sensor = A5;
const int right_sensor = A0;


/*
 * return 1 if line on right
 * return 2 if line on left
 * return 0 if reached goal
 * return -1 if line not detected
*/
int detect_line(){
  int left_val = digitalRead(left_sensor);
  int right_val = digitalRead(right_sensor);
  
  if(left_val == 1 && right_val == 0){
    return 1;
  }
  else if(right_val == 1 && left_val == 0){
    return 2;
  }
  else if(right_val == 0 && left_val == 0){
    return 0;
  }
  return -1;
}
