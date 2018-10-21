/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Assignment E2 Integrated Builds part A: Dimmer switch
 * 
 * Sources: 
 *   LED fader/PWM: https://www.arduino.cc/en/Tutorial/Fade
 *   Potentiometer: https://learn.adafruit.com/adafruit-arduino-lesson-8-analog-inputs/an-experiment
 *   Mapping function: HCDE temperature example
 *****************************************/

// Set some pins & other constants
const int pinPot          = A4;
const int pinLED          = 9;   // the PWM pin the LED is attached to


// Set some initial values
// For inputs, use -999 as a "sentinel" value. 
// The first readying from the sensor shoudl be non-negative.
int potValue = -999;


//from http://www.arduino.cc/en/Tutorial/Fade
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup()
{
  // setup  pinmodes
  pinMode(pinPot, INPUT);
  pinMode(pinLED, OUTPUT);
  
  // setup the serial port for sending data to the serial monitor or host computer
  Serial.begin(9600);
}

void loop()
{
  // print first, so we get initial values on the first iteration.
  Serial.print("pot = ");
  Serial.print(potValue);
 
  Serial.print("  LED = ");
  Serial.print(brightness);
  
  Serial.println("");
  
  // read some inputs
  potValue   = analogRead(pinPot);          // pot
  
  // based on HCDE temperature example **get better citation**
  // map Potentiiometer range (0-1023) to LED brigness range (0-255), 
  // based on the range used in the adafruit fade xample
  brightness  = map(potValue, 0, 1023, 0, 255);
  
  //from http://www.arduino.cc/en/Tutorial/Fade
  analogWrite(pinLED, brightness);
  
      
  // delay (500); //comment out for faster LED reaction.
}

