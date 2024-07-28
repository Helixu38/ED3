#include <Arduino.h>
#include "MyMotor.h"
#include "MySerial.h"

void setup()
{
  Init_Motor();
  Init_Serial();
}

void loop()
{
  Run_Motor();
  // SerialDataPrint();
  SerialDataWrite();
}
