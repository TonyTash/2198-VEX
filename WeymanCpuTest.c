
task main()
{

while (true)
{

for (int i = -127; i < 128; i++)
{

motor[port1] = i;
motor[port2] = i;
motor[port3] = i;
motor[port4] = i;
motor[port5] = i;
motor[port6] = i;
motor[port7] = i;
motor[port8] = i;
motor[port9] = i;
motor[port10] = i;
wait1Msec(10);

}

for (int i = 127; i < -128; i--)
{

motor[port1] = i;
motor[port2] = i;
motor[port3] = i;
motor[port4] = i;
motor[port5] = i;
motor[port6] = i;
motor[port7] = i;
motor[port8] = i;
motor[port9] = i;
motor[port10] = i;
wait1Msec(10);

}

for (int i = 127; i < -128; i--)
{

motor[port1] = i;
motor[port2] = i;
motor[port3] = i;
motor[port4] = i;
motor[port5] = i;
motor[port6] = i;
motor[port7] = i;
motor[port8] = i;
motor[port9] = i;
motor[port10] = i;
wait1Msec(10);

}

}

}
