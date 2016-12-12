#pragma config(Sensor, in1,    lArmPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    rArmPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    lPivotPot,      sensorPotentiometer)
#pragma config(Sensor, in4,    rPivotPot,      sensorPotentiometer)
#pragma config(Motor,  port1,           lBackMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rFrontMotor,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rBackMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           lArmMotor2,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           rArmMotor2,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           rArmMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           lArmMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           rPivot,        tmotorVex393, openLoop)
#pragma config(Motor,  port9,           lPivot,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          lFrontMotor,   tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// 2198Y Drive Program
// Last Updated by Tony T

int lOffset = 240;
int rOffset = 0;
int lPOffset = 0;
int rPOffset = 300;
int pivotHold = 0;
int armMode = 0;
int rPivotCalibrated = 0;
int difference = 0;
// 0 = user
// 1 = arm down
// 2 = arm half up
// 3 = scoring position

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!



void forward()
{
	motor[lFrontMotor] = 127;
	motor[lBackMotor] = 127;
	motor[rFrontMotor] = 127;
	motor[rBackMotor] = 127;
}

void backward()
{
	motor[lFrontMotor] = -127;
	motor[lBackMotor] = -127;
	motor[rFrontMotor] = -115;
	motor[rBackMotor] = -115;
}

void rest()
{
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;
	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
}

void cw()
{
	motor[lFrontMotor] = 127;
	motor[lBackMotor] = 127;
	motor[rFrontMotor] = -127;
	motor[rBackMotor] = -127;
}

void ccw()
{
	motor[lFrontMotor] = -127;
	motor[lBackMotor] = -127;
	motor[rFrontMotor] = 127;
	motor[rBackMotor] = 127;
}

void armUp(int lArm, int rArm, int motorspeed)
{
	if (lArm == rArm)
	{
		motor[rArmMotor] = 127;
		motor[lArmMotor] = 127;
		motor[rArmMotor2] = 127;
		motor[lArmMotor2] = 127;
	}

	else if (lArm > rArm)
	{
		motor[rArmMotor] = 127;
		motor[lArmMotor] = (127 - motorspeed/2);
		motor[rArmMotor2] = 127;
		motor[lArmMotor2] = (127 - motorspeed/2);
	}

	else if (lArm < rArm) {
		motor[rArmMotor] = (127 - motorspeed/2);
		motor[lArmMotor] = 127;
		motor[rArmMotor2] = (127 - motorspeed/2);
		motor[lArmMotor2] = 127;
	}
}

void armUpNoPot()
{
	motor[lArmMotor] = 127;
	motor[rArmMotor] = 127;
	motor[lArmMotor2] = 127;
	motor[rArmMotor2] = 127;
}

void armDownNoPot()
{
	motor[lArmMotor] = -127;
	motor[rArmMotor] = -127;
	motor[lArmMotor2] = -127;
	motor[rArmMotor2] = -127;
}


void armDown(int lArm, int rArm, int motorspeed)
{
		if (lArm == rArm)
			{
				motor[rArmMotor] = -127;
				motor[lArmMotor] = -127;
				motor[rArmMotor] = -127;
				motor[lArmMotor] = -127;
			}

			else if (lArm > rArm)
			{
				motor[rArmMotor] = (-127 + motorspeed/2);
				motor[lArmMotor] = -127;
				motor[rArmMotor] = (-127 + motorspeed/2);
				motor[lArmMotor] = -127;
			}

			else if (lArm < rArm)
			{
				motor[rArmMotor] = -127;
				motor[lArmMotor] = (-127 + motorspeed/2);
				motor[rArmMotor] = -127;
				motor[lArmMotor] = (-127 + motorspeed/2);
			}
}

void pivotUp(int lPivotSensor, int rPivotSensor, int pivotspeed)
{

			//if (lPivotSensor == rPivotSensor)
			//{
				motor[lPivot] = 127;
				motor[rPivot] = 127;
			//}

			//else if (lPivotSensor > rPivotSensor)
			//{
			//	motor[rPivot] = 127;
			//	motor[lPivot] = (127 - pivotspeed);
			//}

			//else if (lPivotSensor < rPivotSensor) {
			//	motor[rPivot] = (127 - pivotspeed);
			//	motor[lPivot] = 127;
			//}

}

void pivotDown(int lPivotSensor, int rPivotSensor, int pivotspeed)
{

	motor[lPivot] = -127;
	motor[rPivot] = -127;

	//if (lPivotSensor == rPivotSensor)
	//		{
	//			motor[rPivot] = -127;
	//			motor[lPivot] = -127;
	//		}

	//		else if (lPivotSensor > rPivotSensor)
	//		{
	//			motor[rPivot] = (-127 + pivotspeed);
	//			motor[lPivot] = -127;
	//		}

	//		else if (lPivotSensor < rPivotSensor)
	//		{
	//			motor[rPivot] = -127;
	//			motor[lPivot] = (-127 + pivotspeed);
	//		}
}

void armHold () {

	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;

}

void pivotRest () {

	motor[lPivot] = 0;
	motor[rPivot] = 0;

}



//////////////////////////// PRE- AUTONOMOUS ///////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

//////////////////////////// AUTONOMOUS ////////////////////////////////////////////

task autonomous()
{

	/* Strategy
	0. Lower shovel
	1. Rotate 90* CCW
	2. Drive forward
	3. Raise shovel and arm
	4. Rotate 90* CW
	5. Drive towards fence
	6. Throw stars down
	7. Move sideways
	*/

	backward();
	wait1Msec(150);
	rest();

	// turn shovel down
	int lPivotSensor = (4096 - (SensorValue[lPivotPot] + lPOffset)); // LARM MINUS THE OFFSER (TO CALIBRATE)
	int rPivotSensor = (SensorValue[rPivotPot] - rPOffset); // ALSO NEGATES THE POTENTIOMETER

	while (rPivotSensor < 1720)
	{
		motor[lPivot] = -127;
		motor[rPivot] = -127;
		lPivotSensor = (4096 - (SensorValue[lPivotPot] - lPOffset)); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rPivotSensor = (SensorValue[rPivotPot] - rPOffset); // ALSO NEGATES THE POTENTIOMETER
	}
	motor[rPivot] = 0;
	motor[lPivot] = 0;

	ClearTimer(T1);
	// move forward, pick up star

	while (time1[T1] < 1600)
	{
		forward();
	}
	rest();

	// initialize arm

	int lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
	int rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER

	// raise arm
		motor[lPivot] = 28;
		motor[rPivot] = 28;

	while (lArm < 1200)
	{
		motor[lArmMotor] = 127;
		motor[rArmMotor] = 127;
		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
	}
	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;
	wait1Msec(250);
	motor[lPivot] = -32;
	motor[rPivot] = -32;
	wait1Msec(60);
	motor[lPivot] = 10;
	motor[rPivot] = 10;


	clearTimer(T4);
	while (time1[T4] < 1650)
	{
		backward();
	}

	rest();

	// turn and goto fence

	ClearTimer(T2);

	while (time1[T2] < 400)
	{
		cw();
	}
	rest();

	wait1Msec(100);

	ClearTimer(T3);

	while (time1[T3] < 3250)
	{
		backward();
	}

	rest();

	while (lArm < 2000)
	{
		motor[lArmMotor] = 127;
		motor[rArmMotor] = 127;
		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
	}

	ClearTimer(T1);
	while (time1[T1] < 500)
	{
		motor[lPivot] = 127;
		motor[rPivot] = 127;
	}

	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;
	motor[lPivot] = 0;
	motor[rPivot] = 0;

}



/////////////////////////// USER CONTROL ///////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{

		// Assign sensor inputs to variables
		int lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
		int rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
		int lPivotSensor = (4096 - (SensorValue[lPivotPot] + lPOffset)); // LARM MINUS THE OFFSER (TO CALIBRATE)
		int rPivotSensor = (SensorValue[rPivotPot] + rPOffset); // ALSO NEGATES THE POTENTIOMETER

		int motorspeed = sqrt( (lArm - rArm)*(lArm - rArm) ); // Create variable to change motor speed based on how different the readings are
		int pivotspeed = sqrt( (lPivotSensor - rPivotSensor)*(lPivotSensor - rPivotSensor) );

		//Right side of the robot is controlled by the right joystick, Y-axis
		motor[rFrontMotor] = vexRT[Ch2];
		motor[rBackMotor]  = vexRT[Ch2];
		//Left side of the robot is controlled by the left joystick, Y-axis
		motor[lFrontMotor] = vexRT[Ch3];
		motor[lBackMotor]  = vexRT[Ch3];

		//  if (vexRT[Btn7R])
		//{
		//	motor[rArmMotor] = 127;
		//}
		//if (vexRT[Btn7U])
		//{
		//	motor[lArmMotor] = 127;
		//}
		//if (vexRT[Btn7L])
		//{5
		//	motor[lArmMotor] = 127;
		//}


		rPivotCalibrated = ((SensorValue[rPivotPot])-1250);
		difference = rArm - rPivotCalibrated;




		if (vexRT[Btn8D] == 1)
		{
			armMode = 1;
		}

		else if (vexRT[Btn8L] == 1)
		{
			armMode = 2;
		}
		else
		{
			armMode = 0;
		}


		// MACRO PROGRAMS

		while (((SensorValue[rArmPot] + SensorValue[LArmPot])/2 > 120) && (armMode == 1))
		{

			lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
			rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER


			if (SensorValue[rArmPot] > 150)
			{
				armDown(lArm, rArm, motorspeed);
			}

			if (SensorValue[rArmPot] < 150)
			{
				armUp(lArm, rArm, motorspeed);
			}

		}
		// COMPARATORS INVERTED
		if ((armMode == 2) && (((SensorValue[rArmPot] + SensorValue[lArmPot])/2 > 1500)|| ((SensorValue[rArmPot] + SensorValue[lArmPot])/2 < 1000)))
		{

			lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
			rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER


			if (SensorValue[rArmPot] > 1200)
			{
				armDown(lArm, rArm, motorspeed);
			}

			if (SensorValue[rArmPot] < 1200)
			{
				armUp(lArm, rArm, motorspeed);
			}
		}




		// ARM PROGRAM

		else if (vexRT[Btn7R] == 1)
		{
			motor[rArmMotor] = -127;
			motor[rArmMotor2] = -127;
		}
		else if (vexRT[Btn7L] == 1)
		{
			motor[lArmMotor] = -127;
			motor[lArmMotor2] = -127;
		}


		else if (vexRT[Btn6U] == 1)
		{
			 armUp(lArm, rArm, motorspeed);
			//armUpNoPot();
		}

		else if (vexRT[Btn6D] == 1)
		{
			 armDown(lArm, rArm, motorspeed);
			//armDownNoPot();
		}


		else
		{
			//armHold();
			motor[lArmMotor2] = 0;
			motor[rArmMotor2] = 0;
			motor[lArmMotor] = 0;
			motor[rArmMotor] = 0
		}


		////////////////////////PIVOT//////////////////

		if (vexRT[Btn7U] == 1)
		{
			pivotHold = 1;
		}
		if (vexRT[Btn7D] == 1)
		{
			pivotHold = 0;
		}



		if (armMode == 2)
		{
			if ((SensorValue[rPivotPot]) < 1500)
			{
				pivotDown(lPivotSensor, rPivotSensor, pivotspeed);
			}
			else if ((SensorValue[rPivotPot]) > 2400)
			{
				pivotUp(lPivotSensor, rPivotSensor, pivotspeed);
			}
			else
			{
				pivotRest();
			}
		}

		else if (vexRT[Btn5U] == 1)
		{
			pivotUp(lPivotSensor, rPivotSensor, pivotspeed);
		}

		else if (vexRT[Btn5D] == 1)
		{
			pivotDown(lPivotSensor, rPivotSensor, pivotspeed);
		}

		//	else if ((difference > 150) && (sensorValue[rArmPot] < 2300)) { // shovel greater then arm
		//	motor[rPivot] = (difference/-2);
		//	motor[lPivot] = (difference/-2);
		//}

		//	else if ((difference < -100) && (sensorValue[rArmPot] < 2300)) { // shovel smaller then arm
		//	motor[rPivot] = (difference/-2);
		//	motor[lPivot] = (difference/-2);
		//}

	else if (pivotHold == 0)
		{
			pivotRest();
		}

		else
		{
			motor[lPivot] = -20;
			motor[rPivot] = -20;
		}
	}
}

/* Changelogs

v1.0.0 		2016-11-01		Created 4 motor drive program
v1.0.1		2016-11-01		Reversed right motors
v2.0.0		2016-11-02		Started arm motor program
v2.0.1		2016-11-02		Added pragma config for arms
v2.1.0		2016-11-02		Added code for arm to go up based on buttons
v2.1.1		2016-11-03		Added potentiometers into pragma config
v3.0.0		2016-11-04		Potentiometer code active
v3.1.0		2016-11-07		Changed joystick buttons
v3.2.0		2016-11-07		Added variables for offset, included potentiometer readings into loop
v3.2.x		2016-11-07		Attempt to fix potentiometers
v4.x.x		2016-11-07		New potentiometer code attempts
v5.0.0		2016-11-07		Working potentiometer code
v5.1.0		2016-11-08		changed ports for base
v5.2.0		2016-11-08		Pivot (without potentiometers) added
v6.0.0		2016-11-13		Switched code to competition template
v6.1.x		2016-11-13		Autonomous timings calculate
v6.2.x		2016-11-13		Autonomous strategy changes
v7.0.x		2016-11-14		Macro key programming

*/
