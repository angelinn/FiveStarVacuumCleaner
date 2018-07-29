#pragma once

#include "Motor.h"
#include "./Sensors/UltrasoundSensor.h"

enum Rotation
{
	None = -1,
	Left,
	Right
};

class MovementEngine
{
public:
	MovementEngine(int leftMotorForwardPin, int leftMotorBackwardPin,
				   int rightMotorForwardPin, int rightMotorBackwardPin,
				   int usEchoPin, int usTriggerPin)
		: leftMotor(leftMotorForwardPin, leftMotorBackwardPin),
	      rightMotor(rightMotorForwardPin, rightMotorBackwardPin),
		  ultrasound(usEchoPin, usTriggerPin)
	{

	}

public:
	void Begin()
	{
		leftMotor.Forward();
		rightMotor.Forward();
	}

	void Loop()
	{
		if (ultrasound.IsObstacleAhead())
		{
			int random = rand() % 2;
			Rotate((Rotation)random);
		}
	}

	void RotateLeft()
	{
		Rotate(Rotation::Left);
	}

	void RotateRight()
	{
		Rotate(Rotation::Right);
	}

	void Rotate(Rotation rotation)
	{
		if (rotation == Rotation::Left)
		{
			leftMotor.Forward();
			rightMotor.Backward();
		}
		else if (rotation == Rotation::Right)
		{
			rightMotor.Forward();
			leftMotor.Backward();
		}

		delay(1000);
		Stop();
		delay(1000);
		Begin();
	}

	void Stop()
	{
		leftMotor.Stop();
		rightMotor.Stop();
	}

private:
	Motor leftMotor;
	Motor rightMotor;
	UltrasoundSensor ultrasound;
};
