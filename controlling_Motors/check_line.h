/*
 * IR Sensor
 * it has three pins 
 * vcc -> take 5V as input
 * GND -> is connected to groung
 * OUT -> if light reflected 
 *        then HIGH
 *        else LOW
*/

const int R_S = A0;
const int L_S = A1;


/*
 * return 0 if line on forward
 * return 1 if line on right
 * return 2 if reached left
 * return -1 if line not detected
*/
int detect_line(){
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){return 0;}
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){return 1;}
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){return 2;}
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){return -1;} 
}
