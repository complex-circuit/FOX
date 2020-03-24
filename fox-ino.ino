#define a 260
#define b 330
#define c 395
int t=1;

int count=0;
int counts=0;
boolean countlots=LOW;
void activated(){if(!countlots){
  count++;if(count==10){count=0;counts++;}if(counts==10){counts=0;countlots=HIGH;}}}

  void morsenumber(int n){if(n!=0){int B=5;if(n>5){n=n-5;
while(n){n--;B--;dah();}
while(B){B--;dit();}
}else{
while(n){n--;B--;dit();}
while(B){B--;dah();}
}}else{dah();dah();dah();dah();dah();}space();}

void beep(int timeofbeep){
tone(8,500);delay(timeofbeep);
tone(8,32766);
delay(50*t);}
void dah(){beep(150*t);}
void dit(){beep(50*t);}
void space(){delay(150*t);}

void endtransmittion(){int x=0;space();t=1;
dit();dit();dah();dit();space();//          F
dah();dah();dah();space();//                O
dah();dit();dit();dah();space();//          X
space();space();
while(x!=4){dit();x++;}x=0;space();//       H
while(x!=2){dit();x++;}x=0;dah();space();// U
dah();dit();space();//                      N
dah();//                                    T
while(x!=4){space();x++;}x=0;
dah();dit();dah();space();//                K
dah();dit();dah();dit();space();//          C
dit();dit();dit();dah();dah();space();//    3
dit();dah();dah();dah();space();//          J
dah();dit();dit();dit();space();//          B
dah();dit();dah();dah();//                  Y
noTone(8);delay(1000);activated();
digitalWrite(10,LOW);}

void setup(){pinMode(10,OUTPUT);digitalWrite(10,LOW);pinMode(8,OUTPUT);pinMode(4,INPUT);pinMode(5,INPUT);pinMode(6,INPUT);pinMode(7,INPUT);pinMode(9,INPUT);}
void transmit(){digitalWrite(10,HIGH);int x=0;
while(x!=10){tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);tone(8,32766);x++;}
x=0;
endtransmittion();}

void sendcount(){t=2;digitalWrite(10,HIGH);int x=0;tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);
tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);tone(8,32766);delay(1000);
  dit();dit();dah();dit();space();//    f
  dah();dah();dah();space();//          o
  dah();dit();dit();dah();space();//    x
  space();space();
  dit();dah();space();//                a
  dah();dit();dah();dit();space();//    c
  dah();space();//                      t
  dit();dit();space();//                i
  dit();dit();dit();dah();space();//    v
  dit();dah();space();//                a
  dah();space();//                      t
  dit();space();//                      e
  dah();dit();dit();space();//          d
  while(x!=2){space();x++;}x=0;
  if(countlots){
    dah();dah();space();/*m*/dit();dah();space();/*a*/dah();dit();space();/*n*/dah();dit();dah();dah();space();/*y*/}else{
    if(counts!=0){morsenumber(counts);}morsenumber(count);}space();
  dah();space();//                      t
  dit();dit();space();//                i
  dah();dah();space();//                m
  dit();space();//                      e
  if(counts!=0 || count!=1){dit();dit();dit();space();}//          s
  while(x!=3){dit();dah();x++;}x=0;//   .
  space();space();
  endtransmittion();}

void loop(){
  if(digitalRead(4)&&digitalRead(5)&&!digitalRead(6)&&!digitalRead(7)&&!digitalRead(9)){transmit();}
  if(digitalRead(4)&&!digitalRead(5)&&digitalRead(6)&&digitalRead(7)&&!digitalRead(9)){sendcount();}
}
