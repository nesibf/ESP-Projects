#include <ESP8266WiFi.h>

const char* nname = "Jeff's Wi-Fi";
const char* pass = "1234567890";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP);
  WiFi.softAP(nname, pass);
  Serial.begin(115200);
  server.begin();
}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  if (req.indexOf("/homepage") != -1) {
    client.print("Harro, welcome to the homepage");
  }

  delay(1);
  Serial.println("Client disconnected.");
  // put your main code here, to run repeatedly:

}
