const int data_pin = 2;
const int clock_pin = 3;
const int latch_pin = 4;

void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte x = B10000000;
 
  
 // LEDs on one at a time;
 for (int i = 0; i < 8; i++){
    shiftDisplay(x);
    x = x >> 1;
    delay(200);
  }
  
  x = B00000001;
 for (int i = 0; i < 8; i++){
    shiftDisplay(x);
    x = x << 1;
    delay(200);
  }
}

void shiftDisplay(byte data) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  digitalWrite(latch_pin, HIGH);
}
