#define HTPIR_I2CADDRESS 		0x02
#define HTPIR_REG_DATA 			0x42
#define HTPIR_REG_DEADBAND 	0x41
#define HTPIR_SENSORTYPE 		sensorI2CCustom

#define MAX_ARR_SIZE 17
typedef ubyte tByteArray[MAX_ARR_SIZE];
struct tI2Cdata
{
  tByteArray rxbuffer;
  tByteArray txbuffer;
  ubyte address;
  tSensors port;
} tI2Cdata;

struct tHTPIRSensor
{
  tI2Cdata I2Cdata;
  ubyte deadband;
  int reading;
  bool init;
  bool configured;
} tHTPIRSensor;

tHTPIRSensor HTPIR;

void clearI2CError(tI2Cdata &data) {
  ubyte error_array[2];
  error_array[0] = 1;           // Message size
  error_array[1] = data.address; // I2C Address

  for (int i = 0; i < 5; i++) {
    sendI2CMsg(data.port, error_array[0], 0);
    wait1Msec(5);
  }
}


/**
 * Wait for the I2C bus to be ready for the next message
 * @param link the port number
 * @return true if no error occured, false if it did
 */
bool waitForI2CBus(tI2Cdata &data)
{
  ubyte error_count = 0;
  while (true && error_count < 10)
  {
    switch (nI2CStatus[data.port])
    {
    case NO_ERR:
      return true;

    case STAT_COMM_PENDING:
      break;

    case ERR_COMM_CHAN_NOT_READY:
      error_count++;
      wait1Msec(5);
      break;

    case ERR_COMM_BUS_ERR:
      return false;
    }
  }
  return true;
}

bool I2Csend(tI2Cdata &data, int replylen) {
  if (!waitForI2CBus(data)) {
    clearI2CError(data);

    // Let's try the bus again, see if the above packets flushed it out
    // clearI2CBus(link);
    if (!waitForI2CBus(data))
      return false;
  }

  sendI2CMsg(data.port, data.txbuffer[0], replylen);

  if (!waitForI2CBus(data)) {
    clearI2CError(data);
    sendI2CMsg(data.port, data.txbuffer[0], replylen);
    if (!waitForI2CBus(data))
      return false;
  }

  if (replylen == 0)
  {
    return true;
  }

  // wait for the bus to be done receiving data
  if (!waitForI2CBus(data))
    return false;

  // ask for the input to put into the data array
  readI2CReply(data.port, data.rxbuffer[0], replylen);

  return true;
}

void init(tHTPIRSensor &sensor, tSensors link)
{
  sensor.I2Cdata.port = link;
  sensor.I2Cdata.address = HTPIR_I2CADDRESS;
  SensorType[link] = HTPIR_SENSORTYPE;
  memset(sensor.I2Cdata.rxbuffer[0], 0, sizeof(tByteArray));
  memset(sensor.I2Cdata.txbuffer[0], 0, sizeof(tByteArray));
  sensor.deadband = 12;
  sensor.init = true;
}

bool configureSensor(tHTPIRSensor &sensor)
{
  if (!sensor.init)
  {
    writeDebugStream("Sensor not initialised!");
    StopAllTasks();
  }

  sensor.I2Cdata.txbuffer[0] = 3;
  sensor.I2Cdata.txbuffer[1] = sensor.I2Cdata.address;
  sensor.I2Cdata.txbuffer[2] = 0x41;
  sensor.I2Cdata.txbuffer[3] = sensor.deadband;
  return I2Csend(sensor.I2Cdata, 0);
}

bool readSensor(tHTPIRSensor &sensor)
{
  if (!sensor.init)
  {
    writeDebugStream("Sensor not initialised!");
    StopAllTasks();
  }

  sensor.I2Cdata.txbuffer[0] = 2;
  sensor.I2Cdata.txbuffer[1] = sensor.I2Cdata.address;
  sensor.I2Cdata.txbuffer[2] = 0x42;
  if (!I2Csend(sensor.I2Cdata, 1))
    return false;
  sensor.reading = sensor.I2Cdata.rxbuffer[0];
  return true;
}


task main ()
{
  init(HTPIR, S1);

  HTPIR.deadband = 20;
  configureSensor(HTPIR);

  writeDebugStreamLine("deadband: %d", HTPIR.deadband);
  writeDebugStreamLine("address: %d", HTPIR.I2Cdata.address);

  while (true)
  {
    readSensor(HTPIR);
    writeDebugStreamLine("reading: %d", HTPIR.reading);
    wait1Msec(100);
  }

  wait1Msec(5000);
}
