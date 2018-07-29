#include "Sensors/UltrasoundSensor.h"
/*
 Name:		Vaccum.ino
 Created:	7/29/2018 2:23:39 PM
 Author:	betra
*/

#define US_TRIGGER_PIN 9
#define US_ECHO_PIN 10

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(US_TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
	pinMode(US_ECHO_PIN, INPUT); // Sets the echoPin as an Input
	Serial.begin(9600); // Starts the serial communication
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.print("Distance: ");
	Serial.println(getDistance(US_ECHO_PIN, US_TRIGGER_PIN));
	delay(1000);
}
