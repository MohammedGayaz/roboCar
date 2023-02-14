/*
 * IR Sensor
 * it has three pins 
 * vcc -> take 5V as input
 * GND -> is connected to groung
 * OUT -> if light reflected 
 *        then HIGH
 *        else LOW
*/

const int l_s = A0;
const int r_s = A5;


/*
 * return 1 if line on left
 * return 2 if line on right
 * return 0 if reached goal
 * return -1 if line not detected
*/
int detect_line(){
  if(l_s == 1 && r_s == 0){
    return 1;
  }
  else if(r_s == 1 && l_s == 0){
    return 2;
  }
  else if(r_s == 0 && l_s == 0{
    return 0;
  }
  return -1;
}
