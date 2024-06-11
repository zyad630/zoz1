#include <Servo.h>
#define in1 2  
#define in2 3  
#define in3 4  
#define in4 7  

Servo myservo;  
int pos = 0;    
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance,Cdistance,Rdistance,Ldistance;
void setup() 
{
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  myservo.attach(9);  
  myservo.write(85);  
}

void loop()
{
  Cdistance=ultrasonic();
  if(Cdistance>30)
  {
    forward();
  }else 
  {
    if(Cdistance<=10&&Cdistance>2)reverse();
    off();                   
    myservo.write(35);      
    delay(300);
    Rdistance=ultrasonic();  
    myservo.write(135);      
    delay(300);
    Ldistance=ultrasonic();  
    myservo.write(85);       
    delay(300);
    comparison(Rdistance, Ldistance); 
    off();                    
    delay(150);
  }
  Rdistance=0;
  Ldistance=0;
  Cdistance=0;
}

int ultrasonic(void)
{
  distance=0;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
return distance;
}

void comparison(int r, int l)
{
  if(r>25||l>25)
  {
   if(r>l||r==l)
   {
     Tright90();
   }else if(l>r)
   {
     Tleft90();
   }
  }
}
void forward()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void off()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void Tleft90()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(650);
}
void Tright90()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(750);  
}

void reverse()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(450);
}




