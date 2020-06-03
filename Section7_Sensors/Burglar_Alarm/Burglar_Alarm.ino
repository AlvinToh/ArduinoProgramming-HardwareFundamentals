// Pins
const int x_pin = A0;
const int y_pin = A1;
const int z_pin = A2;
const int speaker_pin = 3;
 
// Volts per G-Force
const float sensitivity = 0.206;
 
// Ideal conditions to turn on Alarm (G-Force)
const float ideal_x = 0.0;
const float ideal_y = 0.0;
const float ideal_z = 1.0;

// Set how long the burglar alarm is set for
unsigned long last_speaker_time = 0;
const int speaker_delay = 10000; //ms
 
// Acceptable tolerance around 1G (z) or 0G (x, y)
const float tolerance = 0.1;
 
void setup() {
  analogReference(EXTERNAL);
  pinMode(speaker_pin, OUTPUT);
}
 
void loop() {
 
  float x;
  float y;
  float z;
  float freq = 440;
 
  // Read pins and convert to G
  x = (analogRead(x_pin) - 512) * 3.3 / (sensitivity * 1023);
  y = (analogRead(y_pin) - 512) * 3.3 / (sensitivity * 1023);
  z = (analogRead(z_pin) - 512) * 3.3 / (sensitivity * 1023);
  
  // Turn on Alarm if accelerometer moving
  if ( (x < ideal_x - tolerance) || (x > ideal_x + tolerance) &&
       (y < ideal_y - tolerance) || (y > ideal_y + tolerance) &&
       (z < ideal_z - tolerance) || (z > ideal_z + tolerance) 
     ) {
    tone(speaker_pin, freq);
    last_speaker_time = millis();
  }
  
  // Setting the Burglar alarm to be 10 seconds
  if (millis() > (last_speaker_time + speaker_delay)) {
    noTone(speaker_pin);
  }
 
  delay(100);
}
