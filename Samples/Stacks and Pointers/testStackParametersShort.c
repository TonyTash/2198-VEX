
static int  gParm1;
static byte gParm2;
static short gParm3;
static byte gParm4;
static int  gParm5;

static int  gNestedParm1;
static byte gNestedParm2;
static short gNestedParm3;
static byte gNestedParm4;
static int  gNestedParm5;

static int  gNestedNestedParm1;
static byte gNestedNestedParm2;
static short gNestedNestedParm3;
static byte gNestedNestedParm4;
static int  gNestedNestedParm5;


void testParametersViaStack(int xParm1, byte xParm2, short xParm3, int &xParm4, int &xParm5)
{
  gParm1  = xParm1;
  gParm2  = xParm2;
  gParm3  = xParm3;
  gParm4  = xParm4;
  gParm5  = xParm5;
  xParm5   = xParm4;
}

void nestedCall(int parm1, byte parm2, short parm3, int &parm4, int &parm5)
{
  int local1 = 1;
  byte local2 = 2;

  gNestedParm1  = parm1;
  {
    int local3 = 3;
    short local4 = rand();
	  gNestedParm2  = parm2 + local4;
	  local3 = local4;
	}
  gNestedParm3  = parm3;
  {
    int local5 = 5;
    short local6 = 6;
    gNestedParm4  = parm4;
  }
  gNestedParm5  = parm5;
  testParametersViaStack(parm1, parm2, parm3, parm4, parm5);
}


void nestedNestedCall(int parm1, byte parm2, short parm3, int &parm4, int &parm5)
{
  byte local3;

  gNestedNestedParm1  = parm1;
  gNestedNestedParm2  = parm2;
  gNestedNestedParm3  = parm3;
  gNestedNestedParm4  = parm4;
  gNestedNestedParm5  = parm5;
  nestedCall(parm1, parm2, parm3, parm4, parm5);
}


void nestedNestedCallXX(int parm1, byte parm2, short parm3, int &parm4, int &parm5)
{
  byte local3;

  gNestedNestedParm1  = parm1;
  gNestedNestedParm2  = parm2;
  gNestedNestedParm3  = parm3;
  gNestedNestedParm4  = parm4;
  gNestedNestedParm5  = parm5;
  nestedCall(parm1, parm2, parm4, parm4, parm5);
}

int nReferenceParmValue;

task two()
{
  while (true)
    wait1Msec(100);
}

task main()
{
  StartTask(two);
  while (true)
  {
    for (int nLoops = 0; nLoops < 10000; ++nLoops)
	  {
	    testParametersViaStack(1, 2, 3, nLoops, nReferenceParmValue);
		  ++nLoops;
		  nestedCall(6, 7, 8, nLoops, nReferenceParmValue);
		  ++nLoops;
		  nestedNestedCall(11, 12, 13, nLoops, nReferenceParmValue);
		  ++nLoops;
		  nestedNestedCallXX(21, 22, 23, nLoops, nReferenceParmValue);
		}
	}
}
