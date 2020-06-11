#include "SoftwareSerial.h"

// Wifi config
String ssid = "Simulator Wifi";
String password = "";

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

void loop(){
}
