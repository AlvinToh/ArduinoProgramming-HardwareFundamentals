const int add_btn_pin = 2;
const int dec_btn_pin = 3;

const int debounce_delay = 50; //ms

//Globals
int counter = 0;
int add_btn_state = HIGH;
int add_btn_prev = HIGH;

int dec_btn_state = HIGH;
int dec_btn_prev = HIGH;
unsigned long last_debounce_time = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(add_btn_pin, INPUT_PULLUP);
  pinMode(dec_btn_pin, INPUT_PULLUP);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int add_btn_read = digitalRead(add_btn_pin);
  int dec_btn_read = digitalRead(dec_btn_pin);

  // Remember when the button changed states
  if (add_btn_read != add_btn_prev || dec_btn_read != dec_btn_read) {
    last_debounce_time = millis();
  }

  // Wait before checking the state of the button again
  if (millis() > (last_debounce_time + debounce_delay)) {
    if ( add_btn_read !=  add_btn_state ) {
      add_btn_state = add_btn_read;
      if (add_btn_state == LOW) {
        counter++;
        Serial.println(counter);
      }
    } else if (dec_btn_read != dec_btn_state) {
      dec_btn_state = dec_btn_read;
      if (dec_btn_state == LOW) {
        counter--;
        Serial.println(counter);
      }
    }
  }

  add_btn_prev = add_btn_read;
  dec_btn_prev = dec_btn_prev;
}
