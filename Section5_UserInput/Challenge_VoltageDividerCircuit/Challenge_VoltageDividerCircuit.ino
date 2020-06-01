const int btn_pin = 2;
const int ain_pin = A0;
const int debounce_delay = 50; // ms
 
// Globals
int btn_state = HIGH;
int btn_prev = HIGH;
unsigned long last_debounce = 0;
 
void setup() {
  pinMode(btn_pin, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop() {
  
  // Read the current position of the button
  int btn_read = digitalRead(btn_pin);
 
  // Remember when the button changed states
  if ( btn_read != btn_prev ) {
    last_debounce = millis();
  }
 
  // Wait before checking the state of the increment button again
  if ( millis() > (last_debounce + debounce_delay) ) {
    if ( btn_read != btn_state ) {
      btn_state = btn_read;
      if ( btn_state == LOW ) {
 
        // Read analog voltage and convert to voltage (float)
        int val = analogRead(ain_pin);
        float voltage = val * 5.0 / 1023;
 
        // Print
        Serial.println(voltage);
      }
    }
  }
 
  // Remember the previous states for next loop()
  btn_prev = btn_read;
}
