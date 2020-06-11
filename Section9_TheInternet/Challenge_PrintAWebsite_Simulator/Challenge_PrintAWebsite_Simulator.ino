#include "SoftwareSerial.h"
 
// WiFi config
String ssid     = "Simulator Wifi";
String password = "";
 
// Server, file, and port
const String hostname = "http://wifitest.adafruit.com";
const String uri = "/testwifi/index.html";
const int port = 80;
 
// Software serial object
SoftwareSerial soft(8, 9); // RX, TX
 
void setup() {
  
  // Initialize serial connections
  Serial.begin(115200);
  soft.begin(9600);
  
  // Talk to ESP8266
  soft.println("Init ESP8266...");
  Serial.println("AT");
  delay(10);
  if ( Serial.find("OK") == 0 ) {
    soft.println("ESP8266 not found");
    while(1);
  }
  
  // Connect to WiFi
  soft.println("Connecting to WiFi...");
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);
  if ( Serial.find("OK") == 0 ) {
    soft.println("Could not connect to WiFi");
    while(1);
  } else {
    soft.println("Connected!");
  }
}
 
void loop() {
  
  // Open TCP connection
  Serial.println("AT+CIPSTART=\"TCP\",\"" + hostname + "\"," + port);
  delay(50);
  if ( Serial.find("OK") == 0 ) {
    soft.println("Error");
  }
 
  // Construct HTTP request
  String req = "GET " + uri + " HTTP/1.1\r\n" +
                        "Host: " + hostname + "\r\n" +
                        "Connection: close\r\n" +
                        "\r\n";
  int len = req.length();
  
  // Send our request length
  Serial.print("AT+CIPSEND=");
  Serial.println(len);
  delay(10);
  if ( Serial.find(">") == 0 ) {
    soft.println("Error");
  }
 
  // Send our http request
  Serial.print(req);
  delay(10);
  if (!Serial.find("SEND OK\r\n")) {
    soft.println("Error");
  }
  
  // Wait for a response from the server
  while( Serial.available() == 0 ) {
    delay(5);
  }
  
  // Look for "this," and store whatever comes next
  String string = "Not found";
  for ( unsigned long i = 0; i < 500; i++ ) {
    if ( Serial.find("this, ") ) {
      string = Serial.readStringUntil(':');
      while ( Serial.available() ) {
        Serial.read();
      }
      break;
    }
    delay(10);
  }
 
  // Print the string
  soft.println(string);
  
  // Close TCP connection
  Serial.println("AT+CIPCLOSE=0");
  delay(50);
  if ( Serial.find("OK") == 0 ) {
    soft.println("Error");
  } else {
    soft.println();
    soft.println("Connection closed");
  }
  
  delay(10000);
}
