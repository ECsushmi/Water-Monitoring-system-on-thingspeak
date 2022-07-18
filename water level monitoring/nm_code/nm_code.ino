#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "Manda batharam..."; //SSID
char pass[] = "06060606"; // Password
//-------------------------------------------//
WiFiClient client;
unsigned long myChannelField = 1669091; // Channel ID
const int ChannelField = 1; // Which channel to write data
const char * myWriteAPIKey = "FQFHJ7AMQMNH1B4K"; // Your write API Key
int distance;
void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}

void loop()
{
if (Serial.available())
{
distance=Serial.read();
Serial.write(Serial.read());
}
if (WiFi.status() != WL_CONNECTED)
{

while (WiFi.status() != WL_CONNECTED)
{
WiFi.begin(ssid, pass);

delay(1000);
}

}
ThingSpeak.writeField(myChannelField, ChannelField, distance, myWriteAPIKey);
delay(1000);
}
