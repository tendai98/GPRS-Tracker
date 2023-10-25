#include "sim80x.h"

#define BOOT_DELAY 10000
#define LOOP_DELAY 1000

void setup(){
  Serial.begin(9600);
  initSIM80XDevice();
  delay(BOOT_DELAY);
}

void loop(){
  GPRS_CTL();
  getGPSData();
  SEND_GPS_DATA();
  delay(LOOP_DELAY);
}
