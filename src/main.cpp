#include <Arduino.h>
#include <SPI.h>
#include "EM4325.h"

//#define SS (9)
#define SS (2)
SPISettings settingsA(4000000, MSBFIRST, SPI_MODE0); 

void setup() {
  Serial.begin(115200);
  Serial.println("BEGIN.");
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
  SPI.begin();

  uint8_t status;
  SPI.beginTransaction(settingsA);
  digitalWrite(SS, LOW);
  SPI.transfer(EM4325_SPI_CMD_REQUESTSTATUS);
  status = SPI.transfer(0x00);
  digitalWrite(SS, HIGH);
  SPI.endTransaction();
  Serial.println(status, BIN);
}

void readSensorData() {
  uint16_t data[9];
  SPI.beginTransaction(settingsA);
  digitalWrite(SS, LOW);
  // SPI.transfer(0xE4);  // Get sensor data
  SPI.transfer(EM4325_SPI_CMD_GETNEWSENSORDATA);  // Get sensor data after new sample
  // Wait for the status code which must have the MSB set to 1.
  do {
    data[0] = SPI.transfer(0x00); // Reply status
  }
  while (!(data[0] & 0x80));

  // See the "System Memory - Sensor Data" section (pg. 33)
  // for details on the format of this data. In short, the
  // 9 LSBs of the MSW of the sensor data is 2'c complement
  // with 2 fraction bits.
  data[1] = SPI.transfer(0x00); // Sensor data (MSW)
  data[2] = SPI.transfer(0x00);
  data[3] = SPI.transfer(0x00); // Sensor data (LSW)
  data[4] = SPI.transfer(0x00);
  data[5] = SPI.transfer(0x00); // UTC (MSW)
  data[6] = SPI.transfer(0x00);
  data[7] = SPI.transfer(0x00); // UTC (LSW)
  data[8] = SPI.transfer(0x00);

  Serial.print(data[1], BIN);
  Serial.print(" ");
  Serial.print(data[2], BIN);
  Serial.print(" ");
  Serial.print(data[3], BIN);
  Serial.print(" ");
  Serial.print(data[4], BIN);
  Serial.print(" ");
  Serial.print(data[5], BIN);
  Serial.print(" ");
  Serial.print(data[6], BIN);
  Serial.print(" ");
  Serial.print(data[7], BIN);
  Serial.print(" ");
  Serial.print(data[8], BIN);
  Serial.println();
  
  digitalWrite(SS, HIGH);
  SPI.endTransaction();
  Serial.print(((uint16_t)(data[1]) << 8) | data[2], BIN);
  Serial.print(",");
  Serial.print(((uint16_t)(data[3]) << 8) | data[4], BIN);
  Serial.print(",");
  Serial.print(((uint16_t)(data[5]) << 8) | data[6], BIN);
  Serial.print(",");
  Serial.print(((uint16_t)(data[7]) << 8) | data[8], BIN);

  uint16_t readSensorDataMSW = ((uint16_t)(data[1]) << 8) | data[2];
  float pi16Temperature;

  if ( EM4325_TEMERATURE_INVALID == (readSensorDataMSW & EM4325_MASK_TEMERATURE) ) {
    pi16Temperature = EM4325_TEMERATURE_0_KELVIN;
  } else {
    /* Tests the sign of the temperature */
    if(1 == ((readSensorDataMSW & EM4325_MASK_NEG_TEMERATURE) >> EM4325_SHIFT_NEG_TEMERATURE)) {
      /* the format of the temperature is (2's complement MSB  = 4C / 1 LSB = 0.25C) */
      pi16Temperature =  (float)(((~readSensorDataMSW) & 0x00FF) >> 2);
      pi16Temperature *=  EM4325_COEF_NEG_TEMERATURE;
    } else {
      /* the format of the temperature is (1 MSB  = 4C / 1 LSB = 0.25C) */
      pi16Temperature =  (float)(((readSensorDataMSW & EM4325_MASK_MSB_TEMERATURE) >> EM4325_SHIFT_MSB_TEMERATURE)
                  * EM4325_COEF_MSB_TEMERATURE);
      pi16Temperature += (float)(((readSensorDataMSW & EM4325_MASK_LSB_TEMERATURE) >> EM4325_SHIFT_LSB_TEMERATURE)
                  * EM4325_COEF_LSB_TEMERATURE);
    }
  }

  Serial.print("   ,");
  Serial.print(pi16Temperature);
  Serial.println();
}

void loop() {

  readSensorData();
  delay(1000);
}