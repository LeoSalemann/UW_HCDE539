/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Final Project - Arduino Model Flight Simulator
 * Servo Test harness
 * 
 * Based on TinkerCAD circuit "arduino servo motor avec potonsiometre" by user Ounis.Brahim
 * https://www.tinkercad.com/things/hrFMb9KYSrl-arduino-servo-motor-avec-potonsiometre-
 * accessed 11/17/18
*****************************************/

#include   <Servo.h>

Servo servo1;  
Servo servo2;
Servo servo3;

const int servo1Pin = 2;
const int servo2Pin = 3;
const int servo3Pin = 4;

const int pot1 = 0;
const int pot2 = 1;
const int pot3 = 2;

int potValue1;
int potValue2;
int potValue3;

void setup() {
  
servo1.attach(servo1Pin);
servo2.attach(servo2Pin);
//servo3.attach(servo3Pin);
  
}
void loop() {
  
 potValue1 = analogRead (pot1);
 potValue1 = map(potValue1, 0, 1023, 0, 180);
 servo1.write(potValue1);
  
 potValue2 = analogRead (pot2);
 potValue2 = map(potValue2, 0, 1023, 0, 180);
 servo2.write(potValue2);

// potValue3 = analogRead (pot3);
// potValue3 = map(potValue3, 0, 1023, 0, 180);
// servo3.write(potValue3);

}
