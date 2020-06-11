#include <ESP8266WiFi.h>
 
// WiFi config
const char ssid[] = YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// Server, file, and port
const char hostname[] = "adafruit.com";
const String uri = "/testwifi/index.html";
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
  client.print("GET " + uri + " HTTP/1.1\r\n" + 
                "Host: " + hostname + "\r\n" +
                "Connection: close\r\n\r\n");
  delay(500);
 
  // Look for "this," and store whatever comes next
  String string = "Not found";
  for ( unsigned long i = 0; i < 500; i++ ) {
    if ( client.find("this, ") ) {
      string = client.readStringUntil('\n');
      while ( client.available() ) {
        client.read();
      }
      break;
    }
    delay(10);
  }
 
  // Print the string
  Serial.println(string);
 
  // Close TCP connection
  client.stop();
  Serial.println("Connection closed");
  
  delay(10000);
}
