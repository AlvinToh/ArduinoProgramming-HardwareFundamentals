const int motor_pin = 6;

void setup() {
  pinMode(motor_pin, OUTPUT);
}

void loop() {
  // Slowly increase in speed
  for (int i = 0; i < 256; i++) {
    analogWrite(motor_pin, i);
    delay(10);
  }
  
    // Slowly decrease in speed
  for (int i = 255; i >= 0; i--) {
    analogWrite(motor_pin, i);
    delay(10);
  }
}
