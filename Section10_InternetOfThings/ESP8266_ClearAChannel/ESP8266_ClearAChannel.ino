#include <ESP8266WiFi.h>
 
// WiFi config
const char ssid[] = "YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// ThingSpeak config
const String user_api_key = "YOUR USER API KEY";
const String channel_id = "YOUR CHANNEL ID";
 
// Server, file, and port
const char hostname[] = "api.thingspeak.com";
const String uri = "/channels/" + channel_id + "/feeds?api_key=" + user_api_key;
const int port = 80;
 
// WiFiClient object
WiFiClient client;
 
void setup() {
 
  // Initialize Serial
  Serial.begin(9600);
  delay(100);
 
  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
 
  // Show that we are connected
  Serial.println("Connected!");
}
 
void loop() {
 
  // Connect to server
  Serial.print("Connecting to ");
  Serial.println(hostname);
  if ( client.connect(hostname, port) == 0 ) {
    Serial.println("Connection failed");
  }
 
  // Send request for file from server
  client.print("DELETE " + uri + " HTTP/1.1\r\n" + 
                "Host: " + hostname + "\r\n" +
                "Connection: close\r\n\r\n");
  delay(500);
 
  // Print reply from server
  while ( client.available() ) {
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }
 
  // Close TCP connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
  
  delay(30000);
}
