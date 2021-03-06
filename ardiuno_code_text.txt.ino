/*
4 wheel drive
using breadboard to use 1 l298 to control 4 motors
using 5 led pins*/

int c=14;/*variable to control flow to the autonomous part*/
int counter=0;/*variable to count number off squares*/
int ledblue=12;
int ledred=13;
int m1=2;
int m2=4;
int m3=8;
int m4=7;
int ena=10;
int enb=11;
void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  }
void loop() {
  if (c==14){
      if(Serial.available()>0)
       {
           int b=Serial.read();
             switch(b){
                 case 'w':forward();break;
                 case 's':backward();break;
                 case 'a':left();break;
                 case 'd':right;break;
                 case't':c+=1;break;
     } }
      else{
        if(Serial.available()>0){
           int b1=Serial.read();/*to switch fro autonomous to manual in case player by mistake switched to autonomous zone in manual zone*/
            if(b1=='t')
                c==14;
            else{
                ledBlue();
                autonomous();
            }
      }
  }}}
  
 void forward(){
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);}
  void backward(){
  digitalWrite(m2,HIGH);
  digitalWrite(m1,LOW);
  digitalWrite(m4,HIGH);
  digitalWrite(m3,LOW);}
  void left(){
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m4,HIGH);
  digitalWrite(m3,LOW);}
  void right(){
  digitalWrite(m2,HIGH);
  digitalWrite(m1,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
  }
  void autonomous()
  {
    int a0=analogRead(A0);
    int a1=analogRead(A1);
    int a2=analogRead(A2);
    int a3=analogRead(A3);
    int a4=analogRead(A4);
    if(a2<300)
        {
          if(a1<300&&a0<300&&a3<300&&a4<300){
               counter=counter+1;
               forward();}
           else
               {
                forward();
               }
        }
     if(a2>700)
         {
          if(a0>700&&a1>700&&a3<300&&a4<300)
              {
                analogWrite(ena,127);
                analogWrite(enb,127);
                right();
              }
          else if(a3>700&&a4>700&&a0<300&a1<300  )
              {
                analogWrite(ena,127);
                analogWrite(enb,127);
                left();
              }
           else if(a0>700&&a1<300&&a3<300&&a4<300)
               {
                ledRed();
               }
         }}
void ledBlue()
{
  digitalWrite(ledblue,HIGH);
  delay(1000);
  digitalWrite(ledblue,LOW);
 }
 void ledRed(){
   digitalWrite(ledred,HIGH);
   delay(1000);
    digitalWrite(ledred,LOW);
}
