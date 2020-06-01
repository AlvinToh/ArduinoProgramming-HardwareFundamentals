const int speaker_pin = 9;

void setup() {
  pinMode(speaker_pin, OUTPUT);
}

void loop() {
  tone(speaker_pin, 440, 500);
  delay(1000);
}
