typedef int TTT[10];

TTT nCopy1;
TTT nCopy2;


task main()
{
	while (true)
	{
		memcpy(&nCopy2, &nCopy1, sizeof(TTT));
		memcpy(nCopy2,  nCopy1,  sizeof(TTT));
		nxtDisplayString(1, "Test it");
		nxtDisplayString(2, "Format %d", 999);

		nCopy1[0]=0x0102;
		nCopy1[1]=0x0304;
		nCopy1[2]=0x0506;
		nCopy1[3]=0x0708;
		nCopy1[4]=0x090A;
		nxtDisplayString(3, ":%014X", nCopy1);
		nxtDisplayString(4, ":%014X", &nCopy1[2]);
	}
}
