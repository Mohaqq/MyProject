#include <Servo.h>
#include <NewPing.h>
#define led1 12 
#define led2 7 
#define tr 9
#define ech 8 
#define buzz 11
#define max_dis 100
int p=0;
NewPing sonar(tr,ech,max_dis);
Servo motor ;
void setup() {
Serial.begin(9600);
delay(50);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzz,OUTPUT);
motor.attach(5);
motor.write(180);
}

void loop() {
  for(p=0 ; p<180; p++){
    motor.write(p);
    delay(10);
  if(sonar.ping_cm() < 10 && sonar.ping_cm() > 0 ) {
  Serial.print("the distance is : " );
  Serial.println(sonar.ping_cm());
    digitalWrite(buzz , HIGH ) ;
    delay(500);
    digitalWrite(buzz,LOW ) ;
  }else  digitalWrite(buzz , LOW ) ;
  }
  
  for(p=180 ; p>=1; p--){
    motor.write(p);
    delay(10);
  if(sonar.ping_cm() < 10 && sonar.ping_cm()> 0) {
  Serial.print("the distance is : " );
  Serial.println(sonar.ping_cm());
    digitalWrite(buzz , HIGH ) ;
    delay(500);
    digitalWrite(buzz,LOW ) ;
  }else  digitalWrite(buzz , LOW ) ;

  }
  



}
