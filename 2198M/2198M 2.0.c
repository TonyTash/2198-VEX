#pragma config(Motor,  port1,           leftCollector, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port2,           right1,        tmotorVex393, openLoop)
#pragma config(Motor,  port3,           right2,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           right3,        tmotorVex393, openLoop)
#pragma config(Motor,  port5,           left1,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           left2,         tmotorVex393, openLoop)
#pragma config(Motor,  port7,           left3,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           towerLeft,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           towerRight,    tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightCollector, tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}



task autonomous()
{

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}



task usercontrol()
{

	while (true)
	{
		//tank drive
	  motor[right1] = vexRT[Ch2];
	  motor[right3] = vexRT[Ch2];
	  motor[right2] = vexRT[Ch2];
	  motor[left1] = vexRT[Ch3];
	  motor[left2] = vexRT[Ch3];
	  motor[left3] = vexRT[Ch3];

	  //tower
	  if(vexRT[Btn8U] == 1 && vexRT[Btn8R] == 1)
    {
    	if(vexRT[Btn5U] == 1)
    		motor[towerLeft] = 127;
    	else if(vexRT[Btn5D] == 1)
    		motor[towerLeft] = -127;
    	else
    		motor[towerLeft] = 0;
    	if(vexRT[Btn6U] == 1)
    		motor[towerRight] = 127;
    	else if(vexRT[Btn6D] == 1)
    		motor[towerRight] = -127;
    	else
    		motor[towerRight] = 0;
  	}
	  else if(vexRT[Btn5U] == 1)
	  {
	  	motor[towerLeft] = 127;
	  	motor[towerRight] = 127;
	  }
	  else if(vexRT[Btn5D] == 1)
	  {
	  	motor[towerLeft] = -127;
	  	motor[towerRight] = -127;
	  }
	  else
	  {
	  	motor[towerLeft] = 0;
	  	motor[towerRight] = 0;
	  }
	  //collector
	  if(vexRT[Btn7L] == 1)
	  {
	  	motor[leftCollector] = 127;
	  	motor[rightCollector] = 127;
	  }
	  else if(vexRT[Btn7R] == 1)
	  {
	  	motor[leftCollector] = -127;
	  	motor[rightCollector] = -127;
	  }
	  else
	  {
	  	motor[leftCollector] = 0;
	  	motor[rightCollector] = 0;
	  }

	}
}
