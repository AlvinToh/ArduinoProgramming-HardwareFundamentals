const int light_pin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_val = analogRead(light_pin);
  Serial.println(light_val);
  delay(100);
}
