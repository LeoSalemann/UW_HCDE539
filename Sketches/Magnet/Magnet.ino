// MagTest

// Blinks an LED whenever the magnetic sensor reads that the magnet is in range, and also buzzes.
// Uses the serial monitor window to continuously display the value of the magnetic sensor.


const int buzzPin = 2;  // pin for the Piezo buzzer
const int hallPin = 3;  // pin for the Hall Effect sensor
const int ledPin = 13;  // pin for the usual LED

const int magnetIn = LOW;  // NOTE the sensor returns LOW when the magnet is present
const int magnetOut = HIGH;


void setup () {
  pinMode (hallPin, INPUT);
  pinMode (ledPin, OUTPUT);
  pinMode (buzzPin, OUTPUT);
  Serial.begin (9600);
  Serial.println ("*** start");
}


void loop () {

  // read the value of the sensor and print it out
  int mag = digitalRead(hallPin);
  Serial.println(mag);

  // if the magnet is in range, turn on the LED and make a quick buzzer noise
  if (mag == magnetIn) {
    digitalWrite(ledPin, HIGH);
    tone(buzzPin, 400, 100);
  }
  // otherwise turn off the LED
  else {
    digitalWrite(ledPin, LOW);
  }


}

