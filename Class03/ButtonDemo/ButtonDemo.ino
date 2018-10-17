// ButtonDemo

/*
	Example of how to use the ButtonLib library for a flexible, high-level
	interface to hardware buttons.
	-- Andy Davidson
	-- adavid7@uw.edu

	A button is connected to a digital input pin. The library suports
	either a normal button connection with a pull-down resistor, as here:
		1) arduino.cc/en/Tutorial/Button
	or the use of the Arduino's internal pull-up resistor as here:
		2) arduino.cc/en/Tutorial/InputPullupSerial

	In either case, the library handles all of the logic for detecting
	when the button has been pressed and released, and just informing the
	client program (this example) of button state changes.

	For the complete functionality, see Button.h of the ButtonLib package.
	To see the gory details of the ButtonLib's "black box" implementation,
	see Button.cpp of the ButtonLib package.

	This example simply turns on the built-in LED on pin 13 when the
	button is clicked (pressed and released quickly), and turns it off
	when the button is pressed and held for for more than 1 second, then released.

	The latter action is called "hold clicking." The default value of
	1 second may be over-ridden by a parameter in the button declaration.

	Open the Serial Monitor window to see debugging trace messages.
*/

// import the ButtonLib
#include <Button.h>

// define pin number for an LED as an indicator and the pin for the button
const int ledPin = LED_BUILTIN; // substitute 13 if using an old version of Arduino
const int btnPin = 2;

// declare a button that is connected on btnPin using a breadboard pull-down resistor
Button butt (btnPin);

/*
	NOTE: the above declaration is for case 1) above, when the button is connected
	to the Arduino with a 10K pull-down resistor on the breadboard.

	Here are sample declarations for common configurations.

		to use a pull-down resistor on the breadboard:
			Button butt (btnPin);
		to use the Arduino's built-in pull-up resistor:
			Button butt (btnPin, INPUT_PULLUP);
		to use the Arduino's built-in pull-up resistor and over-ride the default hold time
		of 1 second, changing it to 1.5 seconds:
			Button butt (btnPin, INPUT_PULLUP, 1500);
		to use a pull-down resistor on the breadboard, but over-ride the default hold time
		of 1 second, changing it to 1.5 seconds:
			Button butt (btnPin, INPUT, 1500);
*/

void setup()
{
  // housekeeping
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.println("starting button demo");

  // configure the LED pin
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // check the status of the button (what happened?)
  int action = butt.checkButtonAction();

  // codes returned by checkButtonAction():  [values found in Button.h of ButtonLib]
  //    NONE -- nothing happened, just ignore
  //    CLICKED -- button was pressed and released
  //    HELD_CLICKED -- button was pressed and held down for a period of time (default = 1 second), then released

  // now manipulate the LED according to the button action
  if (action == Button::CLICKED) {
    // do CLICKED action -- turn on the LED
    Serial.print("button on pin ");
    Serial.print(btnPin);
    Serial.println(": clicked");
    digitalWrite(ledPin, HIGH);

  } else if (action == Button::HELD_CLICKED) {
    // do HELD_CLICKED action -- turn off the LED
    Serial.print("button on pin ");
    Serial.print(btnPin);
    Serial.println(": held-clicked");
    digitalWrite(ledPin, LOW);

  } else {
    // nothing happened with the button, so do nothing

  }

}
