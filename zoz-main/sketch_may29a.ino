#include<AFMotor.h>
#define right A0
#define left A1
AF_DCMotor motor1(1 , MOTOR12_1KHZ);
AF_DCMotor motor2(2 , MOTOR12_1KHZ);
AF_DCMotor motor3(3 , MOTOR12_1KHZ);
AF_DCMotor motor4(4 , MOTOR12_1KHZ);
void setup() {
pinMode(right , INPUT);
pinMode(left , INPUT);
Serial.begin(9600);
}
void loop(){
Serial.println(digitalRead(left));
Serial.println(digitalRead(right));
if(digitalRead(left)==0 && digitalRead(right)==0){
  motor1.run(FORWARD);
  motor1.setSpeed(150);
  motor2.run(FORWARD);
  motor2.setSpeed(150);
  motor3.run(FORWARD);
  motor3.setSpeed(150);
  motor4.run(FORWARD);
  motor4.setSpeed(150);
}
if(digitalRead(left)==0 && !analogRead(right)==0){
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  motor2.run(FORWARD);
  motor2.setSpeed(200);
  motor3.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.run(BACKWARD);
  motor4.setSpeed(200);
}
if(!digitalRead(left)==0 && digitalRead(right)==0){
  motor1.run(BACKWARD);
  motor1.setSpeed(200);
  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  motor3.run(FORWARD);
  motor3.setSpeed(200);
  motor4.run(FORWARD);
  motor4.setSpeed(200);
}
if(!digitalRead(left)==0 && !digitalRead(right)==0){
  motor1.run(RELEASE);
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor3.run(RELEASE);
  motor3.setSpeed(0);
  motor4.run(RELEASE);
  motor4.setSpeed(0);
}
}
