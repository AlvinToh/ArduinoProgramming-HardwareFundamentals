#include <ESP8266WiFi.h>

// Wifi Config
const char ssid[] = "mySSID";
const char password[] = "myPassword";

// Server, file, and post
const char hostname[] = "example.com";
const String uri = "/index.html";
const int port = 80;

// Wifi client
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while( Wifi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  // Show that we are connected
  Serial.println("Connected!");
  
}

void loop() {
  // Connect to server
  Serial.println("Connecting to ");
  Serial.println(hostname);
  if (client.connect(hostname, port) == 0) {
    Serial.println("Conenctioned failed");
  }

  // Send request for file
  client.print("GET " + uri + " HTTP/1.1\r\n" + 
                "Host: " + hostname + "\r\n" +
                "Connection: close\r\n" + 
                "\r\n");           

  delay(500);

  // Print reply from server
  while(client.available()) {
    String ln = client.readStringUntil('\r');
    Serial.print(ln);
  }

  // Close TCP connection
  client.stop();
  Serial.println();
  Serial.println("Connection closed");

  delay(10000);
}
