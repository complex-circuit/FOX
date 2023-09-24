#define mycall "KC3JBY"//Replace this with your call sign.


#define a 261
#define b 330
#define c 392
//#define analogToVolt 10.000/1023
#define stq 4
#define q1 5
#define q2 6
#define q3 7
#define read_dtmf digitalRead(q1)+2*digitalRead(q2)+4*digitalRead(q3)+8*digitalRead(q4)
//skip pin 8, the audio out
#define q4 9
//pin 10 to ptt opto-isolator
//double volt=9;

int t=1;

unsigned long count=0;
boolean countLots=false;
void activated(){
  if(!countLots){
    count++;
    if(count==0){//a result of overflow
      countLots=true;
    }
  }

}

void morsenumber(unsigned long number){
  byte n=number%10;
  if(number>10){//to handle multiple digits, send the tens place before the ones.
    morsenumber(number/10);//This will also work for more digits.
  }
  
  //transmit the digit
  if(n!=0){
    byte B=5;
    if(n>5){n=n-5;
      while(n){n--;B--;dah();}
      while(B){B--;dit();}
    }else{
      while(n){n--;B--;dit();}
      while(B){B--;dah();}
    }
  }else{ dah();dah();dah();dah();dah(); }space();
}

void beep(int timeofbeep){
  tone(8,500);delay(timeofbeep);
  noTone(8);
  delay(50*t);
}
void dah(){beep(150*t);}//---------------------------------------
void dit(){beep(50*t);}//........................................
void space(){delay(150*t);}//           --space--



void morseChar(char ch){
  if(ch>='A'&&ch<='Z'){ch+='a'-'A';}//if ch is uppercase, turn it lowercase

  if(ch=='a'){dit();dah();}
  if(ch=='b'){dah();dit();dit();dit();}
  if(ch=='c'){dah();dit();dah();dit();}
  if(ch=='d'){dah();dit();dit();}
  if(ch=='e'){dit();}
  if(ch=='f'){dit();dit();dah();dit();}
  if(ch=='g'){dah();dah();dit();}
  if(ch=='h'){dit();dit();dit();dit();}
  if(ch=='i'){dit();dit();}
  if(ch=='j'){dit();dah();dah();dah();}
  if(ch=='k'){dah();dit();dah();}
  if(ch=='l'){dit();dah();dit();dit();}
  if(ch=='m'){dah();dah();}
  if(ch=='n'){dah();dit();}
  if(ch=='o'){dah();dah();dah();}
  if(ch=='p'){dit();dah();dah();dit();}
  if(ch=='q'){dah();dah();dit();dah();}
  if(ch=='r'){dit();dah();dit();}
  if(ch=='s'){dit();dit();dit();}
  if(ch=='t'){dah();}
  if(ch=='u'){dit();dit();dah();}
  if(ch=='v'){dit();dit();dit();dah();}
  if(ch=='w'){dit();dah();dah();}
  if(ch=='x'){dah();dit();dit();dah();}
  if(ch=='y'){dah();dit();dah();dah();}
  if(ch=='z'){dah();dah();dit();dit();}
  if(ch=='1'){dit();dah();dah();dah();dah();}
  if(ch=='2'){dit();dit();dah();dah();dah();}
  if(ch=='3'){dit();dit();dit();dah();dah();}
  if(ch=='4'){dit();dit();dit();dit();dah();}
  if(ch=='5'){dit();dit();dit();dit();dit();}
  if(ch=='6'){dah();dit();dit();dit();dit();}
  if(ch=='7'){dah();dah();dit();dit();dit();}
  if(ch=='8'){dah();dah();dah();dit();dit();}
  if(ch=='9'){dah();dah();dah();dah();dit();}
  if(ch=='0'){dah();dah();dah();dah();dah();}
  if(ch==' '){space();space();}
  if(ch=='@'){dit();dah();dah();dit();dah();dit();}
  if(ch=='.'){dit();dah();dit();dah();dit();dah();}
  if(ch=='?'){dit();dit();dah();dah();dit();dit();}
  if(ch==','){dah();dah();dit();dit();dah();dah();}
  space();
}void morseStr(String str){
  for(char ch:str){
    morseChar(ch);
  }
}





void endtransmittion(){int x=0;space();space();t=1;//return to normal speed in case slowed down
  morseStr("fox hunt");space();space();
  morseStr(mycall);
  noTone(8);delay(1000);
  activated();//count this activation
  digitalWrite(10,false);//switch to recive
}

void setup(){
  pinMode(10,OUTPUT);digitalWrite(10,false);//ptt switch
  pinMode(11,OUTPUT);digitalWrite(11,false);//voltage reader
  pinMode(8,OUTPUT);//sound input for the radio
  pinMode(stq,INPUT);//─────────────────┐
  pinMode(q1, INPUT);//───────────┐     │
  pinMode(q2, INPUT);//────FROM DTMF DECODER
  pinMode(q3, INPUT);//───────────┘     │
  pinMode(q4, INPUT);//─────────────────┘
}



void transmit(){digitalWrite(10,true);/*turn on the transmitter*/int x=0;
  while(x!=10){
    tone(8,a);delay(1000);
    tone(8,b);delay(1000);
    tone(8,c);delay(1000);
    x++;}noTone(8);
  x=0;
  endtransmittion();
}

void sendcount(){t=2;//send at half speed
  digitalWrite(10,true);//switch to transmit.
  int x=0;
  tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);
  tone(8,a);delay(1000);tone(8,b);delay(1000);tone(8,c);delay(1000);
  noTone(8);delay(1000);
  morseStr("fox activated ");

  if(countLots){// too many to count with unsigned long
    morseStr("many");
  }else{
    morsenumber(count);
  }
  morseStr(count==1?" time. ":" times. ");
  endtransmittion();//and remember this too counts as an activation.
}

void loop(){
  if(!digitalRead(stq)){return;}//No current DTMF tone

  if(read_dtmf==1){transmit();}//1
  if(read_dtmf==6){sendcount();}//6
   if(read_dtmf==5) {//5
    t=1;digitalWrite(10,true);delay(2000);
    morseStr("fox test ");
    morseStr(mycall);

    noTone(8);delay(1000);
    activated();//count this activation
    digitalWrite(10,false);//switch to recive
  }
}
