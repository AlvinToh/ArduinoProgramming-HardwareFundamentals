const int light_pin = A0;
const int led_pin = 6;
const int threshold = 900;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_val = analogRead(light_pin);

  if (light_val < threshold) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
}
