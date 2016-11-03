#pragma config(Motor,  port1,           frontRight,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontTshoot,   tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port3,           backTshoot,    tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           Intakes,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           conveyor,      tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port8,           frontBshoot,   tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port9,           backBshoot,    tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port10,          backRight,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;
int speed = 108;
int autospeed=100;
bool pressed = true;

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

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
  ClearTimer(T1);
	while (time1[T1]<15000)
	{
		motor[frontTshoot]=autospeed;
		motor[backTshoot]=autospeed;
	  motor[frontBshoot]=autospeed;
	  motor[backBshoot]=autospeed;

		if (time1[T1]>3550 && time1[T1]<4100)
		{
			motor[conveyor] = 80;
		}

		else if (time1[T1]>6600 && time1[T1]<7175)
		{
			motor[conveyor] = 127;
		}

		else if (time1[T1]>9700 && time1[T1]<10300)
		{
			motor[conveyor] = 127;
		}

		else if (time1[T1]>10300 && time1[T1]<10301)
		{
			autospeed=100;
		}

		else if (time1[T1]>12900 && time1[T1]<13400)
		{
			motor[conveyor] = 100;
		}
		else
		{
			motor[conveyor]=0;
		}
	}
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
	  //Create "deadzone" for Y1/Ch3
		if(abs(vexRT[Ch3]) > threshold)
			Y1 = vexRT[Ch3];
		else
			Y1 = 0;
		//Create "deadzone" for X1/Ch4
		if(abs(vexRT[Ch4]) > threshold)
			X1 = vexRT[Ch4];
		else
			X1 = 0;
		//Create "deadzone" for X2/Ch1
		if(abs(vexRT[Ch1]) > threshold)
			X2 = vexRT[Ch1];
		else
			X2 = 0;

		//Remote Control Commands
		motor[frontRight] = Y1 - X2 - X1;
		motor[backRight] =  Y1 - X2 + X1;
		motor[frontLeft] = Y1 + X2 + X1;
		motor[backLeft] =  Y1 + X2 - X1;

		//Conveyor and intake controls

			if (vexRT[Btn6U]==1)
			{
				motor[conveyor]=80;
			}
			else if (vexRT[Btn8L]==1)
			{
				motor[conveyor]=-100;
			}
			else if (vexRT[Btn8U]==1)
			{
				motor[conveyor]=45;
			}
			else
			{
				motor[conveyor]=0;
			}


			if (vexRT[Btn6D]==1)
			{
				motor[Intakes]=127;
			}
			else if (vexRT[Btn8D]==1)
			{
				motor[Intakes]=-127;
			}
			else
			{
				motor[Intakes]=0;
			}

			//speed controls



			if (vexRT[Btn7L]==1 && pressed==true && speed>0)
			{
				speed--;
				pressed=false;
			}
			else if (vexRT[Btn7R]==1 && pressed==true && speed<120)
			{
				speed++;
				pressed=false;
			}
			if (vexRT[Btn7L]==0 && vexRT[Btn7R]==0)
			{
				pressed=true;
			}

			//shooter controls



			if (vexRT[Btn5U]==1)
			{
				motor[frontTshoot]=speed;
				motor[backTshoot]=speed;
	    	motor[frontBshoot]=speed;
	    	motor[backBshoot]=speed;
	 	 	}
			else if (vexRT[Btn5D]==1)
			{

				motor[frontTshoot]=speed-3;
				motor[backTshoot]=speed-23;
	    	motor[frontBshoot]=speed-3;
	   		motor[backBshoot]=speed-23;

	  	}
	  	else if (vexRT[Btn8R]==1)
			{

				motor[frontTshoot]=speed-6;
				motor[backTshoot]=speed-6;
	    	motor[frontBshoot]=speed-6;
	   		motor[backBshoot]=speed-6;

	  	}
	  	else
	  	{
	  		motor[frontTshoot]=0;
				motor[backTshoot]=0;
	    	motor[frontBshoot]=0;
	    	motor[backBshoot]=0;
			}

	}
}