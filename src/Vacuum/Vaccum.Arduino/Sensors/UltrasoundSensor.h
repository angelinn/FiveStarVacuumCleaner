#pragma once
#include "Arduino.h"

#define GOLDEN_RATIO 0.034 / 2

class UltrasoundSensor
{
public:
	UltrasoundSensor(int echoPin, int triggerPin, int threshold = 60)
	{
		this->echoPin = echoPin;
		this->triggerPin = triggerPin;
		this->threshold = threshold;

		pinMode(echoPin, OUTPUT);
		pinMode(triggerPin, OUTPUT);
	}

public:
	bool IsObstacleAhead()
	{
		int distance = GetDistance();
		return distance < threshold;
	}

private:
	int GetDistance()
	{
		// Clears the trigPin
		digitalWrite(triggerPin, LOW);
		delayMicroseconds(2);
		// Sets the trigPin on HIGH state for 10 micro seconds
		digitalWrite(triggerPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(triggerPin, LOW);
		// Reads the echoPin, returns the sound wave travel time in microseconds
		long duration = pulseIn(echoPin, HIGH);
		// Calculating the distance

		return duration * GOLDEN_RATIO;
	}

private:
	int echoPin;
	int triggerPin;
	int threshold;
};
