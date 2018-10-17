#include <Button.h>

const int ledPin = LED_BUILTIN; // substitute 13 if using an old version of Arduino
const int buttPin = 4;
const int buzzPin = 2;

Button butt (buttPin);

boolean buzzing = false;

void setup()
{
  // housekeeping
  Serial.begin(9600);
  Serial.println("starting button demo");
  pinMode(ledPin, OUTPUT);
}


void loop()
{

  int action = butt.checkButtonAction();
  if (action == Button::PRESSED) {
    Serial.println("pressed");
    buzzing = ! buzzing;
    Serial.println(buzzing);
  }

 // Serial.println(buzzing);
  if (buzzing) {
    digitalWrite(ledPin, HIGH);
    tone (buzzPin, 400, 100);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzPin);
  }

}



