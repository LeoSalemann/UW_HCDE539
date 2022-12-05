// ButtonLibHCDE - Version: Latest 
#include <ButtonLibHCDE.h>

// Button3Demo

/*
	Example of how to use the ButtonLib library for a flexible, high-level
	interface to hardware buttons.
	-- Andy Davidson
	-- adavid7@uw.edu

	This program is an extension of the simpler ButtonDemo example in this package.
	See that for the description of how it works. This example extends that one to
	use 3 instantiations of the Button object, each with a different configuration.

	Open the Serial Monitor window to see debugging trace messages.
*/

// import the ButtonLib
#include "ButtonLibHCDE.h"

// define pin number for LEDs and buttons
const int led1Pin = 13;
const int led2Pin = 12;
const int led3Pin = 11;

const int btn1Pin = 2;
const int btn2Pin = 3;
const int btn3Pin = 4;

// declare a button that is connected using a breadboard pull-down resistor
Button butt1 (btn1Pin);
// declare a button using the internal pull-up resistor
Button butt2 (btn2Pin, INPUT_PULLUP);
// declare a button using the internal pull-up resistor, and over-ride the default hold time
Button butt3 (btn3Pin, INPUT_PULLUP, 2000);


void setup()
{
  // housekeeping
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.println("starting button3 demo");

  // configure the LED pins
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop()
{

  // first we check the status of all three buttons
  int action1 = butt1.checkButtonAction();
  int action2 = butt2.checkButtonAction();
  int action3 = butt3.checkButtonAction();

  // decide what to do if button #1 had any action
  if (action1 == Button::CLICKED) {
    // do CLICKED action -- turn on the LED
    Serial.println("butt1 clicked");
    digitalWrite(led1Pin, HIGH);
  } else if (action1 == Button::HELD_CLICKED) {
    // do HELD-CLICKED action -- turn off the LED
    Serial.println("butt1 held-clicked");
    digitalWrite(led1Pin, LOW);
  } else {
    // nothing happened with the button, so do nothing
  }

  // decide what to do if button #2 had any action
  if (action2 == Button::CLICKED) {
    // do CLICKED action -- turn on the LED
    Serial.println("butt2 clicked");
    digitalWrite(led2Pin, HIGH);
  } else if (action2 == Button::HELD_CLICKED) {
    // do HELD-CLICKED action -- turn off the LED
    Serial.println("butt2 held-clicked");
    digitalWrite(led2Pin, LOW);
  } else {
    // nothing happened with the button, so do nothing
  }

  // decide what to do if button #3 had any action
  if (action3 == Button::CLICKED) {
    // do CLICKED action -- turn on the LED
    Serial.println("butt3 clicked");
    digitalWrite(led3Pin, HIGH);
  } else if (action3 == Button::HELD_CLICKED) {
    // do HELD-CLICKED action -- turn off the LED
    Serial.println("butt3 held-clicked");
    digitalWrite(led3Pin, LOW);
  } else {
    // nothing happened with the button, so do nothing
  }

}
