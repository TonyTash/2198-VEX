#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                        - Wait for Push 2 -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to wait until the touch sensor is pressed before moving forward  *|
|*  for 1.5 seconds.  There is a two second pause at the beginning of the program.                    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital Port 6      touchSensor         VEX Bumper Switch     Front mounted, facing forward.    *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	while(SensorValue(touchSensor) == 0)		// Loop while robot's bumper/touch sensor isn't pressed in
	{
		// Do nothing
	}

	motor[rightMotor] = 63;			            // Motor on port2 is run at half (63) power forward
	motor[leftMotor]  = 63;			            // Motor on port3 is run at half (63) power forward
	wait1Msec(1500);				                // Robot runs previous code for 1500 milliseconds before moving on
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++