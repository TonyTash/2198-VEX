 #pragma config(Motor,  port1,           frontRight,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontTshoot,   tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port3,           backTshoot,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           Intakes,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           conveyor,      tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port8,           frontBshoot,   tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port9,           backBshoot,    tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port10,          backRight,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone
int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;
int speed = 108;
bool pressed = true;
//Loop Forever
	while(1 == 1)
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
		else if (vexRT[Btn8R]==1)
		{

				motor[frontTshoot]=speed-3;
				motor[backTshoot]=speed-3;
	    	motor[frontBshoot]=speed-3;
	   		motor[backBshoot]=speed-3;

	  }
	  else if (vexRT[Btn5D]==1)
	  {
	  		motor[frontTshoot]=speed-3;
				motor[backTshoot]=speed-23;
	    	motor[frontBshoot]=speed-3;
	   		motor[backBshoot]=speed-23;
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
