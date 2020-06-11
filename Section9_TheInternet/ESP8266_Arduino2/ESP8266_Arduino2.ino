#include <SoftwareSerial.h>

SoftwareSerial soft(8, 9); // Rx, Tx

void setup() {
  soft.begin(4800);
  Serial.begin(4800);
}

void loop() {
  
  // Look for data from HW serial
  if ( Serial.available() ) {
    char c = Serial.read();
    soft.print(c);
  }
  
  // Look for data from SW serial
  if ( soft.available() ) {
    char c = soft.read();
    Serial.print(c);
  }
}
