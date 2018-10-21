/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Assignment E2 Integrated Builds part B: Doorbell
 * 
 * Sources: 
 *   UW buzzing Demo
 *   https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
 *****************************************/
 
 #include <Button.h>

const int ledPin = LED_BUILTIN; // substitute 13 if using an old version of Arduino
const int buttPin = 4;
const int buzzPin = 8;

Button butt (buttPin);

boolean buzzing = false;
int milliseconds = 0;

void setup()
{
  // housekeeping
  Serial.begin(9600);
  Serial.println("starting button demo");
  pinMode(ledPin, OUTPUT);
}

/*
 * Funny story here: I had mispelled milliseconds in the argument spec,
 * using one l isntead of two.  So when I tried pressing the buttion, the 
 * delay was always zero, and I never got a tone.
 */
void playTune (int milliseconds){
  // buzzing = true;
  digitalWrite(ledPin, HIGH);
  tone (buzzPin, 400, milliseconds);  
  Serial.println("buzz...");
  
  delay(milliseconds);
  
  digitalWrite(ledPin, LOW);
  noTone(buzzPin);
  Serial.println("...off");
}


void loop()
{
  
  int action = butt.checkButtonAction();

  // if clicked, start the tone
  if (action == Button::CLICKED) {
    Serial.println("on");

  }
  // if held, stop the tone
  if (action == Button::HELD_CLICKED) {
    Serial.println("off");
  }
 
 // if (action == Button::PRESSED) {
 
 /*   
  if (action == Button::HELD_CLICKED) {
    Serial.println("pressed");
    playTune(1000);
  } 
  */
}
