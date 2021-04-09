#include "I2C_AXP192.h"

I2C_AXP192 axp192(I2C_AXP192_DEFAULT_ADDRESS, Wire);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(21, 22);

  I2C_AXP192_InitDef initDef = {
    .EXTEN  = true,
    .BACKUP = true,
    .DCDC1  = 3300,
    .DCDC2  = 0,
    .DCDC3  = 0,
    .LDO2   = 3000,
    .LDO3   = 3000,
    .GPIO0  = 2800,
    .GPIO1  = -1,
    .GPIO2  = -1,
    .GPIO3  = -1,
    .GPIO4  = -1,
  };
  axp192.begin(initDef);
}

void loop() {
  Serial.printf("getBatteryVoltage()          : %7.2f\n", axp192.getBatteryVoltage());
  Serial.printf("getBatteryDischargeCurrent() : %7.2f\n", axp192.getBatteryDischargeCurrent());
  Serial.printf("getBatteryChargeCurrent()    : %7.2f\n", axp192.getBatteryChargeCurrent());
  Serial.printf("getInternalTemperature()     : %7.2f\n", axp192.getInternalTemperature());

  Serial.println();

  delay(1000);
}
