#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

IPAddress MyIP(192,168,4,1);

WiFiServer server(MyIP, 4011);

/* Set these to your desired credentials. */
const char *ssid = "NS_SECURE";
const char *password = "1234567890";

uint32_t chip_id;

String resp;

void setup() {
  Serial.begin(9600);
  delay(10);
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(ssid, password);
  server.begin();

}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    resp = client.readStringUntil('\n');
    Serial.println(resp);
  }
}
