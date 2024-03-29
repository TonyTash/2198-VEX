#pragma config(Motor,  port1,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

TPCJoystick joystick;

void motorControlProportional()
{
  int nMotorPower;
  int nDirection;

  nMotorPower = joystick.joy_y1;
  nDirection  = joystick.joy_x1;
  if (nDirection < 0)
  {
    // Turn left

    motor[rightMotor] = nMotorPower; // use power settings from Y-axis
    motor[leftMotor]  = nMotorPower * (64 + nDirection) / 64;
  }
  else
  {
    // Turn right

    motor[leftMotor]  = nMotorPower; // use power settings from Y-axis
    motor[rightMotor] = nMotorPower * (64 - nDirection) / 64;
  }
}

void buttonControl()
{
  return;
}

task main()
{
  while (true)
  {
    getPCJoystickSettings(joystick);
    motorControlProportional();
    buttonControl();
  }
}
