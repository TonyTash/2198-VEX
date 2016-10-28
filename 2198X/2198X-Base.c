#pragma config(Motor,  port2,           frontLeftMotor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           frontRightMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port4,           backLeftMotor,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           backRightMotor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           sidewaysMotor,   tmotorVex393, openLoop, reversed)

// 2198X User Control Drive Program

task main()
{

  while(1 == 1) // Loop following indefinetly
  {
    //Right side of the robot is controlled by the left joystick, Y-axis, minus the rotation from the x axis
    motor[frontRightMotor] = (vexRT[Ch3] - vexRT[Ch1]);
    motor[backRightMotor]  = (vexRT[Ch3] - vexRT[Ch1]);
    //Left side of the robot is controlled by the left joystick, Y-axis, plus the rotation from the x axis
    motor[frontLeftMotor] = (vexRT[Ch3] + vexRT[Ch1]);
    motor[backLeftMotor]  = (vexRT[Ch3] + vexRT[Ch1]);

    motor[sidewaysMotor] = vexRT[Ch4]; // Allows the robot to move sideways, based on the


	}

}
