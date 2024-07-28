#include <Arduino.h>

unsigned long Serial_time = 0; // time in us
// ====================================================================================
void Init_Serial()
{
  Serial.begin(115200);
  while (!Serial)
    ;
}
// ====================================================================================
void SerialDataPrint()
{
  if (micros() - Serial_time >= 10000)
  {
    Serial_time = micros();
    Serial.println(Serial_time / 10000);
    Serial.print(">MOT1_cmd:");
    Serial.println(MOT1_cmd);
  }
}
// ====================================================================================
void SerialDataWrite()
{
  static String received_chars;
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    received_chars += inChar;
    if (inChar == '\n')
    {
      Serial.print("Test1");
      switch (received_chars[0])
      {
      case '1':
        Serial.print("Hello");
        received_chars.remove(0, 1);
        MOT1_cmd += 50;
        if((MOT1_cmd> 255)){
          MOT1_cmd = 50;
        }
        break;
      default:
        Serial.print("Test");
        break;
      }
      received_chars = "";
    }
  }
}