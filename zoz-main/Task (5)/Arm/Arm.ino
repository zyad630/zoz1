#include <Servo.h>
Servo myservo1;  
Servo myservo2;  

int potpin1 = A0;  
int potpin2 = A1;  
 

void setup() {
  myservo1.attach(9); 
  myservo2.attach(10); 
}

void loop() {
  int val1 = analogRead(potpin1);            
  int val2 = analogRead(potpin2);            
  val1 = map(val1, 0, 1023, 0, 180);     
  val2 = map(val2, 0, 1023, 0, 180);     
  myservo1.write(val1);                  
  myservo2.write(val2);                  
  delay(150);                           
}

// زود عدد السيرفو زي ما انت عاوز
