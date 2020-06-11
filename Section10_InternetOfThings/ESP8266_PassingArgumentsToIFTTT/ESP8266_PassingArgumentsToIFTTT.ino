#include <ESP8266WiFi.h>
 
// WiFi config
const char ssid[] = "<YOUR SSID>";
const char password[] = "<YOUR WIFI PASSWORD>";
 
// IFTTT settings
const String ifttt_trigger = "my_reminder";
const String ifttt_key = "<IFTTT KEY>";
 
// HTTP POST body
const String body = "{\"value1\":\"You need bread\"}";
 
// Server, file, and port
const char hostname[] = "maker.ifttt.com";
const String uri = "/trigger/" + ifttt_trigger +
            "/with/key/" + ifttt_key;
const int port = 80;
 
// WiFi Client
WiFiClient client;
 
void setup() {
 
  // Init Serial
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
 
  // Show we are connected
  Serial.println("Connected!");
}
 
void loop() {
 
  // Establish TCP connection
  Serial.print("Connecting to ");
  Serial.println(hostname);
  if ( !client.connect(hostname, port) ) {
    Serial.println("Connection failed");
  }
 
  // Send request
  String req = "POST " + uri + " HTTP/1.1\r\n" +
                "Host: " + hostname + "\r\n" +
                "Content-Type: application/json\r\n" +
                "Content-Length: " + body.length() + "\r\n" +
                "Connection: close\r\n" +
                "\r\n" +
                body + "\r\n";
  client.print(req);
  delay(500);
 
  // Print response
  while ( client.available() ) {
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }
 
  // Close TCP connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");
 
  delay(60000);
}
