// Arthemus: Created by Ali Shariatmadari

#pragma config(Motor,  port1,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          backRight,     tmotorVex393, openLoop, reversed)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	double motorSensitivity = 1.0;

	//R-SENSE OF 1.0 CAUSES STATIC ROTATION.
	double rotationSensitivity= 0.5;

	while (true){

		double LeftY = vexRT[Ch3] / motorSensitivity;
		double LeftX = vexRT[Ch4] / motorSensitivity;
		double RightY = vexRT[Ch2] / motorSensitivity;
		double RightX = vexRT[Ch1] / motorSensitivity;

		if (LeftY != 0){

		/*
		Ali, this is a slight flaw
		in your program. Since the
		joysticks are analog, there
		is often no way for them to
		be exactly centered. You
		should replace this with a
		threshold value such as 20
		or 30 as the value of the
		joystick will almost never
		be 0. This won't make a
		difference for this snippet
		of code, as you don't have
		any function to run if it
		was equal to 0, but it's a
		good idea to keep it in
		mind if you did.		-Tony
		*/

			if (LeftX > 0){
				motor[frontRight] = LeftY;
				motor[backRight] = LeftY;
				motor[frontLeft] = LeftX / rotationSensitivity;
				motor[backLeft] = LeftX / rotationSensitivity;
			} else

			if (LeftX < 0){
				motor[frontRight] = LeftX / rotationSensitivity;
				motor[backRight] = LeftX / rotationSensitivity;
				motor[frontLeft] = LeftY;
				motor[backLeft] = LeftY;
			}
		} else

		if (LeftX > 0){
			motor[frontRight] = LeftX;
			motor[BackRight] = LeftX;
			motor[frontLeft] = -LeftX;
			motor[BackLeft] = -LeftX;
		}
}
