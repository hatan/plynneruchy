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
      int onerandom = random(50, 120);
      delay(100);
      if ((pion_pozycja < onerandom) && (poziom_pozycja < onerandom))
      {
        for (int b = pion_pozycja;  b < onerandom; b++)
        {
          pion.write(b);
          Serial.println(b);
          poziom.write(poziom_pozycja);
          delay(predkosc);
          Serial.println(poziom_pozycja);
          poziom_pozycja++;

        }
      }
      else if ((pion_pozycja > onerandom) && (poziom_pozycja < onerandom))
      {
        for (int b = pion_pozycja; b > onerandom; b--)
        {
          pion.write(b);
          Serial.println(b);
          poziom.write(poziom_pozycja);
          delay(predkosc);
          Serial.println(poziom_pozycja);
          poziom_pozycja++;
        }
      }
      else if ((poziom_pozycja > onerandom) && (pion_pozycja > onerandom))
      {
        for (int c = poziom_pozycja; c > onerandom; c--)
        {
          poziom.write(c);
          Serial.println(c);
          pion.write(pion_pozycja);
          delay(predkosc);
          Serial.println(pion_pozycja);
          pion_pozycja--;

        }
      }
      else if ((pion_pozycja < onerandom) && (poziom_pozycja > onerandom))
      {
        for (int b = poziom_pozycja; b > onerandom; b++)
        {
          pion.write(pion_pozycja);
          Serial.println(pion_pozycja);
          poziom.write(b);
          delay(predkosc);
          Serial.println(b);
          pion_pozycja++;
        }
      }
      delay(200);
      Serial.println (onerandom);
    }
  }

  else {
    digitalWrite(10, LOW);
    pion.write(120);
    poziom.write(90);
  }

  delay(1000);
}
