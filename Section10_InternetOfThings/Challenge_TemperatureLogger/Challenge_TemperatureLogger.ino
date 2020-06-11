#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
 
// Pins
const int temp_pin = A0;
 
// WiFi config
const char ssid[] = "YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// ThingSpeak config
const unsigned long channel_id = YOUR CHANNEL ID;
const char write_api_key[] = "YOUR WRITE API KEY";
 
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
 
  // Connect to ThingSpeak
  ThingSpeak.begin(client);
}
 
void loop() {
 
  float voltage;
  float temp_c;
 
  // Read temperature sensor (remember to multiply by 3!)
  voltage = (analogRead(temp_pin) * 1.0 / 1023) * 3.0;
  temp_c = 100.0 * voltage - 50;
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("V degC: ");
  Serial.println(temp_c);
 
  // Write values to our ThingSpeak channel
  Serial.println("Posting " + String(temp_c, 2) + " to ThingSpeak");
  ThingSpeak.setField(1, String(temp_sc, 2));
  ThingSpeak.writeFields(channel_id, write_api_key);
 
  delay(30000);
}
