#include <SoftwareSerial.h>
#define TIMEOUT 5000 // mS  

SoftwareSerial esp8266(7, 6); // RX, TX
String AP="gratis";
String PASS="prayogo27";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  esp8266.begin(9600);
  esp8266.println("AT+CWMODE=1");
  delay(1000);
  esp8266.println("AT+CWJAP=\""+AP+"\",\""+PASS+"\"");
  delay(1000);
}


void loop() {
  // put your main code here, to run repeatedly:
   SendData();
   delay(5000);

}



void SendData()
{
  ulang :
  String cmd = "AT+CIPSTART=\"TCP\",\"";cmd += "192.168.43.74" ;
  cmd += "\",80";
  esp8266.println(cmd);
  long t=millis()+TIMEOUT;
  while(millis() < t)
  {
  if (esp8266.available()){
    char ch = esp8266.read();
    Serial.print(ch);
  }
  }
  Serial.println();
  
  if(esp8266.find("ERROR"))
  { 
    Serial.println("Koneksi error");
    esp8266.println("AT+CIPCLOSE");
    goto ulang;
    
  }

  cmd = "GET /afhd/index.php/afhd/status_?value=123\r\n\r\n";
  esp8266.print("AT+CIPSEND=");
  esp8266.println(cmd.length());
  t=millis()+TIMEOUT;
  while(millis() < t)
  {
  if (esp8266.available()){
    char ch = esp8266.read();
    Serial.print(ch);
  }
  }
  if(esp8266.find(">"))
  { 
    Serial.println("Terhubung");   
  }
  else if(esp8266.find("ERROR"))
  { 
    Serial.println("Koneksi error.");
    esp8266.println("AT+CIPCLOSE");
    goto ulang;
    
  }
  
 /* t=millis()+TIMEOUT;
  while(millis() < t){
  if (esp8266.available()){
    char ch = esp8266.read();
    Serial.print(ch);
  }
  }
  Serial.println();
  */
  esp8266.print(cmd);
}
