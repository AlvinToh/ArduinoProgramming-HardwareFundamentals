#include <Servo.h>

const int servo_pin = 9;
const int light_pin = A0;
Servo servo;

void setup() {
  servo.attach(servo_pin);
}

void loop() {
  int val = analogRead(light_pin);
    
  val = map(val, 0, 1023, 0 , 180);
  servo.write(val);
  
  delay(50);
}
