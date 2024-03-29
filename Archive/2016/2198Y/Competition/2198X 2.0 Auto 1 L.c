#pragma config(Sensor, in1,    armSensor,      sensorPotentiometer)
#pragma config(Sensor, in2,    clawSensor,     sensorPotentiometer)
#pragma config(Sensor, in3,    powerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  leftWheelsSensor, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightWheelsSensor, sensorQuadEncoder)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           backRight,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           claw1,         tmotorVex393, openLoop)
#pragma config(Motor,  port4,           towerAB,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           lock,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           towerCD,       tmotorVex393, openLoop)
#pragma config(Motor,  port9,           claw2,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          tower,         tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


/////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////Robot Functions/////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//
/////////////////////////////Forward///////////////////////////////
//
///////////////////////////////////////////////////////////////////
void forwardAuto(int speed)//distance in positive, remember to set sensor value to zero if needed; speed in positive
{
		if(SensorValue[leftWheelsSensor] > SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = speed - (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[frontLeft] = speed - (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[backRight] = speed;
			motor[frontRight] = speed;
		}
		else if(SensorValue[leftWheelsSensor] < SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = speed;
			motor[frontLeft] = speed;
			motor[backRight] = speed - (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[frontRight] = speed - (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
		}
		else if(SensorValue[leftWheelsSensor] == SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = speed;
			motor[frontLeft] = speed;
			motor[backRight] = speed;
			motor[frontRight] = speed;
		}
}

///////////////////////////////////////////////////////////////////
//
/////////////////////////////Backward//////////////////////////////
//
///////////////////////////////////////////////////////////////////
void backwardAuto(int speed)//distance in negative, remember to set sensor value to zero if needed; speed in positive
{
		if(SensorValue[leftWheelsSensor] > SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = -speed;
			motor[frontLeft] = -speed;
			motor[backRight] = -speed + (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[frontRight] = -speed + (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
		}
		else if(SensorValue[leftWheelsSensor] < SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = -speed + (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[frontLeft] = -speed + (abs((SensorValue[leftWheelsSensor]) - (SensorValue[rightWheelsSensor])));
			motor[backRight] = -speed;
			motor[frontRight] = -speed;
		}
		else if(SensorValue[leftWheelsSensor] == SensorValue[rightWheelsSensor])
		{
			motor[backLeft] = -speed;
			motor[frontLeft] = -speed;
			motor[backRight] = -speed;
			motor[frontLeft] = -speed;
		}
}

void stopMoving()
{
	motor[frontLeft] = 0;
	motor[backLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
}



void ccwRotationBothSide(int degree, int speed)//degree in positive, and speed in positive for both side, program will set them to negative
{
	int distance = 6*degree/2;
	while(SensorValue[leftWheelsSensor] > -distance && SensorValue[rightWheelsSensor] < distance)
	{
		motor[backLeft] = -speed;
		motor[frontLeft] = -speed;
		motor[backRight] = speed;
		motor[frontRight] = speed;
	}
}

void cwRotationBothSide(int degree,int speed)//degree in positive, and speed in positive for both side, program will set them to negative
{
	int distance = 6*degree/2;
	while(SensorValue[leftWheelsSensor] < distance && SensorValue[rightWheelsSensor] > -distance)
	{
		motor[backLeft] = speed;
		motor[frontLeft] = speed;
		motor[backRight] = -speed;
		motor[frontRight] = -speed;
	}
}






//pivot goes up
void up()
{
	motor[towerAB] = 127;
	motor[towerCD] = 127;
	motor[tower] = 127;
}

void upSlowly()
{
	motor[towerAB] = 30;
	motor[towerCD] = 30;
	motor[tower] = 30;
}

//pivot goes down
void down()
{
	motor[towerAB] = -127;
	motor[towerCD] = -127;
	motor[tower] = -127;
}

void downSlowly()
{
	motor[towerAB] = -18;
	motor[towerCD] = -18;
	motor[tower] = -18;
}

//pivot stays still
void holdArm()
{
	if (SensorValue[armSensor] > 600)
	{
		motor[towerAB] = 10;
		motor[towerCD] = 10;
		motor[tower] = 10;
	}
	else if(SensorValue[armSensor] < 600)
	{
		motor[towerAB] = 0;
		motor[towerCD] = 0;
		motor[tower] = 0;
	}
}

void clawClose(int clawSpeed)
{
	motor[claw1] = clawSpeed;
	motor[claw2] = clawSpeed;
}

void clawOpen(int clawSpeed)
{
	motor[claw1] = -clawSpeed;
	motor[claw2] = -clawSpeed;
}

void clawStop()
{
	motor[claw1] = 0;
	motor[claw2] = 0;
}





void defenseAuto()
{
	int clawAuto = 0;
	if(SensorValue[clawSensor] < 800)
		clawAuto = 1;
	else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
		clawAuto = 2;
	else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
		clawAuto = 0;
	else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
		clawAuto = 3;
	else if(SensorValue[clawSensor] >1700)
		clawAuto = 4;
	while(clawAuto == 1)
	{
		motor[claw1] = -40;
		motor[claw2] = -40;
		motor[backLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[frontLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[backRight] = 0 - SensorValue[rightWheelsSensor];
		motor[frontRight] = 0 - SensorValue[rightWheelsSensor];
		int clawAuto = 0;
		if(SensorValue[clawSensor] < 800)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
			clawAuto = 3;
		else if(SensorValue[clawSensor] >1700)
			clawAuto = 4;
	}
	while(clawAuto == 2)
	{
		motor[claw1] = -20;
		motor[claw2] = -20;
		motor[backLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[frontLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[backRight] = 0 - SensorValue[rightWheelsSensor];
		motor[frontRight] = 0 - SensorValue[rightWheelsSensor];
		if(SensorValue[clawSensor] < 800)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
			clawAuto = 3;
		else if(SensorValue[clawSensor] >1700)
			clawAuto = 4;
	}
	while(clawAuto == 3)
	{
		motor[claw1] = 40;
		motor[claw2] = 40;
		motor[backLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[frontLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[backRight] = 0 - SensorValue[rightWheelsSensor];
		motor[frontRight] = 0 - SensorValue[rightWheelsSensor];
		if(SensorValue[clawSensor] < 800)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
			clawAuto = 3;
		else if(SensorValue[clawSensor] >1700)
			clawAuto = 4;
	}
	while(clawAuto == 4)
	{
		motor[claw1] = 80;
		motor[claw2] = 80;
		motor[backLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[frontLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[backRight] = 0 - SensorValue[rightWheelsSensor];
		motor[frontRight] = 0 - SensorValue[rightWheelsSensor];
		if(SensorValue[clawSensor] < 800)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
			clawAuto = 3;
		else if(SensorValue[clawSensor] >1700)
			clawAuto = 4;
	}
	while(clawAuto == 0)
	{
		motor[claw1] = 0;
		motor[claw2] = 0;
		motor[backLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[frontLeft] = 0 - SensorValue[leftWheelsSensor];
		motor[backRight] = 0 - SensorValue[rightWheelsSensor];
		motor[frontRight] = 0 - SensorValue[rightWheelsSensor];
		if(SensorValue[clawSensor] < 800)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >800 && SensorValue[clawSensor] < 1230)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1230 && SensorValue[clawSensor] < 1330)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >1330 && SensorValue[clawSensor] < 1700)
			clawAuto = 3;
		else if(SensorValue[clawSensor] >1700)
			clawAuto = 4;
	}
}




/////////////////////////////////////////////////////////////////////////////////////////



void clearEncoders()
{
	SensorValue[leftWheelsSensor] = 0;
	SensorValue[rightWheelsSensor] = 0;
}

void pre_auton()
{
	//bLCDBacklight = true;
	//autonomousSelection();
	clearEncoders();
	motor[lock] = -30;
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	//prepare
	clearEncoders();
	while(SensorValue[armSensor] < 700)
	{
		up();
	}
	holdArm();
	while(SensorValue[clawSensor] > 1180)
	{
		clawClose(127);
	}
	clawStop();
	wait1Msec(150);
	while(SensorValue[armSensor] > 480)
	{
		down();
	}
	holdArm();
	while(SensorValue[leftWheelsSensor] < 700 && SensorValue[rightWheelsSensor] < 700)
	{
		forwardAuto(80);
	}
	stopMoving();
	clawClose(90);
	wait1Msec(150);
	clawClose(30);
	wait1Msec(250);
	while(SensorValue[armSensor] < 2300)
	{
		up();
	}
	holdArm();
	while(SensorValue[leftWheelsSensor] > 500 && SensorValue[rightWheelsSensor] > 500)
	{
		backwardAuto(30);
	}
	stopMoving();
	wait1Msec(150);
	clearEncoders();
	/////////////////////////////////////////////////////////
	//
	//
	//
	//
	//
	ccwRotationBothSide(110,65); //need to be tested !!!!
	//
	//
	//adjust the degree(120) so the robot can facing the left side fence
	//
	//
	//
	//
	///////////////////////////////////////////////////////////
	stopMoving();
	wait1Msec(300);
	clearEncoders();
	while(SensorValue[leftWheelsSensor] < 1350 && SensorValue[rightWheelsSensor] < 1350)
	{
		forwardAuto(90);
	}
	while(SensorValue[leftWheelsSensor] < 1600 && SensorValue[rightWheelsSensor] < 1600)
	{
		forwardAuto(90);
		clawOpen(127);
	}
	stopMoving();
	clawStop();
	/////////////////////////////////////////////////////////////////
	//
	//
	//
	//
	//
	//the following code need to be tested
	//let the robot knock off three stars on the left side fence, or at least two.
	//
	//
	//
	//
	//
	/////////////////////////////////////////////////////////////////
	while(SensorValue[clawSensor] < 1230)
	{
		clawOpen(90);
	}
	clawStop();
	/*
	while(SensorValue[armSensor] > 2300)
	{
		down();
	}
	holdArm();
	*/
	while(SensorValue[leftWheelsSensor] < 1650 && SensorValue[rightWheelsSensor] < 1650)
	{
		forwardAuto(90);
	}
	stopMoving();

	clawClose(60);
	wait1Msec(500);
	clawStop();

	while(SensorValue[leftWheelsSensor] > 1300 && SensorValue[rightWheelsSensor] > 1300)
	{
		backwardAuto(90);
	}
	stopMoving();
	ccwRotationBothSide(30,65); //need to be tested !!!!
	clawOpen(60);
	wait1Msec(500);
	clawStop();
	while(SensorValue[armSensor] > 2200)
	{
		down();
	}
	holdArm();
	while(SensorValue[leftWheelsSensor] < 1700 && SensorValue[rightWheelsSensor] < 1700)
	{
		forwardAuto(90);
	}

	stopMoving();
	wait1Msec(200);
	clawClose(60);
	wait1Msec(500);
	clawStop();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//
//                                 User Control Task
//
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	//StartTask (driverControlDisplayValue);
	while (true)
	{

//////////////////////////////////////////////////////
//
//
//                     driving
//
//
//////////////////////////////////////////////////////



		int threshold = 15;
	 	if(abs(vexRT[Ch2]) > threshold)
			{
				motor[backRight] = vexRT[Ch2];
				motor[frontRight] = vexRT[Ch2];
			}
		else if(abs(vexRT[Ch2]) < threshold)
		{
			motor[backRight] = 0;
			motor[frontRight] = 0;
		}
		if(abs(vexRT[Ch3]) > threshold)
			{
				motor[backLeft] = vexRT[Ch3];
				motor[frontLeft] = vexRT[Ch3];
			}
		else if(abs(vexRT[Ch3]) < threshold)
		{
			motor[backLeft] = 0;
			motor[frontLeft] = 0;
		}


//////////////////////////////////////////////////////
//
//
//                     claw
//
//
//////////////////////////////////////////////////////





		if(vexRT[Btn6U] == 1)
		{
			clawClose(55);
		}
		else if(vexRT[Btn6D] == 1)
		{
			clawOpen(127);
		}
		else
		{
			clawStop();
		}


//////////////////////////////////////////////////////
//
//
//                six-bar / pivit
//
//
//////////////////////////////////////////////////////


			if(SensorValue[armSensor] < 2200 && SensorValue[armSensor] > 460)
		{
			if(vexRT[Btn5U] == 1 && vexRT[Btn7U] != 1 && vexRT[Btn8U] != 1)
				up();
			else if(vexRT[Btn5D] == 1 && vexRT[Btn7D] != 1 && vexRT[Btn8D] != 1)
				down();
			else if(vexRT[Btn7U] == 1 || vexRT[Btn8U] == 1 && vexRT[Btn5U] != 1)
			{
				upSlowly();
			}
			else if(vexRT[Btn7D] == 1 || vexRT[Btn8D] == 1 && vexRT[Btn5D] != 1)
			{
				downSlowly();
			}
			else
				holdArm();
		}
		else if(SensorValue[armSensor] > 2200)
		{
			if(vexRT[Btn5D] == 1 && vexRT[Btn7D] != 1 && vexRT[Btn8D] != 1)
				down();
			else if(vexRT[Btn7U] == 1 || vexRT[Btn8U] == 1 && vexRT[Btn5U] != 1)
			{
				upSlowly();
			}
			else if(vexRT[Btn7D] == 1 || vexRT[Btn8D] == 1 && vexRT[Btn5D] != 1)
			{
				downSlowly();
			}
			else
				holdArm();
		}
		else if(SensorValue[armSensor] < 460)
		{
			if(vexRT[Btn5U] == 1 && vexRT[Btn7U] != 1 && vexRT[Btn8U] != 1)
				up();
			else if(vexRT[Btn7U] == 1 || vexRT[Btn8U] == 1 && vexRT[Btn5U] != 1)
			{
				upSlowly();
			}
			else if(vexRT[Btn7D] == 1 || vexRT[Btn8D] == 1 && vexRT[Btn5D] != 1)
			{
				downSlowly();
			}
			else
				holdArm();
		}




//////////////////////////////////////////////////////
//
//
//                     lock
//
//
//////////////////////////////////////////////////////



		if(vexRT[Btn7L] == 1 || vexRT[Btn8R] == 1)
		{
			motor[lock] = -111;
		}
		else if(vexRT[Btn7R] == 1 && vexRT[Btn8L] == 1)
		{
			motor[lock] = -30;
		}
	}
}
