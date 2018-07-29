#pragma once
#include "Arduino.h"

#define GOLDEN_RATIO 0.034 / 2

int getDistance(int echoPin, int trigerPin)
{
	// Clears the trigPin
	digitalWrite(trigerPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigerPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	long duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	Serial.println(sizeof(int));
	Serial.println(sizeof(long));
	Serial.println(duration);
	return duration * GOLDEN_RATIO;
}