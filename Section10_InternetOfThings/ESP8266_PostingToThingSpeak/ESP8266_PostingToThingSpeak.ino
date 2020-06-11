#include <ESP8266WiFi.h>
#include "ThingSpeak.h";

// WiFi config
const char ssid[] = YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// ThingSpeak config
const unsigned long channel_id = 303230;
const char write_api_key[] = "PR3GJY4QJ8KITISX";
 
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

  randomSeed(micros());
}
 
void loop() {

  // Generate random number 1-100
  int rando = random(1, 101);
 
  // Write values to our ThingSpeak Channel
  Serial.println("Posting " + String(rando) + " to ThingSpeak");
  ThingSpeak.setField(1, rando);
  ThingSpeak.writeFields(channel_id, write_api_key);
  
  delay(30000);
}
