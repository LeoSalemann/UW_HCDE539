// Button.cpp

/*
	ButtonLib library for a flexible, high-level interface to hardware buttons.
	-- Andy Davidson
	-- adavid7@uw.edu

	A button is connected to a digital input pin. The library suports
	either a normal button connection with a pull-down resistor, as here:
		1) arduino.cc/en/Tutorial/Button
	or the use of the Arduino's internal pull-up resistor as here:
		2) arduino.cc/en/Tutorial/InputPullupSerial

	In either case, the library handles all of the logic for detecting
	when the button has been pressed and released, and just informing the
	client program of button state changes.
	
	The algorithm for PRESSED and HELD logic adapted from Jeff Saltzman: jmsarduino.blogspot.com
*/
 

#include "Arduino.h"
#include "ButtonUW.h"

Button::Button(int buttonPin,
               /* default values for the remaining parameters are defined in Button.h */
               int  inputMode,
               long holdTime,
               long debounceInterval)

{
  /* keep local copies of constructor parameters */
  _buttonPin = buttonPin;
  _inputMode = inputMode;
  _holdTime = holdTime;
  _debounceInterval = debounceInterval;

  /* set internal values for UP and DOWN logic of button --
     using built-in pullup resistor inverts the logic:
     arduino.cc/en/Tutorial/InputPullupSerial
  */
  if (_inputMode == INPUT_PULLUP) {
    _buttonDownValue = LOW;
    _buttonUpValue = HIGH;
  }
  else {
    _buttonDownValue = HIGH;
    _buttonUpValue = LOW;
  }

  /* initialize the pin to the right mode */
  pinMode(_buttonPin, _inputMode);

  /* initialize all state variables */
  _btnState = _buttonUpValue;
  _btnPrev = _buttonUpValue;
  _btnDown = 0;
  _btnUp = 0;
  _btnIgnoreUp = false;
}

int Button::checkButtonAction()
{
  // checks the given button status and returns a code indicating
  // if it was clicked, or if it was pressed and held for a
  // given amount of time then released (held-clicked), or nothing has happened.

  // this algorithm is adapted from Jeff Saltzman: jmsarduino.blogspot.com

  // return value = button action code (NONE, CLICKED, HELD_CLICKED)
  int result = NONE;

  // read the current state of the button
  _btnState = digitalRead(_buttonPin);

  // check to see if it just went down, with debouncing
  if ((_btnState == _buttonDownValue) &&
      (_btnPrev == _buttonUpValue) &&
      ((millis() - _btnUp) > _debounceInterval))
  {
    // button just went down for real, so just remember the time
    _btnDown = millis();
  }

  // now check to see if it just went up, with debouncing
  if ((_btnState == _buttonUpValue) &&
      (_btnPrev == _buttonDownValue) &&
      ((millis() - _btnUp) > _debounceInterval))
  {
    // button was just released, so see how long it was down
    // we are still waiting to see if it is being held down
    if (!_btnIgnoreUp)
      result = CLICKED;
    else
      _btnIgnoreUp = false;

    _btnUp = millis();
  }

  if ((_btnState == _buttonDownValue) &&
      ((millis() - _btnDown) > _holdTime))
  {
    // it's been down so long, call it held, not just clicked
    result = HELD_CLICKED;
    _btnIgnoreUp = true;
    _btnDown = millis();
  }

  // remember this state for the next time around
  _btnPrev = _btnState;

  return result;
}
