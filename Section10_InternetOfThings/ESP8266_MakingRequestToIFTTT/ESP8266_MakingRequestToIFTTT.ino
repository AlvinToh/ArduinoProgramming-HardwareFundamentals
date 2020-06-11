#include <ESP8266WiFi.h>
 
// WiFi config
const char ssid[] = "YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// IFTTT config
const String ifttt_trigger = "my_reminder";
const String ifttt_key = "cIL7tAJ8rAIlP07aHcvCUd";

// Server, file, and port
const char hostname[] = "maker.ifttt.com";
const String uri = "/trigger/" + ifttt_trigger +
                    "/with/key/" + ifttt_key;
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

  // Construct HTTP request
  String req = "POST" + uri + " /HTTP/1.1\r\n" +
                "Host: " + hostname + "\r\n" +
                "Connection: close\r\n" +
                "\r\n";
 
  // Connect to server
  Serial.print("Connecting to ");
  Serial.println(hostname);
  if ( client.connect(hostname, port) == 0 ) {
    Serial.println("Connection failed");
  }
 
  // Send request for file from server
  client.print(req);
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
  
  delay(60000);
}
