const int btn_pin = 2;
const int led_pin = 6;
int led_state = LOW;
int prev_state = HIGH;

void setup() {
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);

  // Default is LOW
  digitalWrite(led_pin, led_state);
}

void loop() {
  if ((prev_state == HIGH) && (digitalRead(btn_pin) == LOW)) {
    if (led_state == LOW) {
      led_state = HIGH;
    } else {
      led_state = LOW;
    }
    digitalWrite(led_pin, led_state);
  }

  prev_state = digitalRead(btn_pin);
}
