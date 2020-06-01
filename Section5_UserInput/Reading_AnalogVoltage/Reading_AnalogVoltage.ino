int const ain_pin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(min_pin);
  float voltage = val * 5.0 / 1023;

  Serial.println(voltage);
  delay(100);
}
