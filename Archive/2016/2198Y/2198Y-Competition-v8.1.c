#pragma config(Sensor, in1,    lArmPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    rArmPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    lPivotPot,      sensorPotentiometer)
#pragma config(Sensor, in4,    rPivotPot,      sensorPotentiometer)
#pragma config(Motor,  port1,           lBackMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rFrontMotor,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rBackMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           lArmMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           rArmMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           lPivot,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           rPivot,        tmotorVex393, openLoop)
#pragma config(Motor,  port10,          lFrontMotor,   tmotorVex393, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// 2198Y Drive Program
// Last Updated by Tony T

	int lOffset = 220;
	int rOffset = 0;
	int lPOffset = 0;
	int rPOffset = 0;
	int pivotHold = 0;
	int armMode = 0;
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
	int lPOffset = 0;
	int rPOffset = 0;

	// turn shovel down
	int lPivotSensor = (4096 - (SensorValue[lPivotPot] + lPOffset)); // LARM MINUS THE OFFSER (TO CALIBRATE)
  int rPivotSensor = (SensorValue[rPivotPot] - rPOffset); // ALSO NEGATES THE POTENTIOMETER

	while (rPivotSensor < 2420)
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

	while (time1[T1] < 1250)
	{
	motor[rFrontMotor] = 127;
	motor[rBackMotor] = 127;
	motor[lFrontMotor] = 127;
	motor[lBackMotor] = 127;
	}
	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;

	// initialize arm

	int lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
  int rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER

  // raise arm

  while (lArm < 1200)
	{
	motor[lArmMotor] = -127;
	motor[rArmMotor] = -127;
	motor[lPivot] = 36;
	motor[rPivot] = 36;
	lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
  rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
	}

	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;
	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;
	motor[lPivot] = -32;
	motor[rPivot] = -32;
	wait1Msec(60);
	motor[lPivot] = 20;
	motor[rPivot] = 20;


	clearTimer(T4);
	while (time1[T4] < 2000)
	{
	motor[rFrontMotor] = -63;
	motor[rBackMotor] = -63;
	motor[lFrontMotor] = -63;
	motor[lBackMotor] = -63;
	}


	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;

	// turn and goto fence

	ClearTimer(T2);

		while (time1[T2] < 340)
	{
	motor[rFrontMotor] = -63;
	motor[rBackMotor] = -63;
	motor[lFrontMotor] = 63;
	motor[lBackMotor] = 63;
	}
	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;

	wait1Msec(100);

	ClearTimer(T3);

		while (time1[T3] < 2500)
	{
	motor[rFrontMotor] = -127;
	motor[rBackMotor] = -127;
	motor[lFrontMotor] = -115;
	motor[lBackMotor] = -115;
	}

	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;

	while (lArm < 2000)
	{
	motor[lArmMotor] = -127;
	motor[rArmMotor] = -127;
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
  //{
  //	motor[lArmMotor] = 127;
  //}





if (vexRT[Btn8D] == 1)
  {
  	armMode = 1;
}

else if (vexRT[Btn8L] == 1)
  {
  	armMode = 2;
}


		// MACRO PROGRAMS

  	while (((SensorValue[rArmPot] + SensorValue[LArmPot])/2 > 250) && (armMode == 1))
		{
		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
  	rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER

  	if (lArm == rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = 127;
		}

		else if (lArm > rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = (127 - motorspeed/3);
		}

		else if (lArm < rArm) {
			motor[rArmMotor] = (127 - motorspeed/3);
			motor[lArmMotor] = 127;
		}

}
	// COMPARATORS INVERTED
	while ((armMode == 2) && (((SensorValue[rArmPot] + SensorValue[lArmPot])/2 > 1300)|| ((SensorValue[rArmPot] + SensorValue[lArmPot])/2 < 1100))
	{
		if (SensorValue[rArmPot] > 1200)
		{

		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
  	rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER

  	if (lArm == rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = 127;
		}

		else if (lArm > rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = (127 - motorspeed/3);
		}

		else if (lArm < rArm) {
			motor[rArmMotor] = (127 - motorspeed/3);
			motor[lArmMotor] = 127;
		}


	}

	if (SensorValue[rArmPot] < 1200)
	{
		if (lArm == rArm)
			{
			motor[rArmMotor] = -127;
			motor[lArmMotor] = -127;
		}

		else if (lArm < rArm)
			{
			motor[rArmMotor] = (-127 + motorspeed/3);
			motor[lArmMotor] = -127;
		}

		else if (lArm > rArm)
			{
			motor[rArmMotor] = -127;
			motor[lArmMotor] = (-127 + motorspeed/3);
		}
	}
}


	// ARM PROGRAM

	if (vexRT[Btn6D] == 1)
	{
		if (lArm == rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = 127;
		}

		else if (lArm > rArm)
			{
			motor[rArmMotor] = 127;
			motor[lArmMotor] = (127 - motorspeed);
		}

		else if (lArm < rArm) {
			motor[rArmMotor] = (127 - motorspeed);
			motor[lArmMotor] = 127;
		}
		armMode = 0;
	}

	else if (vexRT[Btn6U] == 1)
	{
		if (lArm == rArm)
			{
			motor[rArmMotor] = -127;
			motor[lArmMotor] = -127;
		}

		else if (lArm > rArm)
			{
			motor[rArmMotor] = (-127 + motorspeed);
			motor[lArmMotor] = -127;
		}

		else if (lArm < rArm)
			{
			motor[rArmMotor] = -127;
			motor[lArmMotor] = (-127 + motorspeed);
		}
		armMode = 0;
	}

   else
     {
	   motor[lArmMotor] = 0;
	   motor[rArmMotor] = 0;
	   armMode = 0;
   }

   if (vexRT[Btn7U] == 1)
   {
     pivotHold = 1;
  }
  if (vexRT[Btn7D] == 1)
   {
     pivotHold = 0;
  }

  	if (vexRT[Btn5U] == 1)
  	{
  	motor[lPivot] = 127;
  	motor[rPivot] = 127;
  	}

  	else if (vexRT[Btn5D] == 1)
  	{
		motor[rPivot] = -127;
		motor[lPivot] = -127;
		}

		else if (pivotHold == 0)
    {
    motor[lPivot] = 0;
  	motor[rPivot] = 0;
  	}


		else
		{
		motor[lPivot] = 30;
		motor[rPivot] = 30;
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
