#include <ESP8266WiFi.h>
 
// WiFi config
const char ssid[] = "YOUR NETWORK'S SSID";
const char password[] = "YOUR NETWORK'S PASSWORD";
 
// Pins
const int btn_pin = 0;
 
// IFTTT settings
const String ifttt_trigger = "iot_button";
const String ifttt_key = "YOUR IFTTT KEY";
 
// Server, file, and port
const char hostname[] = "maker.ifttt.com";
const String uri = "/trigger/" + ifttt_trigger +
                    "/with/key/" + ifttt_key;
const int port = 80;
 
// WiFiClient object
WiFiClient client;
 
// Globals
int btn_prev = HIGH;
 
void setup() {
 
  // Set button pin to input with pullup
  pinMode(btn_pin, INPUT_PULLUP);
  
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
 
  // Sample button state
  int btn_state = digitalRead(btn_pin);
 
  // Send GET request to IFTTT if button is pressed
  if ( (btn_prev == HIGH) && (btn_state == LOW) ) {
 
    // Connect to server
    Serial.print("Connecting to ");
    Serial.println(hostname);
    if ( client.connect(hostname, port) == 0 ) {
      Serial.println("Connection failed");
    }
 
    // Send request to IFTTT
    client.print("GET " + uri + " HTTP/1.1\r\n" + 
                "Host: " + hostname + "\r\n" +
                "Connection: close\r\n\r\n");
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
  }
 
  // Store previous button state
  btn_prev = btn_state;
}
