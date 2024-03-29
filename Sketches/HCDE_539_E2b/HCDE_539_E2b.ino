/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Assignment E2 Integrated Builds part B: Dimmer switch
 * 
 * Sources: 
 *   Tinkercad stae change detection demo
 *   http://www.arduino.cc/en/Tutorial/ButtonStateChange
 *
 *   Arduino tone() function
 *   https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
 *
 *   Adafruit Piezzo Buzzer docs
 *   https://www.adafruit.com/product/160
 *****************************************/
 
/*

  State change detection (edge detection)

  Often, you don't need to know the state of a
  digital input all the time,  but you just need
  to know when the input changes from one state to
  another.  For example, you want to know when a
  button goes from OFF to ON.  This is called
  state change detection, or edge detection.

  This example shows how to detect when a button
  or button changes from off to on  and on to off.


  The circuit:
  * pushbutton attached to pin 2 from +5V
  * 10K resistor attached to pin 2 from ground
  * LED attached from pin 13 to ground (or use the
  built-in LED on  most Arduino boards)

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

int buttonState = 0;

int lastButtonState = 0;

int buttonPushCounter = 0;

int pinButton = 4;
int pinBuzzer = 8;

bool firstTime = true;

void setup()
{
  pinMode(pinButton, INPUT);
  Serial.begin(9600);

  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  // read the pushbutton input pin
  buttonState = digitalRead(pinButton);
  
  // Leo's hack
  if (firstTime) {
  	// buttonState = LOW;
    Serial.println("first time: off");
    noTone(pinBuzzer);  
  }
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    firstTime = false;
    
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter += 1;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      tone(pinBuzzer, 400);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
      noTone(pinBuzzer);
    }
    // delay a little bit to avoid debouncing
    delay(5); // Wait for 5 millisecond(s)
  }
  
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState = buttonState;

}