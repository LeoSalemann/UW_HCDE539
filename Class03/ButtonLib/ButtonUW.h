// Button.h

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
*/

#ifndef ButtonUW_h
#define ButtonUW_h

#include "Arduino.h"

class Button
{
  public:
  
    //  button actions
    static const int NONE = 0;          // no action on button
    static const int CLICKED = 1;       // button pressed and released
    static const int HELD_CLICKED = 2;  // button pressed and held down, then released

    static const int PRESSED = CLICKED;   // for backward compatibility with earlier release of library
    static const int HELD = HELD_CLICKED; // for backward compatibility with earlier release of library

    // constructor interface, with default values for optional parameters
    Button(int buttonPin, 
    	int inputMode = INPUT,	// or INPUT_PULLUP, per arduino.cc/en/Tutorial/InputPullupSerial
    	long holdTime = 1000, 	// in ms
    	long debounceInterval = 10);	// in ms

    // methods
    int checkButtonAction();

  private:

    // button parameters
    int _buttonPin;   // pin number for button connection
    int _inputMode;   // input mode for pin -- whether normal or using internal pullup resistor
    long _debounceInterval; // delay to filter noise on button press (ms)
    long _holdTime;         // delay for button hold event (ms)
    int  _buttonDownValue;  // pin value for closed state (down) of button
    int  _buttonUpValue;    // pin value for open state (up) of button

    // button state variables
    int _btnState;    // current state of button (up/down)
    int _btnPrev;     // prior state of button (up/down)
    long  _btnDown;     // last time button was detected down
    long  _btnUp;       // last time button was detected up
    bool  _btnIgnoreUp; // true if waiting to see if button has been held down
};

#endif
