/****************************************
 * Leo Salemann
 * HCDE 539 Physical Computing
 * University of Washinton
 * Assignment E1 Individual Builds
 * 
 * sources: 
 * https://www.adafruit.com/product/161
 * Potentiometery code
 * https://learn.adafruit.com/adafruit-arduino-lesson-8-analog-inputs/an-experiment
 *****************************************/

// Set some pins & other constants
const int pinPhotoSensor  = A0;   // must be an analog pin !!
const int pinHallFXsensor = A1;
const int pinMotor        = A2;
const int pinPot          = A4;

const int motorMinValue = 1;

// Set some initial values
// For inputs, use -999 as a "sentinel" value. 
// The first readying from the sensor shoudl be non-negative.
int lightValue = -999;  
int hallVaue = -999;  
int motorValue = 1;


void setup()
{
  // setup  pinmodes
  pinMode(pinPhotoSensor,  INPUT);
  pinMode(pinHallFXsensor, INPUT);
  pinMode(pinMotor,        OUTPUT);
  pinMode(pinPot,          INPUT);

  
  // setup the serial port for sending data to the serial monitor or host computer
  Serial.begin(9600);
}

void loop()
{
  // print first, so we get initial values on the first iteration.
  Serial.print("photocel = ");
  Serial.print(lightValue);
  
  Serial.print("  hall effect = ");
  Serial.print(hallVaue);
  
  
  Serial.print("  motor = ");
  Serial.print(motorValue);
  
  Serial.print("  pot = ");
  Serial.print(potValue);
  
  Serial.println("");
  
  // read some inputs
  lightValue = analogRead(pinPhotoSensor);  // photosensor
  hallVaue   = analogRead(pinHallFXsensor); // hall effect sensor
  potValue   = analogRead(pinPot);          // pot
  
  // write some outputs
  analogWrite(pinMotor, motorValue);
 
  
  // change some variables for next iteration;
  if (motorValue >= 1024){
    motorValue = motorMinValue;
  }else{
    motorValue = motorValue * 2;
  }
      
  delay (500);
}
