// SIM808 Module AT Commands

char * AT_GNSPWR = "AT+CGNSPWR=1";
char * AT_GNSSEQ = "AT+CGSNSEQ=RMC";
char * AT_GNSINF = "AT+CGNSINF";

char * AT_GPRS_CONN = "AT+SABPR=3,1,CONTYPE,GPRS";
char * AT_GPRS_APN = "AT+SAPBR=3,1,APN,netone.net";
char * AT_GPRS_ON = "AT+SAPBR=1,1";
char * AT_GPRS_IP = "AT+SAPBR=2,1";

char * AT_HTTP_INIT = "AT+HTTPINIT";
char * AT_HTTP_CID = "AT+HTTPPARA=CID,1";
char * AT_HTTP_URL = "AT+HTTPPARA=URL,http://20.164.38.53/api?id=Goat1&ln=%s&lt=%s\r\n";
char * AT_HTTP_DATA = "AT+HTTPDATA=256,10000";
char * AT_HTTP_GET = "AT+HTTPACTION=0";
