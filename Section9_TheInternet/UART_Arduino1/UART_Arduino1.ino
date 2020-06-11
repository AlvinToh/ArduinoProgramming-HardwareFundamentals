#include <SoftwareSerial.h>

SoftwareSerial soft(8, 9); // Rx, Tx

void setup() {
  soft.begin(4800);
}

void loop() {
  soft.println("Hi");
  delay(1000);
}
