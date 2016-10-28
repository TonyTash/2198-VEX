#pragma config(ProgramType, StandaloneWiFi)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

  while(vexRT[Btn7D] == 0)
  {
  }

  ClearTimer(T1);
  while(time1[T1] < 90000)
  {
    motor[leftMotor] = vexRT[Ch3] / 2;
    motor[rightMotor] = vexRT[Ch2] / 2;

    if(vexRT[Btn6U] == 1)
    {
      motor[armMotor] = 40;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[armMotor] = -40;
    }
    else
    {
      motor[armMotor] = 0;
    }
  }

  motor[leftMotor] = 0;
  motor[rightMotor] = 0;

}
