#pragma config(Sensor, in1,    armSensor,      sensorPotentiometer)
#pragma config(Sensor, in2,    clawSensor,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftWheels,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightWheels,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor1,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           leftMotor3,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           rightMotor4,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           rightMotor5,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           rightMotor6,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           claw,          tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftTower,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           rightTower,    tmotorVex393, openLoop)
#pragma config(Motor,  port9,           lock,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          leftMotor2,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
changelog: V3.2: autonomous trial1.
*/
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)


void forwardAuto(int distance, int speed)//distance in positive, remember to set sensor value to zero if needed; speed in positive
{
	while(SensorValue[leftWheels] < distance || SensorValue[rightWheels] < distance)
	{
		if(SensorValue[leftWheels] > SensorValue[rightWheels])
		{
			motor[leftMotor1] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[leftMotor2] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[leftMotor3] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor4] = speed;
			motor[rightMotor5] = speed;
			motor[rightMotor6] = speed;
		}
		else if(SensorValue[leftWheels] < SensorValue[rightWheels])
		{
			motor[leftMotor1] = speed;
			motor[leftMotor2] = speed;
			motor[leftMotor3] = speed;
			motor[rightMotor4] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor5] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor6] = speed - (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
		}
		else if(SensorValue[leftWheels] == SensorValue[rightWheels])
		{
			motor[leftMotor1] = speed;
			motor[leftMotor2] = speed;
			motor[leftMotor3] = speed;
			motor[rightMotor4] = speed;
			motor[rightMotor5] = speed;
			motor[rightMotor6] = speed;
		}
	}
}

void backwardAuto(int distance, int speed)//distance in negative, remember to set sensor value to zero if needed; speed in positive
{
	while(SensorValue[leftWheels] > distance || SensorValue[rightWheels] > distance)
	{
		if(SensorValue[leftWheels] > SensorValue[rightWheels])
		{
			motor[leftMotor1] = -speed;
			motor[leftMotor2] = -speed;
			motor[leftMotor3] = -speed;
			motor[rightMotor4] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor5] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor6] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
		}
		else if(SensorValue[leftWheels] < SensorValue[rightWheels])
		{
			motor[leftMotor1] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[leftMotor2] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[leftMotor3] = -speed + (abs((SensorValue[leftWheels]) - (SensorValue[rightWheels])));
			motor[rightMotor4] = -speed;
			motor[rightMotor5] = -speed;
			motor[rightMotor6] = -speed;
		}
		else if(SensorValue[leftWheels] == SensorValue[rightWheels])
		{
			motor[leftMotor1] = -speed;
			motor[leftMotor2] = -speed;
			motor[leftMotor3] = -speed;
			motor[rightMotor4] = -speed;
			motor[rightMotor5] = -speed;
			motor[rightMotor6] = -speed;
		}
	}
}

void ccwRotationBothSide(int degree, int speed)//degree in positive, and speed in positive for both side, program will set them to negative
{
	int distance = (11*PI*degree)/(4*PI);
	while(SensorValue[leftWheels] > -distance || SensorValue[rightWheels] < distance)
	{
		motor[leftMotor1] = -speed;
		motor[leftMotor2] = -speed;
		motor[leftMotor3] = -speed;
		motor[rightMotor4] = speed;
		motor[rightMotor5] = speed;
		motor[rightMotor6] = speed;
	}
}

void cwRotationBothSide(int degree, int speed)//degree in positive, and speed in positive for both side, program will set them to negative
{
	int distance = (11*PI*degree)/(4*PI);
	while(SensorValue[leftWheels] < distance || SensorValue[rightWheels] > -distance)
	{
		motor[leftMotor1] = speed;
		motor[leftMotor2] = speed;
		motor[leftMotor3] = speed;
		motor[rightMotor4] = -speed;
		motor[rightMotor5] = -speed;
		motor[rightMotor6] = -speed;
	}
}

void stopMoving()
{
	motor[leftMotor1] = 0;
	motor[leftMotor2] = 0;
	motor[leftMotor3] = 0;
	motor[rightMotor4] = 0;
	motor[rightMotor5] = 0;
	motor[rightMotor6] = 0;
}

void armUp()
{
	motor[leftTower] = 127;
	motor[rightTower] = 127;
}

void armDown()
{
	motor[leftTower] = -63;
	motor[rightTower] = -63;
}

void armStop()
{
	if(SensorValue[armSensor] < 1790 && SensorValue[armSensor] > 289)
	{
		motor[leftTower] = 8;
		motor[rightTower] = 8;
	}
	else
	{
		motor[leftTower] = 0;
		motor[rightTower] = 0;
	}
}

void armStopAuto()
{
	int towerBalanceAuto = 0;
	if(SensorValue[armSensor] < 1790 && SensorValue[armSensor] > 289)
		towerBalanceAuto = 1;
	else
		towerBalanceAuto = 0;
	while(towerBalanceAuto == 1)
	{
		 motor[leftTower] = 10;
		 motor[rightTower] = 10;
		 wait1Msec(1);
		 motor[leftTower] = 0;
		 motor[rightTower] = 0;
		 wait1Msec(1);
		 if(SensorValue[armSensor] < 1790)
			towerBalanceAuto = 1;
     else
			towerBalanceAuto = 0;
	}
	while(towerBalanceAuto == 0)
	{
		motor[leftTower] = 0;
		 motor[rightTower] = 0;
		 if(SensorValue[armSensor] < 1790)
			towerBalanceAuto = 1;
     else
			towerBalanceAuto = 0;
	}
}

void defenseAuto()
{
	int clawAuto = 0;
	if(SensorValue[clawSensor] > 1650)
		clawAuto = 1;
	else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
		clawAuto = 2;
	else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
		clawAuto = 0;
	else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
		clawAuto = 3;
	else if(SensorValue[clawSensor] <865)
		clawAuto = 4;
	while(clawAuto == 1)
	{
		motor[claw] = 63;
		motor[leftMotor1] = 0 - SensorValue[leftWheels];
		motor[leftMotor2] = 0 - SensorValue[leftWheels];
		motor[leftMotor3] = 0 - SensorValue[leftWheels];
		motor[rightMotor4] = 0 - SensorValue[rightWheels];
		motor[rightMotor5] = 0 - SensorValue[rightWheels];
		motor[rightMotor6] = 0 - SensorValue[rightWheels];
		if(SensorValue[clawSensor] > 1650)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
			clawAuto = 3;
		else if(SensorValue[clawSensor] <865)
			clawAuto = 4;
	}
	while(clawAuto == 2)
	{
		motor[claw] = 40;
		motor[leftMotor1] = 0 - SensorValue[leftWheels];
		motor[leftMotor2] = 0 - SensorValue[leftWheels];
		motor[leftMotor3] = 0 - SensorValue[leftWheels];
		motor[rightMotor4] = 0 - SensorValue[rightWheels];
		motor[rightMotor5] = 0 - SensorValue[rightWheels];
		motor[rightMotor6] = 0 - SensorValue[rightWheels];
		if(SensorValue[clawSensor] > 1650)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
			clawAuto = 3;
		else if(SensorValue[clawSensor] <865)
			clawAuto = 4;
	}
	while(clawAuto == 3)
	{
		motor[claw] = -20;
		motor[leftMotor1] = 0 - SensorValue[leftWheels];
		motor[leftMotor2] = 0 - SensorValue[leftWheels];
		motor[leftMotor3] = 0 - SensorValue[leftWheels];
		motor[rightMotor4] = 0 - SensorValue[rightWheels];
		motor[rightMotor5] = 0 - SensorValue[rightWheels];
		motor[rightMotor6] = 0 - SensorValue[rightWheels];
		if(SensorValue[clawSensor] > 1650)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
			clawAuto = 3;
		else if(SensorValue[clawSensor] <865)
			clawAuto = 4;
	}
	while(clawAuto == 4)
	{
		motor[claw] = -63;
		motor[leftMotor1] = 0 - SensorValue[leftWheels];
		motor[leftMotor2] = 0 - SensorValue[leftWheels];
		motor[leftMotor3] = 0 - SensorValue[leftWheels];
		motor[rightMotor4] = 0 - SensorValue[rightWheels];
		motor[rightMotor5] = 0 - SensorValue[rightWheels];
		motor[rightMotor6] = 0 - SensorValue[rightWheels];
		if(SensorValue[clawSensor] > 1650)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
			clawAuto = 3;
		else if(SensorValue[clawSensor] <865)
			clawAuto = 4;
	}
	while(clawAuto == 0)
	{
		motor[claw] = 0;
		motor[leftMotor1] = 0 - SensorValue[leftWheels];
		motor[leftMotor2] = 0 - SensorValue[leftWheels];
		motor[leftMotor3] = 0 - SensorValue[leftWheels];
		motor[rightMotor4] = 0 - SensorValue[rightWheels];
		motor[rightMotor5] = 0 - SensorValue[rightWheels];
		motor[rightMotor6] = 0 - SensorValue[rightWheels];
		if(SensorValue[clawSensor] > 1650)
			clawAuto = 1;
		else if(SensorValue[clawSensor] >1150 && SensorValue[clawSensor] < 1650)
			clawAuto = 2;
		else if(SensorValue[clawSensor] >1100 && SensorValue[clawSensor] < 1150)
			clawAuto = 0;
		else if(SensorValue[clawSensor] >865 && SensorValue[clawSensor] < 1100)
			clawAuto = 3;
		else if(SensorValue[clawSensor] <865)
			clawAuto = 4;
	}
}

void openClaw()
{
	motor[claw] = 75;
}

void closeClaw()
{
	motor[claw] = -75;
}

void holdClaw()
{
	motor[claw] = -40;
}

void clearEncoders()
{
	SensorValue[leftWheels] = 0;
	SensorValue[rightWheels] = 0;
}

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
void pre_auton()
{
	motor[lock] = 127;
	clearEncoders();
}
task autonomous()
{
	int defence = 0;
	pre_auton();
	clearEncoders();
	forwardAuto(1576,40);
	backwardAuto(85, 40);
	forwardAuto(85,40);
	backwardAuto(85,40);
	cwRotationBothSide(90,40);
	forwardAuto(1031,40);
	ccwRotationBothSide(90,40);
	forwardAuto(85,40);
	defence = 1;
	while(defence == 1)
	{
		defenseAuto();
	}
	/*clearEncoders();
	//go right for 12"
	forwardAuto(344,40);
	stopMoving();
	wait1Msec(100);
	clearEncoders();
	//CCW rotation 180 degree
	ccwRotationBothSide(180,40);
	stopMoving();
	wait1Msec(100);
	clearEncoders();
	//CW rotation 180 degree
	cwRotationBothSide(180,40);
	stopMoving();
	clearEncoders();
	//forward 48"
	forwardAuto(1375,40);
	stopMoving();
	wait1Msec(100);
	clearEncoders();
	//defense
	//defenseAuto();
	*/
}
task usercontrol()
{
	while (true)
	{
			//driving system
		int threshold1 = 0;
		int threshold2 = 0;
		if(abs(vexRT[Ch3]) > 50)
			threshold1 = vexRT[Ch3];
		else
			threshold1 = 0;
		if (abs(vexRT[Ch4]) > 63)
			threshold2 = vexRT[Ch4];
		else
			threshold2 = 0;
		if(vexRT[Btn8D] == 1)//precise control
		{
			if(abs(vexRT[Ch4]) <= 63)
			{
				motor[leftMotor1] = threshold1/2.5;
				motor[leftMotor2] = threshold1/2.5;
				motor[leftMotor3] = threshold1/2.5;
				motor[rightMotor4] = threshold1/2.5;
				motor[rightMotor5] = threshold1/2.5;
				motor[rightMotor6] = threshold1/2.5;
			}
			else if (abs(vexRT[Ch4]) > 63)
			{
				motor[leftMotor1] = (threshold1/2.5 + threshold2/4);
				motor[leftMotor2] = (threshold1/2.5 + threshold2/4);
				motor[leftMotor3] = (threshold1/2.5 + threshold2/4);
				motor[rightMotor4] = (threshold1/2.5 - threshold2/4);
				motor[rightMotor5] = (threshold1/2.5 - threshold2/4);
				motor[rightMotor6] = (threshold1/2.5 - threshold2/4);
			}
		}
		else//fast moving control
		{
			motor[leftMotor1] = (threshold1 + threshold2/2.5);
			motor[leftMotor2] = (threshold1 + threshold2/2.5);
			motor[leftMotor3] = (threshold1 + threshold2/2.5);
			motor[rightMotor4] = (threshold1 - threshold2/2.5);
			motor[rightMotor5] = (threshold1 - threshold2/2.5);
			motor[rightMotor6] = (threshold1 - threshold2/2.5);
		}


		//six bar control.
		if(SensorValue[armSensor] > 289  && SensorValue[armSensor] < 2064 )
		{
			if(vexRT[Btn5U] == 1)
			{
				armUp();
			}
			else	if(vexRT[Btn5D] == 1)
			{
				armDown();
			}
			else
			{
				armStop();
			}
		}
		//goes up from the lowest position.
		else if(SensorValue[armSensor] > 2064)
   	{
   		if(vexRT[Btn5U] == 1)
   		{
   			armUp();
   		}
   		else
 			{
 				armStop();
   		}
   	}
    //goes down from the highest position
    else if(SensorValue[armSensor]< 289)
    {
 			if(vexRT[Btn5D] == 1)
 			{
 				motor[rightTower] = -127;
   			motor[leftTower] = -127;
   		}
   		else
   			{
   				armStop();
   			}
   		}
  	//lock

		//claw
    if(vexRT[Btn6U] == 1)
   		openClaw();
   	else if(vexRT[Btn6D] == 1)
   		closeClaw();
   	else if(vexRT[Btn8R] == 1)
   		holdClaw();
   	else
   		motor[claw] = 0;
	}
}
