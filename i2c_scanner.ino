#include <Wire.h>

#define MAX_I2C_ADDRESS 0x7F

enum ET_ERROR_CODES
{
  SUCCESS,
  TOO_LONG,
  NACK_ADDRESS,
  NACK_DATA,
  OTHER
};

void setup() 
{
   Wire.begin();
   Serial.begin(115200);
   while(!Serial){}
   Serial.println("Starting I2C scan...");
}

void loop() 
{
  for (uint8_t address = 1; address <= MAX_I2C_ADDRESS; ++address) 
  {
    Wire.beginTransmission(address);
    byte ret = Wire.endTransmission();
    if (ret == SUCCESS)
    {
      Serial.print("Found I2C device at: ");
      Serial.print(address, HEX);
      Serial.println();
    }
  }

  Serial.println("End of I2C Scanning.");
  while(1){}
}
