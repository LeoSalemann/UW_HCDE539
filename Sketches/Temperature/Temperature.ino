/* Thermometer
 ahdavidson
 www.goldensection.cc
 8/1/11
 
 This program implements a simple thermometer by reading data from a temperature sensor.
 It then displays the values in the serial monitor window.
 
 */



// this constant shows where we'll find the temp sensor
const int sensorPin = A1;   // must be an analog pin !!

// these variables are used to calculate the temperature
int sensorValue;  // raw analog data
int sensorMV;     // corresponding voltage
float tempCent;   // degrees Fahrenheit
float tempFahr;   // degrees Centigrade


void setup() {

  // setup the pin for the temp sensor input
  pinMode(sensorPin, INPUT);  

  // setup the serial port for sending data to the serial monitor or host computer
  Serial.begin(9600);

  // display a startup message
  Serial.println ("Thermometer");

}


void loop() {

  // read the raw value of the temp sensor
  sensorValue = analogRead(sensorPin); 

  // an analog sensor on the Arduino returns a value between 0 and 1023, depending on the strength
  // of the signal it reads. (this is because the Arduino has a 10-bit analog to digital converter.)

  // so we have to convert this value between 0-1023 into a temperature. the calculation is based on the
  // voltage, and then the specs of the temperature sensor to convert that into degrees Celsius.
  
  // if you're not interested in the details, you can just think of it as doing some math magic and skip down below

  // first, convert the sensor reading to the right voltage level (5000 mV, since the Arduino port is +5V)
  // the map function is just an efficient shortcut for some ratio math
  sensorMV = map(sensorValue, 0, 1023, 0, 4999);

  // now convert this voltage to degrees, both Fahrenheit and Centigrade
  // this calculation comes from the spec of the specific sensor we are using
  tempCent = (sensorMV - 500) / 10.0;
  tempFahr = (tempCent * 9 / 5.0) + 32;

  // write these temperatures out to the serial monitor so we can see them
  Serial.print(tempFahr);
  Serial.print(" deg F  ");
  Serial.print(tempCent);
  Serial.print(" deg C");
  Serial.println();

  // since temperature doesn't change so rapidly, we can set the delay here until the next check
  // this should also work with shorter delays, or none for ultra real-time (OK, 9600 baud...)
  delay (500); 

}










