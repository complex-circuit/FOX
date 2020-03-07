#define a 260
#define b 330
#define c 395
void beep(int timeofbeep){
tone(8,500);delay(timeofbeep);
noTone(8);
delay(50);}
void dah(){beep(150);}
void dit(){beep(50);}
void space(){delay(150);}
void setup(){int x=0;pinMode(8,OUTPUT);pinMode(4,INPUT);pinMode(5,INPUT);
while(x!=10){tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);noTone(8);x++;}
x=0;
space();
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

}
void loop(){if(digitalRead(4)&&digitalRead(5)){setup();}}
