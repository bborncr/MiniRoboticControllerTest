/* Example code for the Mini Driver Board
 
 Select Board Type "Arduino NG or older w/ ATMEGA8"
 Use the USB drivers found at CRCibernetica.com for this board
 
 Basic operation:
 Set the direction pin to Forward (HIGH) or Reverse (LOW)
 Then set the speed pin using analogWrite(0-255)
 
 The example below creates functions for forward, reverse, rotate right and left, 
 and stop.  The variable for each function is the speed of the movement from 0 to 255.
 Once the command is given the motors will execute the command until told
 to do otherwise.
 
 */

#define left_direction 7
#define left_speed 9
#define right_direction 8
#define right_speed 10

void setup(){

  pinMode(left_direction, OUTPUT);
  pinMode(right_direction, OUTPUT);
  pinMode(left_speed, OUTPUT);
  pinMode(right_speed, OUTPUT);
  
  motorStop();

}
void loop(){
  forward(200);
  delay(2000);
  motorStop();
  delay(500);
  left_rotate(200);
  delay(1500);
  motorStop();
  delay(500);
  right_rotate(200);
  delay(1500);
  motorStop();
  delay(500);
  reverse(200);
  delay(2000);
  motorStop();
  delay(500);
}

void forward(int speed){
  digitalWrite(left_direction, HIGH);
  digitalWrite(right_direction, HIGH);
  analogWrite(left_speed, speed);
  analogWrite(right_speed, speed);
}
void reverse(int speed){
  digitalWrite(left_direction, LOW);
  digitalWrite(right_direction, LOW);
  analogWrite(left_speed, speed);
  analogWrite(right_speed, speed);
}
void left_rotate(int speed){
  digitalWrite(left_direction, LOW);
  digitalWrite(right_direction, HIGH);
  analogWrite(left_speed, speed);
  analogWrite(right_speed, speed);
}
void right_rotate(int speed){
  digitalWrite(left_direction, HIGH);
  digitalWrite(right_direction, LOW);
  analogWrite(left_speed, speed);
  analogWrite(right_speed, speed);
}
void motorStop(){
  digitalWrite(left_direction, HIGH);
  digitalWrite(right_direction, HIGH);
  analogWrite(left_speed, 0);
  analogWrite(right_speed, 0);
}



