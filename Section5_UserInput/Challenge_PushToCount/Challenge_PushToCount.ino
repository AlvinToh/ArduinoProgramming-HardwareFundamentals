const int btn_pin = 2;

int btn_prev = HIGH;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
   pinMode(btn_pin, INPUT_PULLUP);

   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btn_state;

  btn_state = digitalRead(btn_pin);

  if ((btn_prev == HIGH) && (btn_state == LOW)) {
      counter++;
      Serial.println(counter);
  }

  btn_prev = btn_state;
}
