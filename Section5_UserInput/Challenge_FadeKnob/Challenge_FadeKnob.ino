const int ain_pin = A0;
const int led_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(13, led_pin);
}

void loop() {
  int val = analogRead(ain_pin);
  
  int conv = map(val, 0, 1023, 0, 255);
  analogWrite(led_pin, conv);
  
  delay(100);
}
