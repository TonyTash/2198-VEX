task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................
		motor[armMotor1] = 127;
		motor[armMotor2] = 127;

		wait1Msec(1000);

		motor[armMotor1] = 0;
		motor[armMotor2] = 0;

		motor[frontRightMotor] = 127;
    motor[backRightMotor]  = 127;
    motor[frontLeftMotor] = 127;
    motor[backLeftMotor]  = 127;

    //SensorValue[??];
		wait1Msec(2000);

		motor[frontRightMotor] = 0;
    motor[backRightMotor]  = 0;
    motor[frontLeftMotor] = 0;
    motor[backLeftMotor]  = 0;

		motor[armMotor1] = -127;
		motor[armMotor2] = -127;

		wait1Msec(1000);

		motor[armMotor1] = 0;
		motor[armMotor2] = 0;

		motor[frontRightMotor] = 127;
    motor[backRightMotor]  = 127;
    motor[frontLeftMotor] = -127;
    motor[backLeftMotor]  = -127;

    wait1Msec(500);

    motor[frontRightMotor] = 127;
    motor[backRightMotor]  = 127;
    motor[frontLeftMotor] = 127;
    motor[backLeftMotor]  = 127;

    wait1Msec(2000);

    motor[frontRightMotor] = -10;
    motor[backRightMotor]  = -10;
    motor[frontLeftMotor] = -10;
    motor[backLeftMotor]  = -10;

    motor[frontRightMotor] = 0;
    motor[backRightMotor]  = 0;
    motor[frontLeftMotor] = 0;
    motor[backLeftMotor]  = 0;

}
