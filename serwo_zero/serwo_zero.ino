#include <Servo.h>
Servo pion;
Servo poziom;

int czujnik = 11;
int val = 0;


void setup()
{
  pion.attach(8);
  poziom.attach(9);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  pion.write(120);
  poziom.write(90);
}


void loop() {

  digitalRead(czujnik);
  val = digitalRead(czujnik);
  Serial.println(val);
  delay (10000);

  if (digitalRead(czujnik) == 1)
  {
    for (int a = 0; a < 50; a++)
    {
      int predkosc = random(15, 30);
      int pion_pozycja = pion.read();
      int poziom_pozycja = poziom.read();
      digitalWrite(10, HIGH);
      int pion_random = random(50, 120);
      delay(100);
      if (pion_pozycja < pion_random)
      {
        for (int b = pion_pozycja; b < pion_random; b++)
        {
          pion.write(b);
          delay(predkosc);
          Serial.println(b);
        }
      }
      else
      {
        for (int b = pion_pozycja; b > pion_random; b--)
        {
          pion.write(b);
          delay(predkosc);
          Serial.println(b);
        }
      }
      int  poziom_random = random(35, 150);
      delay(100);
      if (poziom_pozycja < poziom_random)
      {
        for (int b = poziom_pozycja; b < poziom_random; b++)
        {
          poziom.write(b);
          delay(predkosc);
          Serial.println(b);
        }
      }
      else
      {
        for (int b = poziom_pozycja; b > poziom_random; b--)
        {
          poziom.write(b);
          delay(predkosc);
          Serial.println(b);
        }
      }
      delay(200);
      Serial.println (pion_random);
      Serial.println (poziom_random);
    }
  }

  else {
    digitalWrite(10, LOW);
    pion.write(120);
    poziom.write(90);
  }

  delay(1000);
}
