#include <Arduino.h>

#include <WiFi.h>

 

const char *ssid = "miniannewifi";

const char *password = "MiniAnne2.0";

 

IPAddress IP = IPAddress {192, 168, 42, 1};

IPAddress gateway = IPAddress (192, 168, 42, 1);

IPAddress NMask = IPAddress (255, 255, 255, 0);

 

WiFiServer server(80);

 

void setup()

{

  Serial.begin(115200);

  Serial.println();

  Serial.print("System Start");

 

  WiFi.mode(WIFI_AP);  

  WiFi.softAP(ssid,password);

  delay(1000);

 

  WiFi.softAPConfig(IP, gateway, NMask);

 

  delay(1000);

  

  IPAddress myIP = WiFi.softAPIP();

  Serial.println();

  Serial.print("AP IP address: ");

  Serial.println(myIP);  

 

  server.begin();

}

 

void loop()

{

  // put your main code here, to run repeatedly:

}