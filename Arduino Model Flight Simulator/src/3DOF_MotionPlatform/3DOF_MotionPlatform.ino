/*********************************************************************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Final Project - Arduino Model Flight Simulator
 * Joystick/Servo test.
 * 
 * 
 * JoystickServo.ino is where joystick-read and servo-write come together. Values are read from 
 * joystick servos, processed, and sent to servos to control the motion platform. The same 
 * remapJoyAxis() from Joysticktest.ino is used here to ensure a full range of 0 to 1023 on the 
 * joystick side, with a 512 midpoint.  These are then (re)remapped to servo target angles ranging 
 * from zero to +/- Platfrom_RolLimit and Platform_Pitchlimit, which are typically 90 to 45, based 
 * on how "wild" you want the platform to behave. The servos are then read for their current angles, 
 * and are not given new targets unless the new-old delta exceeds the NULLZONE_roll or NULLZONE_pitch 
 * as appropriate.  The NULLZONE variables were an attempt to surpress "jitter" in the platform, which 
 * met with mixed success. The original intent of JoystickServo.ino was to be another test harness 
 * focused on joystick/servo interaction, but it became the main simulator code once BlueFruit experiments 
 * proved unsuccessful.
 *
 *
 * Joystick input based on temperature sensor demo at
 * https://blogs.uw.edu/fizzlab/technology/examples  accessed 11/21/2018 
 *
 * Servo output based on TinkerCAD circuit "arduino servo motor avec potonsiometre" 
 * by user Ounis.Brahim, accessed 11/17/18
 * https://www.tinkercad.com/things/hrFMb9KYSrl-arduino-servo-motor-avec-potonsiometre-
*****************************************************************************************/
#include   <Servo.h>

/****************************************
 * PC Game port jostick axes are analog
*****************************************/
const int JoystickRollpin     = A0;   // must be an analog pin !!
const int JoystickPitchpin    = A1;   // must be an analog pin !!
//const int Joystick2Xpin     = A2;   // unused
const int JoystickThrottlepin = A3;   // must be an analog pin !!


/********************************************************************
 * Biasing values for midpoints and mininums, based on Sieral Monitor
*********************************************************************/

const int JoystickRoll_midpoint = 412; // Roll reads 245 at rest instead of 512.
const int JoystickRollmin       = 235; // Roll reads 160 when hard over instead of 0.
                                  // Roll reads 1023 when hard over the otherway so no bias needed.

const int JoystickPitch_midpoint = 479; // Pitch reads 251 at rest instead of 512.
const int JoystickPitchmin       = 245; // Pitch reads 163 when hard over instead of 0.
                                  // Pitch reads 1023 when hard over the otherway so no bias needed.

const int JoystickThrottle_midpoint = 258; // Pitch reads 258 at rest instead of 512.
const int JoystickThrottlemin       = 159; // Pitch reads 159 when hard over instead of 0.
                                  // Throttle reads 1023 when hard over the otherway so no bias needed.


/********************************************************************
 * Null zones. Don't move servos unless unless comanded to ove alot
 ********************************************************************/
const int NULLZONE_pitch = 12; // was 2, then 8, 0 worked ok, tried 180 & flipped sign
const int NULLZONE_roll  = 12; // was 5, then 8, 0 worked ok, tried 180 & flipped sign


/********************************************
 * Platform motion limits.
*********************************************/
const int Platform_RollLimit  = 90; // was 45
const int Platform_PitchLimit = 90; // was 25


/**********************************************
 * Raw values read from joystick pins
***********************************************/
int JoystickRollValue;       // raw analog data
int JoystickPitchValue;      // raw analog data
//int Joystick2XValue;       // raw analog data
int JoystickThrottleValue;   // raw analog data

/********************************************************************************
 * remapped values to compenstate for internal joystick potientiometer wierdness
*********************************************************************************/
int remapped_JoystickRollValue;     // compensate for joystick bias
int remapped_JoystickPitchValue;    // compensate for joystick bias
//int remapped_Joystick2XValue;      // compensate for joystick bias
int remapped_JoystickThrottleValue; // compensate for joystick bias

Servo ServoRoll;  
Servo ServoPitch;
Servo servo3;

const int ServoRollPin = 2;
const int ServoPitchPin = 3;
const int servo3Pin = 4;

int servoRollTarget;
int servoPitchTarget;
int servoThrottleTarget;


/***************************************************
 * FUNCTION remapJoyAxis()
 * Remaps a given axis to compentsate for minvalue 
 * and midpoint biases.
 * 
 * map the "bottom half" from axis' reported 
 * min value and mindpont to 0-512
 * 
 * map the "top half" from ax's reported midpoint
 * and 2013 to 512-1023
 * ************************************************/
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
  /************************************
   * setup Joystick nput pins
  *************************************/
  pinMode(JoystickRollpin, INPUT);  
  pinMode(JoystickPitchpin, INPUT);  
  // pinMode(Joystick2Xpin, INPUT);  
  pinMode(JoystickThrottlepin, INPUT);  

  ServoRoll.attach(ServoRollPin);
  ServoPitch.attach(ServoPitchPin);
  servo3.attach(servo3Pin);

  // setup the serial port for sending data to the serial monitor or host computer
  Serial.begin(9600);

  // display a startup message
  Serial.println ("JoyRoll       JoyPitch     Joy2X  JoyThrottle  [ServoRoll  ServoPitch]");

}


void loop() {

  /**********************************************************
   * read the raw value of the temp JoystickX
  ***********************************************************/
  JoystickRollValue     = analogRead(JoystickRollpin); 
  JoystickPitchValue    = analogRead(JoystickPitchpin); 
  //Joystick2XValue       = analogRead(Joystick2Xpin); 
  JoystickThrottleValue = analogRead(JoystickThrottlepin); 
  
  /***************************************************************************
   * Remap the raw joystick values so they range 0-1023 with at 512 midpoint
  ***************************************************************************/
  remapped_JoystickRollValue = remapJoyAxis(JoystickRollValue, 
                                            JoystickRollmin, 
                                            JoystickRoll_midpoint);
    
  remapped_JoystickPitchValue = remapJoyAxis(JoystickPitchValue, 
                                             JoystickPitchmin, 
                                             JoystickPitch_midpoint);
  
  remapped_JoystickThrottleValue = remapJoyAxis(JoystickThrottleValue, 
                                                JoystickThrottlemin, 
                                                JoystickThrottle_midpoint);
  
 /*******************************************
  * Print joystick diagnostics to searial
  *******************************************/
  Serial.print(JoystickRollValue);
  Serial.print("  ");
  Serial.print(remapped_JoystickRollValue);
  Serial.print("  #  ");
  Serial.print(JoystickPitchValue);
  Serial.print("  ");
  Serial.print(remapped_JoystickPitchValue);
  Serial.print("  #  ");
  // Serial.print(Joystick2XValue);
  Serial.print("  # ");
  Serial.print(JoystickThrottleValue);
  Serial.print("  ");  
  Serial.print(remapped_JoystickThrottleValue);
  Serial.print("  $  ");  


 /*******************************************************************************
  * Move servos based on joystick values, platform motion limits, and null zones
  *******************************************************************************/
  servoRollTarget = map(remapped_JoystickRollValue, 
                     0, 1023, 
                     90 - Platform_RollLimit, 90 + Platform_RollLimit);

  if (abs(servoRollTarget - ServoRoll.read()) > NULLZONE_roll){ 
    ServoRoll.write(servoRollTarget);
  }

  servoPitchTarget = map(remapped_JoystickPitchValue, 
                      1023, 0, 
                      90 - Platform_PitchLimit, 90 + Platform_PitchLimit);
                     
  if (abs(servoPitchTarget - ServoPitch.read()) > NULLZONE_pitch){ 
    ServoPitch.write(servoPitchTarget);
  }

  // Keep it simple for throttle
   servoThrottleTarget = map(remapped_JoystickThrottleValue, 
                      1023, 0, 
                      0, 180);
   servo3.write(servoThrottleTarget);


 /*****************************
  * More Serial diagnostics
  *****************************/
  Serial.print("[");  
  Serial.print(servoRollTarget);
  Serial.print("  ");  
  Serial.print(servoPitchTarget);
  Serial.print("]");  
  
  // Give the servoes some time to reach their targets
  delay (25); //from https://www.instructables.com/id/ArduinoServoPotentiometer/
  
  Serial.println(); // whatever we've been printing, time for newline.
}
