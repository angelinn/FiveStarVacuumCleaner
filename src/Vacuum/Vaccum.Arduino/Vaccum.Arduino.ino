#include "Sensors/UltrasoundSensor.h"
#include "Movement/MovementEngine.h"
/*
 Name:		Vaccum.ino
 Created:	7/29/2018 2:23:39 PM
 Author:	betra
*/

#define US_TRIGGER_PIN 9
#define US_ECHO_PIN 10

#define LEFT_MOTOR_FORWARD_PIN 2
#define LEFT_MOTOR_BACKWARD_PIN 4
#define RIGHT_MOTOR_FORWARD_PIN 7
#define RIGHT_MOTOR_BACKWARD_PIN 8

MovementEngine movement(LEFT_MOTOR_FORWARD_PIN, LEFT_MOTOR_BACKWARD_PIN,
						RIGHT_MOTOR_FORWARD_PIN, RIGHT_MOTOR_BACKWARD_PIN,
						US_ECHO_PIN, US_TRIGGER_PIN);

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(9600);

	movement.Begin();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	delay(1000);
}
