//autonumous tryout
void forwardA()
{
	motor[frontLeftMotor] = 63;
  motor[frontRightMotor] = 63;
  motor[backLeftMotor] = 63;
  motor[backRightMotor] = 63;
}
void rest()
{
	motor[frontLeftMotor] = 0;
  motor[frontRightMotor] = 0;
  motor[backLeftMotor] = 0;
  motor[backRightMotor] = 0;
}
task main()
{
ClearTimer(T1);
  while(time1[T1]<2500)
	{
		forwardA();
	}
	rest();
	while


}
