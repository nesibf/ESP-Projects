#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

MDNSResponder mdns;

const char* ssid = "Huang Family Network";
const char* password = "SJHH#100";

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS Responder started.");
  }

  server.on("/", []{
    server.send(200, "text/html", "HELLO WORLD!!!!!");
  });
  server.begin();
  Serial.println("HTTPS Server started");
}

void loop(void) {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
