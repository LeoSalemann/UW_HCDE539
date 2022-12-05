/*******************************************************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Final Project - Arduino Model Flight Simulator
 * Joystick Test harness - Read Axes and view data with Serial Monitor/Plotter
 * 
 * based on the temperature sensor demo at
 * https://blogs.uw.edu/fizzlab/technology/examples  accessed 11/21/2018 
******************************************************************************/

// PC Game port jostick axes are analog
const int Joystick1Xpin = A0;   // must be an analog pin !!
const int Joystick1Ypin = A1;   // must be an analog pin !!
const int Joystick2Xpin = A2;   // must be an analog pin !!
const int Joystick2Ypin = A3;   // must be an analog pin !!

const int Joystick1Xmidpoint = 443;
const int Joystick1Xmin = 190;

const int Joystick1Ymidpoint = 367;
const int Joystick1Ymin = 199;

const int Joystick2Ymidpoint = 249;
const int Joystick2Ymin = 160;

// these variables are used to store axis values.
int Joystick1XValue;  // raw analog data
int Joystick1YValue;  // raw analog data
int Joystick2XValue;  // raw analog data
int Joystick2YValue;  // raw analog data
int Joystick1XValueOrig; //before re-mapping
int Joystick1YValueOrig; //before re-mapping
int Joystick2YValueOrig; //before re-mapping

/*****************************************************************************
 * FUNCTION remapJoyAxis()
 * Takes a joystick axis with a range like 125-1023 and a 325 midpoint, and 
 * remaps it so it acts like 0-1023 with a 512 midopint.
 *
 * Splits the joystick range into two parts: [Joymin-JoyMid] and [JoyMid-1023]
 * Remaps JoyVal into one of these parts, depending of if it's above or below
 * Joy Mid
******************************************************************************/
int remapJoyAxis(int joyVal, int joyMin, int JoyMid){
  int retVal = 0;
 if (joyVal < JoyMid) {
       retVal = map(joyVal, joyMin, JoyMid, 0, 512);
  }else{
      retVal = map(joyVal, JoyMid, 1023, 512, 1023);
  }
  if (retVal < 0){
    retVal = 0;
  }

  return retVal;
}

void setup() {

  // setup the pin for the temp JoystickX input
  pinMode(Joystick1Xpin, INPUT);  
  pinMode(Joystick1Ypin, INPUT);  
  pinMode(Joystick2Xpin, INPUT);  
  pinMode(Joystick2Ypin, INPUT);  

  // setup the serial port for sending data to the serial monitor or host computer
  Serial.begin(9600);

  // display a startup message
  Serial.println ("1X=Roll  1Y=Pitch  2X  2Y=Throttle");

}


void loop() {

  // read the raw value of the temp JoystickX
  Joystick1XValue = analogRead(Joystick1Xpin); 
  Joystick1YValue = analogRead(Joystick1Ypin); 
  Joystick2XValue = analogRead(Joystick2Xpin); 
  Joystick2YValue = analogRead(Joystick2Ypin); 

  Joystick1XValueOrig = Joystick1XValue;
  Joystick1YValueOrig = Joystick1YValue;
  Joystick2YValueOrig = Joystick2YValue;

  Joystick1XValue = remapJoyAxis(Joystick1XValue, Joystick1Xmin, Joystick1Xmidpoint);
  Joystick1YValue = remapJoyAxis(Joystick1YValue, Joystick1Ymin, Joystick1Ymidpoint);
  Joystick2YValue = remapJoyAxis(Joystick2YValue, Joystick2Ymin, Joystick2Ymidpoint);

//  Serial.print(Joystick1XValueOrig);
//  Serial.print("  ");
  Serial.print(Joystick1XValue);
  Serial.print("  #  ");
//  Serial.print(Joystick1YValueOrig);
//  Serial.print("  ");
  Serial.print(Joystick1YValue);
  Serial.print("  #  ");
  /* Serial.print(Joystick2XValue); //this channel not used */
  /* Serial.print("  #  ");         //this channel not used */
//  Serial.print(Joystick2YValueOrig);
//  Serial.print("  ");
  Serial.print(Joystick2YValue);
  Serial.println();

  // Uncomment for Serial monitor; comment-out for Serial Plotter
  // delay (500); 

}
