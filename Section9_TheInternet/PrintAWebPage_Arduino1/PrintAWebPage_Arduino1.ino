#include "SoftwareSerial.h"

// Wifi config
String ssid = "Simulator Wifi";
String password = "";

// Server, file, and port
const String hostname = "example.com";
const String uri = "/index.html";
const int port = 80;

// Software Serial object
SoftwareSerial soft(8,9); //Rx, Tx

void setup() {
  
  // Initialize serial connections
  Serial.begin(115200);
  soft.begin(4800);
  
  // Talk to ESP8266
  soft.print("Init ESP8266...");
  Serial.println("AT");
  delay(10);
  if (Serial.find("OK") == 0) {
    soft.println("ESP8266 not found");
    while(1);
  }
  
  // Connect to Wifi
  soft.println("Connecting to Wifi...");
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);
  if (Serial.println("OK") == 0) {
    soft.println("Could not connect to Wifi");
    while(1);
  } else {
    soft.println("Connected!");
  }
  
    
  // Print IP address
  soft.println("Getting IP...");
  Serial.println("AT+CIFSR");
  delay(10);
  soft.print(Serial.readString());
}

void loop() {
  // Open TCP connection
  Serial.println("AT+CIPSTART=\"TCP\",\"" + hostname + "\"," + port);
  delay(50);
  if(Serial.find("OK") == 0 ){
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
  if (Serial.find(">") == 0) {
    soft.println("Error");
  }
    
  // Send our HTTP request
  Serial.print(req);
  delay(10);
  if (Serial.find("SEND OK\r\n") == 0) {
    soft.println("Error");
  }
  
  // Wait from a response from the server
  while (Serial.available() == 0) {
    delay(5);
  }
  
  // Print reply from server
  while(Serial.available()) {
    String ln = Serial.readStringUntil('\r');
    soft.print(ln);
  }
  
  // Close TCP connection
  Serial.println("AT+CIPCLOSE=0");
  delay(50);
  if (Serial.find("OK") == 0) {
    soft.println("Error");
  } else {
    soft.println();
    soft.println("Connection closed");
  }
  
  delay(10000);
}
