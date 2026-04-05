const int redPed = 10;
const int greenPed = 9;

const int red = 13;
const int yellow = 12;
const int green = 11;

const int push1 = 3;
const int push2 = 2;

volatile bool trigger = false;

void setup()
{
  pinMode(redPed, OUTPUT);
  pinMode(greenPed, OUTPUT);
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  pinMode(push1, INPUT_PULLUP);
  pinMode(push2, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(push1),pushbtn, FALLING);
  attachInterrupt(digitalPinToInterrupt(push2),pushbtn, FALLING);
  
  kondisiAwal();
}

void loop()
{
  if(trigger){
    trigger = false;
    
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    
    digitalWrite(redPed,LOW);
    digitalWrite(greenPed,HIGH);
    
    delay(5000);
    
    digitalWrite(greenPed,LOW);
    digitalWrite(redPed,HIGH);
    
   
    digitalWrite(red,LOW);
    for (int i=0;i<3;i++){
      digitalWrite(yellow,HIGH);
      delay(500);
      digitalWrite(yellow,LOW);
      delay(500);
    }
    kondisiAwal();
  }
}

void pushbtn(){
  trigger = true;
}

void kondisiAwal(){
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,HIGH);
  
  digitalWrite(redPed,HIGH);
  digitalWrite(greenPed,LOW);
}