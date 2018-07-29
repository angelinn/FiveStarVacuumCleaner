#pragma once

#include "Arduino.h"

class Motor
{
public:
	Motor(int forwardPin, int backwardPin) : forwardPin(0), backwardPin(0)
	{
		this->forwardPin = forwardPin;
		this->backwardPin = backwardPin;

		pinMode(forwardPin, OUTPUT);
		pinMode(backwardPin, OUTPUT);
	}

public:
	void Forward()
	{
		Stop();

		digitalWrite(forwardPin, HIGH);
		digitalWrite(backwardPin, LOW);
	}

	void Backward()
	{
		Stop();

		digitalWrite(backwardPin, HIGH);
		digitalWrite(forwardPin, LOW);
	}

	void Stop()
	{
		digitalWrite(forwardPin, LOW);
		digitalWrite(backwardPin, LOW);

		delay(1000);
	}

private:
	int forwardPin;
	int backwardPin;
};
