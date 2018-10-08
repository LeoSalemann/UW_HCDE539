/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Assignment E0 Traffic Light
 * 
 * Originally from Tinkercad > Getting Started > Editing Components
 * link: https://www.tinkercad.com/things/dTAcB2IUt0I-editing-components/editel?collectionid=OIYJ88OJ3OPN3EA&lessonid=EFU6PEHIXGFUR1J&projectid=OIYJ88OJ3OPN3EA#/lesson-viewer
 *****************************************/

/*
 * In TinkerCad, the pins are 0, 1, 2 but that causes an error:
 *   avrdude stk500_getsync() not in sync resp=0x30
 * After much googling, I found a solution that suggested to avoid using pin 0
 *   https://www.instructables.com/id/A-solution-to-avrdude-stk500getsync-not-in-syn/
 * Actually, my professor advised starting at pin 2.
 */
int led_red    = 4; // the red    LED is connected to Pin 4 of the Arduino
int led_yellow = 3; // the yellow LED is connected to Pin 3 of the Arduino
int led_green  = 2; // the green  LED is connected to Pin 2 of the Arduino

void setup() {
  // set up all the LEDs as OUTPUT
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
}

/*
 * Function stop()
 * Turns red LED on; the rest off.
 * Maintains state for stop_time seconds.
 */
void stop (int stop_time) {
  // turn the red LED on and the other LEDs off
  digitalWrite(led_red, HIGH);  
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
  delay(stop_time * 1000);  // wait stop_time seconds 
}

/*
 * Function caution()
 * Turns yellow LED on; the rest off.
 * Maintains state for caution_time seconds.
 */
void caution (int caution_time) {
  // turn the yellow LED on and the other LEDs off
  digitalWrite(led_red, LOW);   
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_green, LOW);
  delay(caution_time * 1000);   // wait caution_time seconds
}

/*
 * Function go()
 * Turns green LED on; the rest off.
 * Maintains state for go_time seconds.
 */
void go (int go_time) {
  // turn the green LED on and the other LEDs off
  digitalWrite(led_red, LOW); 
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, HIGH);
  delay(go_time * 1000);  // wait go_time seconds 
}


void loop() {
  go(2);
  caution(1);
  stop(10);
}
