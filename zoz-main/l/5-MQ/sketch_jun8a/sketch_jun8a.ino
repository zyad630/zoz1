#define MQ A0
#define led 5
void setup() {
  Serial.begin(9600);
  pinMode(MQ,INPUT);
  pinMode(led,OUTPUT);


}

void loop() {
  int readping = analogRead(MQ);;
  Serial.println(readping);
 if(readping>290){
  digitalWrite(led,1);
 }
 else{
  digitalWrite(led,0);
 }
}
