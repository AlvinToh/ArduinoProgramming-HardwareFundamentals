const int trig_pin = 7;
const int pw_pin = 7;
const int trig_delay = 25; // microseconds
const int speaker_pin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration;
  float cm;

  // Tell distance to sent out a pulse
  pinMode(trig_pin, OUTPUT);
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // Measure time of pulse on PW pin
  pinMode(pw_pin, INPUT);
  duration = pulseIn(pw_pin, HIGH);

  // Convert time to distance
  cm = duration / 58.8;

  // Map to a frequency and play it
  float freq = 14.003 * cm - 15.01;
  tone(speaker_pin, freq);

  delay(100);
}
