#include <Servo.h>
const int buttonPin = 5;
int randomNumber;
int buttonState = 0;
Servo first;
Servo secnd;
Servo thrd;
Servo fourth;
Servo fifth;
void setup() {
  Serial.begin(9600); //желательно убрать к финалу или оставить чтобы делать с пк
  first.attach(0); //указательный
  secnd.attach(1); //средний
  thrd.attach(2); //безымянный
  fourth.attach(3); //мизинец
  fifth.attach(4); //большой 
  pinMode(5, OUTPUT) //кистевая часть
  pinMode(6, OUTPUT) // локтевая часть
  pinMode(7, OUTPUT) //плечевая часть
  pinMode(8, OUTPUT) //свободный пин для руки выход
  pinMode(9, INPUT) //свободный пин для руки вход
  pinMode(buttonPin, INPUT); //кнопка (надо заменить на блютуз интерфейс)
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) { //игра в камень-ножницы-бумага 
    randomNumber=random(1,3);
      if (randomNumber == 1) { //камень
        first.write(180);
        secnd.write(180);
        thrd.write(180);
        fourth.write(180);
        fifth.write(180);
        delay(5000);
      }
       if (randomNumber == 2) { //ножницы
        first.write(180);
        secnd.write(180);
        thrd.write(0);
        fourth.write(0);
        fifth.write(0);
        delay(5000);
      }
      else { //бумага
        first.write(0);
        secnd.write(0);
        thrd.write(0);
        fourth.write(0);
        fifth.write(0);
        delay(5000);
      }
    first.write(0);
    secnd.write(0);
    thrd.write(0);
    fourth.write(0);
    fifth.write(0);
  }
  else {

  }


}
