
#include <Servo.h>
Servo pion; 
Servo poziom;

int czujnik =11;
int val = 0;
void setup() {
pion.attach(8);
poziom.attach(9); 
pinMode(11, INPUT);
pinMode(10, OUTPUT);   
Serial.begin(9600);
}

void zmienPozycje(Servo &myServo, int nowaPozycja) {
  int predkosc = random(10,20);
  int pozycja = myServo.read();
  if(pozycja < nowaPozycja) { 
    for (int i=pozycja; i < nowaPozycja; i++) {
      myServo.write(i);
      delay(predkosc); 
    }
  } else { 
    for (int i=pozycja; i > nowaPozycja; i--) { 
      myServo.write(i);
      delay(predkosc);
    }
  }
}


void loop() {
 
digitalRead(czujnik);
val=digitalRead(czujnik);
 
Serial.println(val);
 
if (digitalRead(czujnik)==1){
for (int a=0; a<10; a++)
{
  digitalWrite(10, HIGH);
  int pozycja = random(0,180);
  zmienPozycje(pion, pozycja);
  pozycja = random(0,180);
  zmienPozycje(poziom, pozycja);
  delay(300);
  Serial.println (pozycja);
  
}}
 
else {
    digitalWrite(10, LOW);
    
}
 
delay(300);
}
