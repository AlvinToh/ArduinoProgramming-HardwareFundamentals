const int motor_pin = 6;

void setup() {
  pinMode(motor_pin, OUTPUT);
}

void loop() {
  digitalWrite(motor_pin, HIGH);
  delay(500);
  digitalWrite(motor_pin, LOW);
  delay(500);
}
