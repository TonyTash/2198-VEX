#pragma config(Motor,  port2,           rFrontMotor,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rBackMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           lFrontMotor,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           lBackMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           lArm,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           rArm,          tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// 2198Y Drive Program
// Last Updated by Tony T on 2016-11-02

task main()
{
  while(1 == 1)
  {
    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[rFrontMotor] = vexRT[Ch2];
    motor[rBackMotor]  = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[lFrontMotor] = vexRT[Ch3];
    motor[lBackMotor]  = vexRT[Ch3];

    if


  }
}

/* Changelogs

v1.0.0 		2016-11-01		Created 4 motor drive program
v1.0.1		2016-11-01		Reversed right motors
v2.0.0		2016-11-02		Started arm motor program
v2.0.1		2016-11-02		Added pragma config for arms
*/
