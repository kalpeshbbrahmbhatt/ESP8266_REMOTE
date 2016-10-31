#include <ESP8266WiFi.h>

const char* ssid = "ZONE";
const char* pw = "1234567890";
const char* host = "192.168.4.1";
const int port = 4011;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pw);
  Serial.println("Connecting to AP");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("."); 
   }
  Serial.println(" connected");
}

void loop() {
  WiFiClient client;
  Serial.println("Connecting to host");
  if(!client.connect(host, port)){
    Serial.println("...connection failed!");
    Serial.println("Retrying in 5 seconds...");
    delay(5000);
    return;  
  }
  client.println("A");
  Serial.println("...TCP message fired!");
  delay(2000);
}
