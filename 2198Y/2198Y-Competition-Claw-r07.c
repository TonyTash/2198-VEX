#pragma config(Sensor, in1,    lArmPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    rArmPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    lPivotPot,      sensorPotentiometer)
#pragma config(Sensor, in4,    rPivotPot,      sensorPotentiometer)
#pragma config(Sensor, in5,    pExpander,      sensorAnalog)
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

// 2198Y Claw Robot Program for Missisauga Competition


// DECLERATION OF VARIABLES

int lOffset = 240; 	// Offset the left potentiometer to calibrate to 0
int rOffset = 0;		// Offset the right potentiometer to calibrate to left
int lPOffset = 0;		// Offset left pivot/claw potentiometer to calibrate to 0
int rPOffset = 300;	// Offset right pivot/claw potentiometer to calibrate to 0
int pivotHold = 0;	// Pivot/claw hold mechanism activation (set by remote later)
int armMode = 0;		// Depreceted function: Arm mode (auto/joystick)
int rPivotCalibrated = 0;	// Value of right pivot/claw potentiometer after reversed
int difference = 0;	// Difference in potentiometer value between two arms
int armLock = 0;
int speed = 63;

// END OF VARIABLE DECLERATION

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!



void forward() // Move forward (autonomous)
{
	motor[lFrontMotor] = 127;
	motor[lBackMotor] = 127;
	motor[rFrontMotor] = 127;
	motor[rBackMotor] = 127;
}

void backward() // Move backward (autonomous)
{
	motor[lFrontMotor] = -127;
	motor[lBackMotor] = -127;
	motor[rFrontMotor] = -115;
	motor[rBackMotor] = -115;
}

void rest() // Stop moving (autonomous)
{
	motor[lFrontMotor] = 0;
	motor[lBackMotor] = 0;
	motor[rFrontMotor] = 0;
	motor[rBackMotor] = 0;
}

void cw()	// Rotate clockwise
{
	motor[lFrontMotor] = 127;
	motor[lBackMotor] = 127;
	motor[rFrontMotor] = -127;
	motor[rBackMotor] = -127;
}

void ccw() // Rotate counterclockwise
{
	motor[lFrontMotor] = -127;
	motor[lBackMotor] = -127;
	motor[rFrontMotor] = 127;
	motor[rBackMotor] = 127;
}

void armUp(int lArm, int rArm, int motorspeed) // Bring arm up
{
	if (lArm == rArm) // If both potentiometers are equal, go up at the same speed
	{
		motor[rArmMotor] = 127;
		motor[lArmMotor] = 127;
		motor[rArmMotor2] = 127;
		motor[lArmMotor2] = 127;
	}

	else if (lArm > rArm) // If left arm is higher then right arm (when going up),
	{
		motor[rArmMotor] = 127; 									// Right arm (slower arm) continues to go up full speed
		motor[lArmMotor] = (127 - motorspeed/2); 	// Slow the left arm by the difference between the two
		motor[rArmMotor2] = 127;
		motor[lArmMotor2] = (127 - motorspeed/2);
	}

	else if (lArm < rArm) // If the right arm is higher then the left arm
		{
		motor[rArmMotor] = (127 - motorspeed/2);	// Slow the right arm down by the difference between the two
		motor[lArmMotor] = 127; 									// Left arm (slower arm) continues to go up full speed
		motor[rArmMotor2] = (127 - motorspeed/2);
		motor[lArmMotor2] = 127;
	}
}

void armUpNoPot(int speed) // Raise arm, without using any potentiometer code
{
	motor[lArmMotor] = speed;
	motor[rArmMotor] = speed;
	motor[lArmMotor2] = speed;
	motor[rArmMotor2] = speed;
}

void armDownNoPot(int speed) // Lower arm, without using potentiometer code
{
	motor[lArmMotor] = (speed * -1);
	motor[rArmMotor] = (speed * -1);
	motor[lArmMotor2] = (speed * -1);
	motor[rArmMotor2] = (speed * -1);
}


void armDown(int lArm, int rArm, int motorspeed) // Lower the arm, using the potentiometers
{
		if (lArm == rArm) // If both arms are at equal height
			{
				motor[rArmMotor] = -127; // Power all motors equally
				motor[lArmMotor] = -127;
				motor[rArmMotor] = -127;
				motor[lArmMotor] = -127;
			}

			else if (lArm > rArm) // If the right arm is lower then the left arm
			{
				motor[rArmMotor] = (-127 + motorspeed/2); // Slow the right arm by the difference between the arms
				motor[lArmMotor] = -127; 									// Run left arm at full speed (higher arm)
				motor[rArmMotor] = (-127 + motorspeed/2);
				motor[lArmMotor] = -127;
			}

			else if (lArm < rArm) // If the left arm is lower then the right arm
			{
				motor[rArmMotor] = -127;									// Run the right arm (higher) at full speed
				motor[lArmMotor] = (-127 + motorspeed/2);	// Slow the left arm the the difference between the arms
				motor[rArmMotor] = -127;
				motor[lArmMotor] = (-127 + motorspeed/2);
			}
}

void pivotUp() // Raise pivot & close claws
{

			// TEMPORARILY DISABLED POTENTIOMETER CODE FOR TESTING PURPOSES

				motor[lPivot] = 127;
				motor[rPivot] = 127;

			//if (lPivotSensor == rPivotSensor)
			//{
			//	motor[lPivot] = 127;
			//	motor[rPivot] = 127;
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

void pivotDown()  // Lower pivot & open claws
{

	motor[lPivot] = -127;
	motor[rPivot] = -127;

	// TEMPORARILY DISABLED POTENTIOMETER CODE FOR TESTING PURPOSES


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

void armHold () {		// Turn off arm motors

	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;

	motor[lArmMotor2] = 0;
	motor[rArmMotor2] = 0;

}

void pivotRest () { // Turn off the pivot motors

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

// Claw potentiometer
// Open wide: 639, 2204
// Open fully: 273, 1812
// Open: 1095, 2730
// Closed: 1970, 3739
// Touching: 2090, 3870

// Arm Potentiometer
// Down: 240, 0
// Off ground: 246, 1
// Parallel: 700, 925
// near fence: 246, 1884
// Perfect fence: 2160, 2488
// Stop:2000, 2200

// Cube autonomous

/*

	pivotUp();
	forward();
	wait1Msec(1000);
	pivotDown();
	rest();
	wait1Msec(1200);
	motor[lPivot] = -30;
	motor[rPivot] = -30;

	// ccw - right side
	// cc - left side

	ccw();
	wait1Msec(1450);
	backward();

	wait1Msec(1200);
	rest();


		while (SensorValue[rArmPot] < 1800) // Raise the arm until the potentiometer reads 1200 (travelling height)
	{
	  armUpNoPot(127);
	}
		while (SensorValue[rArmPot] < 2400) // Raise the arm until the potentiometer reads 1200 (travelling height)
	{
	  armUpNoPot(127);
	 	pivotUp();
	}
	backward();
	armHold();
	wait1Msec(650);
	rest();
	pivotRest();
wait1Msec(100);
cw();
wait1Msec(500);
backward();
wait1Msec(500);
rest();

*/

// Knock Star Autonomous

/*

forward();
pivotUp();
wait1Msec(750);
rest();
pivotDown();

*/


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


	/* Old autonomous

	backward(); // Move backwards to avoid hitting fence w/ back tipping mechanism
	wait1Msec(150);
	rest();		// Stop moving

	// Update shovel potentiometers
	int lPivotSensor = (4096 - (SensorValue[lPivotPot] + lPOffset)); // LARM MINUS THE OFFSET (TO CALIBRATE)
	int rPivotSensor = (SensorValue[rPivotPot] - rPOffset); // ALSO NEGATES THE POTENTIOMETER

	while (rPivotSensor < 1720) // Bring shovel down, until potentiometer is at 1720 (parallel to ground)
	{
		motor[lPivot] = -127;
		motor[rPivot] = -127;
		// Update the pivot sensors
		lPivotSensor = (4096 - (SensorValue[lPivotPot] - lPOffset)); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rPivotSensor = (SensorValue[rPivotPot] - rPOffset); // ALSO NEGATES THE POTENTIOMETER
	}
	motor[rPivot] = 0;
	motor[lPivot] = 0;

	ClearTimer(T1); // Reset the timer

	// Move for 1.6s, picking up the three stars in the center

	while (time1[T1] < 1600) // Move forward for 1.6 seconds
	{
		forward();
	}
	rest(); // Stop moving after 1.6s

	// initialize arm by updating sensor values

	int lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
	int rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER

	// Run pivot slowly to prevent dropping stars
		motor[lPivot] = 28;
		motor[rPivot] = 28;

	while (lArm < 1200) // Raise the arm until the potentiometer reads 1200 (travelling height)
	{
		motor[lArmMotor] = 127; // Raise the arm
		motor[rArmMotor] = 127;

		//Update sensor values
		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
	}

	armHold(); // Stop raising arm
	wait1Msec(250); // Wait 250ms

	// Lower pivot to not drop
	motor[lPivot] = -32;
	motor[rPivot] = -32;
	wait1Msec(60);

	// Continue slightly powering to hold position
	motor[lPivot] = 10;
	motor[rPivot] = 10;

	// Move backwards until starting tile
	clearTimer(T4);
	while (time1[T4] < 1650)
	{
		backward();
	}

	// Stop moving once on starting tile
	rest();


	ClearTimer(T2); // Clear timer for rotating

	while (time1[T2] < 400) // Rotate clockwise for 400 ms
	{
		cw();
	}

	rest(); // Stop moving to not jerk motion

	wait1Msec(100);

	ClearTimer(T3);

	while (time1[T3] < 3250) // Move backwards until touching the fence
	{
		backward();
	}

	rest(); // Stop moving once at fence

	while (lArm < 2000) // Raise arm more to drop star
	{
		motor[lArmMotor] = 127;
		motor[rArmMotor] = 127;

		// update potentiometer readings
		lArm = (SensorValue[lArmPot] + lOffset); // LARM MINUS THE OFFSER (TO CALIBRATE)
		rArm = (SensorValue[rArmPot] + rOffset); // ALSO NEGATES THE POTENTIOMETER
	}

	ClearTimer(T1);
	while (time1[T1] < 500) // Raise pivot to ensure stars fall
	{
		motor[lPivot] = 127;
		motor[rPivot] = 127;
	}

	// Stop moving
	motor[lArmMotor] = 0;
	motor[rArmMotor] = 0;
	motor[lPivot] = 0;
	motor[rPivot] = 0;

}
	*/

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

		// Set the difference between the two sensor values
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


		rPivotCalibrated = ((SensorValue[rPivotPot])-1250); // Negated and calibrated pivot potentiometers
		difference = rArm - rPivotCalibrated;


		if (vexRT[Btn8U] == 1) {
			armLock = 1;
	}
		else if (vexRT[Btn8D] == 1){
			armLock = 0;
		}



		// Arm with direct user control


		if (SensorValue[lArmPot] > 0) {

		if (vexRT[Btn6U] == 1) // Bring arm up
		{
			// armUp(lArm, rArm, motorspeed); // Using potentiometers
			armUpNoPot(127); // Without potentiometers
		}

		else if (vexRT[Btn6D] == 1)	// Bring arm down
		{
			 //armDown(lArm, rArm, motorspeed); // Using potentiometers
			armDownNoPot(127);	// WItout potentiometers
		}

		else if (armLock == 1) {
			motor[lArmMotor2] = 30;
			motor[rArmMotor2] = 30;
			motor[lArmMotor] = 30;
			motor[rArmMotor] = 30;
}

		else
		{
			//armHold();
			motor[lArmMotor2] = 0;
			motor[rArmMotor2] = 0;
			motor[lArmMotor] = 0;
			motor[rArmMotor] = 0;
		}
	}

		else	if (vexRT[Btn7R] == 1) // Bring right arm down (manual calibration)
		{
			motor[rArmMotor] = -127;
			motor[rArmMotor2] = -127;
		}
		else if (vexRT[Btn7L] == 1) // Bring left arm down (manual calibration)
		{
			motor[lArmMotor] = -127;
			motor[lArmMotor2] = -127;
		}

		else if (vexRT[Btn6U] == 1) {
	armUpNoPot(127);
	}
else {
		motor[lArmMotor2] = 36;
		motor[rArmMotor2] = 36;
		motor[lArmMotor] = 36;
		motor[rArmMotor] = 36;
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





		if (vexRT[Btn5U] == 1)
		{
			pivotUp();
		}

		else if (vexRT[Btn5D] == 1)
		{
			pivotDown();
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
