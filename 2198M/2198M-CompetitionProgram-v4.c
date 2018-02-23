#pragma config(Sensor, dgtl1,  leftDrive,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightDrive,     sensorQuadEncoder)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backRight,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           leftArm,       tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rightArm,      tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////


void drive(int speed) {
	motor[frontLeft]=speed;
	motor[frontRight]=speed;
	motor[backLeft]=speed;
	motor[backRight]=speed;
}

void wheels(int left, int right) {
	motor[frontLeft]=left;
	motor[frontRight]=right;
	motor[backLeft]=left;
	motor[backRight]=right;
}

void arms(int speed) {
	motor[leftArm]=speed;
	motor[rightArm]=speed;
}

void clearEncoder() {
		SensorValue[rightDrive] = 0;      // Set the encoder so that it starts counting at 0
    SensorValue[leftDrive]  = 0;      // Set the encoder so that it starts counting at 0
}

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
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	clearEncoder();

	while(SensorValue[rightDrive] < 400)
    {
        drive(40);
				arms(-110);
    }

		arms(0);

		clearEncoder();

	while(SensorValue[rightDrive] < 800)
    {
        drive(40);
		}

    drive(0);

  arms(127);
  wait1Msec(750);
  arms(0);

  clearEncoder();

	while(SensorValue[rightDrive] > -1700)
    {
        wheels(-40, -80);
		}

    drive(0);


    clearEncoder();

	while(SensorValue[rightDrive] > -450)
    {
        wheels(40, -40);
		}

  drive(0);

  clearEncoder();

	while(SensorValue[rightDrive] < 220)
    {
        drive(63);
		}

  drive(0);

  clearEncoder();

	while(SensorValue[rightDrive] < 400)
    {
        drive(73);
        arms(-90);
		}

  drive(0);
  arms(0);

   clearEncoder();

	while(SensorValue[rightDrive] > -400)
    {
        drive(-63);
        arms(100);
		}

  drive(0);
  arms(0);

   clearEncoder();

	while(SensorValue[rightDrive] > -300)
    {
        drive(-63);
		}

  drive(0);

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

	while (true)
	{
	  //Right side of the robot is controlled by the right joystick, Y-axis
    motor[frontRight] = (vexRT[Ch2]*0.7);
    motor[backRight]  = (vexRT[Ch2]*0.7);
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[frontLeft] = (vexRT[Ch3]*0.7);
    motor[backLeft]  = (vexRT[Ch3]*0.7);

    if(vexRT[Btn6U] == 1)
    {
      motor[leftArm] = 100;
      motor[rightArm] = 100;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[leftArm] = -100;
      motor[rightArm] = -100;
    }
    else
    {
      motor[leftArm] = 0;
      motor[rightArm] = 0;
    }
	}
}
