int fan=2;
char rec;
void setup() {
Serial.begin(9600);
pinMode(fan.OUTPUT);
pinMode(rec.INPUT);
}

void loop() {
if (Serial.available() >0){
  rec=Serial.read();
  if(rec>0){
    digigtalWrite(fan,1);
  }
  else{
    digitalWrite(fan,0);
  }
}
Serail.println(rec);
delay(200);
}
