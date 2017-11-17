#pragma config(Motor,  port1,           frontRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port2,           backRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           towerLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port4,           clawLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port5,           mobileRighttMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           mobileLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port7,           clawRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           towerRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           backLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port10,          frontLeftMotor, tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

	while (true)
	{

    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[frontRightMotor] = vexRT[Ch2];
    motor[backRightMotor]  = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[frontLeftMotor] = vexRT[Ch3];
    motor[backLeftMotor]  = vexRT[Ch3];


    // Control speeds from variable to make changes easier
    int mobileSpeed = 127;
    int towerSpeed = 127;
    int clawSpeed = 127;

	  //Tower Cone Control
    if(vexRT[Btn6U] == 1)
    {
      motor[towerRightMotor] = towerSpeed;
      motor[towerLeftMotor] = towerSpeed;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[towerRightMotor] = (-1)*(towerSpeed);
      motor[towerLeftMotor] = (-1)*(towerSpeed);
    }
    else
    {
      motor[towerRightMotor] = 0;
      motor[towerLeftMotor] = 0;
    }

    //Mobile Goal Control
    if(vexRT[Btn5U] == 1)
    {
      motor[mobileLeftMotor] = mobileSpeed;
      motor[mobileRightMotor] = mobileSpeed;
    }
    else if(vexRT[Btn5D] == 1)
    {
      motor[mobileLeftMotor] = (-1)*(mobileSpeed);
      motor[mobileRightMotor] = (-1)*(mobileSpeed);
    }
    else
    {
      motor[mobileLeftMotor] = 0;
      motor[mobileRightMotor] = 0;
    }

    //Claw Motor Control
    if(vexRT[Btn8L] == 1)
    {
      motor[clawLeftMotor] = clawSpeed;
      motor[clawRightMotor] = clawSpeed;
    }
    else if(vexRT[Btn8R] == 1)
    {
      motor[clawLeftMotor] = (-1)*(clawSpeed);
      motor[clawRightMotor] = (-1)*(clawSpeed);
    }
    else
    {
      motor[clawLeftMotor] = 0;
      motor[clawRightMotor] = 0;
    }

	}
}