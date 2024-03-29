#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,	 rightIEM,			 sensorQuadEncoderOnI2CPort,		, AutoAssign)
#pragma config(Sensor, I2C_2,	 leftIEM,				 sensorQuadEncoderOnI2CPort,		, AutoAssign)
#pragma config(Motor,	 port1,						rightMotor,		 tmotorVex269, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,	 port10,					leftMotor,		 tmotorVex269, openLoop, encoder, encoderPort, I2C_2, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard							 !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Move Forward and Display Values - 269 Motors
This program instructs your robot to move forward at half power for 1000 encoder counts. It will
display the encoder values on the VEX LCD. There is a two second pause at the beginning of the program.

Robot Model(s): Modified Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 1        rightMotor          269 Motor             Right side motor, Reversed
Motor Port 10       leftMotor           269 Motor             Left side motor
I2C_1               rightIEM            Integrated Encoder    Encoder mounted on rightMotor
I2C_2               leftIEM             Integrated Encoder    Encoted mounted on leftMotor
UART2               -------             VEX LCD               VEX LCD, Optional
----------------------------------------------------------------------------------------------------*/

task main
{
	wait1Msec(2000);

	//Setup the VEX LCD for displaying encoder values
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDString(0, 0, "R: ");
	displayLCDString(1, 0, "L: ");

	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;

	//While less than 1000 encoder counts of the right motor
	while(nMotorEncoder[rightMotor] < 1000)
	{
		//Display the right and left motor encoder values
		displayLCDNumber(0, 3, nMotorEncoder[rightMotor], 6);
		displayLCDNumber(1, 3, nMotorEncoder[leftMotor], 6);
		//Move forward at half power
		motor[rightMotor] = 63;
		motor[leftMotor]	= 63;
	}
}
