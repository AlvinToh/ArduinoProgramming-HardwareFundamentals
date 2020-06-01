const int ain_pin = A0;
const int led_pin = 3;
const int pot_pin = 13;
const int btn_pin = 2;

int btn_prev = HIGH;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pot_pin, led_pin);
  pinMode(btn_pin, INPUT_PULLUP);
}

void loop() {
  int btn_state;

  btn_state = digitalRead(btn_pin);

  if ((btn_prev == HIGH) && (btn_state == LOW)) {
    counter+=51;
    if (counter > 255) {
      counter = 0;
    }
    analogWrite(led_pin, counter);
  }
  
  btn_prev = btn_state;
  
  int val = analogRead(ain_pin);
  
  int conv = map(val, 0, 1023, counter, 255);
  analogWrite(led_pin, conv);
  
  delay(100);
}
