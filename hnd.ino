#include <Servo.h>
#define numOfValsRec 5     // количество цифр принимаемых
#define digitsPerValRec 1  // количество переменных? от 0

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int valsRec[numOfValsRec];
int stringLength = numOfValsRec * digitsPerValRec + 1;  //$00000
int counter = 0;
bool counterStart = false;
String recievedString;

void setup() {
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
}

void recieveData() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '$') {
      counterStart = true;
    }
    if (counterStart) {
      if (counter < stringLength) {
        recievedString = String(recievedString + c);
        counter++;
      }
      if (counter >= stringLength) {  //$00000
        for (int i = 0; i < numOfValsRec; i++) {
          int num = (i * digitsPerValRec) + 1;
          valsRec[i] = recievedString.substring(num, num + digitsPerValRec).toInt();
        }
        recievedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}

void loop() {
  recieveData();
  if (valsRec[0] == 0){servo1.write(180);}else{servo1.write(0);}
  if (valsRec[1] == 0){servo2.write(180);}else{servo2.write(0);}
  if (valsRec[2] == 0){servo3.write(180);}else{servo3.write(0);}
  if (valsRec[3] == 0){servo4.write(180);}else{servo4.write(0);}
  if (valsRec[4] == 1){servo5.write(180);}else{servo5.write(0);}
}
