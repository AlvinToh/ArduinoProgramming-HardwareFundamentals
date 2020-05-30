const int btn_pin = 2;
const int led_pin = 6;

int btn_prev;
int counter = 0;

void setup() {
  
  // Configure pins
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  
  // Set Initial LED state
  digitalWrite(led_pin, LOW);
}

void loop() {
  
  int btn_state;
  
  //Read button state;
  btn_state = digitalRead(btn_pin);
  
  //Flash LED on rising edge(let go of button)
  if ((btn_prev == LOW) && (btn_state == HIGH)) {
    digitalWrite(led_pin, HIGH);
    delay(500);
    digitalWrite(led_pin, LOW);
  }
  
  btn_prev = btn_state;
}
