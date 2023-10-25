#include "SoftwareSerial.h"
#include "StringSplitter.h"
#include "at.h"

#define TX_GPIO D3
#define RX_GPIO D2
#define BLINK_DELAY 50
#define BLINK_LED D4
#define BAUDRATE 9600

StringSplitter * parser;
SoftwareSerial sim80xDevice(TX_GPIO, RX_GPIO);
String GLOBAL_GPS_DATA = "";
String GLOBAL_LATITUDE = "";
String GLOBAL_LONGITUDE = "";
char c;

void blinkLED(){
  digitalWrite(BLINK_LED, LOW);
  delay(BLINK_DELAY);
  digitalWrite(BLINK_LED, HIGH);
  delay(BLINK_DELAY);
}

void sendCommand(char * buff){
  sim80xDevice.flush();
  sim80xDevice.println(buff);  
  blinkLED(); 
  while(sim80xDevice.available()){
    Serial.print((char) sim80xDevice.read());
  }
  delay(250);
}

void initSIM80XDevice(){
  pinMode(BLINK_LED, OUTPUT);
  sim80xDevice.begin(BAUDRATE);
}


void getGPSData(){
  sim80xDevice.println(AT_GNSINF);
  delay(100);
  while(sim80xDevice.available()){
    c = (char) sim80xDevice.read();
    GLOBAL_GPS_DATA += String(c);
    if(GLOBAL_GPS_DATA.length() > 20 && c == 10){
      GLOBAL_GPS_DATA.remove(0,10);
      GLOBAL_GPS_DATA.remove(0,17);
      GLOBAL_GPS_DATA.replace(AT_GNSINF,"");
      parser = new StringSplitter(GLOBAL_GPS_DATA, ',', 12);
      GLOBAL_LATITUDE = parser->getItemAtIndex(1);
      GLOBAL_LONGITUDE = parser->getItemAtIndex(2);
      GLOBAL_GPS_DATA = "";
      sim80xDevice.flush();
      
      break;
    }
  }
}

void GPRS_CTL(){
  sendCommand(AT_GNSPWR);
  sendCommand(AT_GNSSEQ);
  sendCommand(AT_GPRS_CONN);
  sendCommand(AT_GPRS_APN);
  sendCommand(AT_GPRS_ON);
  delay(2000);
  sendCommand(AT_GPRS_IP);
}

void SEND_GPS_DATA(){
  sendCommand(AT_HTTP_INIT);
  sendCommand(AT_HTTP_CID);
  sim80xDevice.printf(AT_HTTP_URL, GLOBAL_LONGITUDE, GLOBAL_LATITUDE);
  sendCommand(AT_HTTP_DATA); 
  sendCommand(AT_HTTP_GET);
  Serial.printf("%s - %s", GLOBAL_LONGITUDE, GLOBAL_LATITUDE); //DEBUG CODE
  delay(10000);
}
