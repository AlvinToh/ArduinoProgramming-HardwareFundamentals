#include <ESP8266WiFi.h>

// Wifi Config
const char ssid[] = "mySSID";
const char password[] = "myPassword";

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
  // put your main code here, to run repeatedly:

}
