#pragma config(Sensor, in7,    leftArmSensor,  sensorPotentiometer)
#pragma config(Sensor, in8,    rightArmSensor, sensorPotentiometer)
#pragma config(Motor,  port1,           backLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port3,           frontRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           backRightMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           leftCollector, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           rightCollector, tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftArmMotor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           rightArmMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           convey,        tmotorVex393, openLoop)
#pragma config(Motor,  port10,          sidewaysMotor, tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
V2.4 update: change the formula for the six bar level control, so six bar can now move up and down at the same rate without suddenly switch direction
set seperated six bar control buttom to 8U and 8D
*/
task main()
{
while(1 == 1) // Loop following indefinetly
  {
int side = 0;
int forbackward = 0;
int threshold1 = 40;
int threshold2 = 30;
int lArm = SensorValue[leftArmSensor] - 571;
int rArm = (-SensorValue[rightArmSensor] + 1759);
int speed = abs(lArm - rArm);


  	if(abs(vexRT[Ch4]) > threshold1)
  	{
  		if(vexRT[Ch4] > 0)
  		{
  			side = 127;
  		}
  		else
  		{
  			side = -127;
  		}
  	}
  	else
  	{
  		side = 0;
  	}
  	if (abs(vexRT[Ch3]) > threshold2)
  	{
  		forbackward = vexRT[Ch3];
  	}
  	else
  	{
  		forbackward = 0;
  	}

 		//Right side of the robot is controlled by the left joystick, Y-axis, minus the rotation from the x axis
    motor[frontRightMotor] = (forbackward - vexRT[Ch1]/2);
    motor[backRightMotor]  = (forbackward - vexRT[Ch1]/2);
    //Left side of the robot is controlled by the left joystick, Y-axis, plus the rotation from the x axis
    motor[frontLeftMotor] = (forbackward + vexRT[Ch1]/2);
    motor[backLeftMotor]  = (forbackward + vexRT[Ch1]/2);

    motor[sidewaysMotor] = side; // Allows the robot to move sideways, based on the


    //six bar control.
    //if(SensorValue[leftArmSensor] > 567) || SensorValue[rightArmSensor] < 1718 )
    if(vexRT[Btn8U] == 1 && vexRT[Btn8D] == 1)
    {
    	if(vexRT[Btn5U] == 1)
    		motor[leftArmMotor] = 127;
    	else if(vexRT[Btn5D] == 1)
    		motor[leftArmMotor] = -127;
    	else
    		motor[leftArmMotor] = 0;
    	if(vexRT[Btn6U] == 1)
    		motor[rightArmMotor] = 127;
    	else if(vexRT[Btn6D] == 1)
    		motor[rightArmMotor] = -127;
    	else
    		motor[rightArmMotor] = 0;
  	}
    else if(lArm == rArm)
    {
   		if(vexRT[Btn6U] == 1)
   		{
   			motor[rightArmMotor] = 127;
   			motor[leftArmMotor] = 127;
   		}
   		else	if(vexRT[Btn6D] == 1)
   		{
   			motor[rightArmMotor] = -127;
   			motor[leftArmMotor] = -127;
   		}
   		else
   		{
   			motor[rightArmMotor] = 0;
   			motor[leftArmMotor] = 0;
   		}
   	}
   	else if(lArm > rArm)
   	{
   		if(vexRT[Btn6U] == 1)
   		{
   			motor[rightArmMotor] = 127;
   			motor[leftArmMotor] = 127-speed;
   		}
   		else if(vexRT[Btn6D] == 1)
   		{
   			motor[rightArmMotor] = -127+speed;
   			motor[leftArmMotor] = -127;
   		}
   		else
   		{
   			motor[rightArmMotor] = 0;
   			motor[leftArmMotor] = 0;
   	  }
    }
    else if(lArm < rArm)
    {
    	if(vexRT[Btn6U] == 1)
   		{
   			motor[rightArmMotor] = 127-speed;
   			motor[leftArmMotor] = 127;
   		}
   		else if(vexRT[Btn6D] == 1)
   		{
   			motor[rightArmMotor] = -127;
   			motor[leftArmMotor] = -127+speed;
   		}
   		else
   		{
   			motor[rightArmMotor] = 0;
   			motor[leftArmMotor] = 0;
   	  }
    }

    //convey and collector
    if(vexRT[Btn8L] == 1)
    {
    	motor[leftCollector] = 127;
    	motor[rightCollector] = 127;
    	motor[convey] = 127;
    }
    else if(vexRT[Btn8R] == 1)
    {
    	motor[leftCollector] = -127;
    	motor[rightCollector] = -127;
    	motor[convey] = -127;
    }
    else
    {
    	motor[leftCollector] = 0;
    	motor[rightCollector] = 0;
    	motor[convey] = 0;
    }

//changelog: add seperated control of six bars.(by pressing 7U button)

	}

}
