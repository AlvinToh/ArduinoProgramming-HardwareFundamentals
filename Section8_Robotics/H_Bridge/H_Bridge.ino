const int pwm_pin = 9;
const int dir_1a_pin = 8;
const int dir_2a_pin = 7;

void setup() {
  pinMode(pwm_pin, OUTPUT);
  pinMode(dir_1a_pin, OUTPUT);
  pinMode(dir_2a_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  digitalWrite(dir_1a_pin, HIGH);
  digitalWrite(dir_2a_pin, LOW);
  analogWrite(pwm_pin, 127);
  
  // Stop spinning
  analogWrite(pwm_pin, 0);
  delay(1000);
  
  // Other direction at full speed
  digitalWrite(dir_1a_pin, LOW);
  digitalWrite(dir_2a_pin, HIGH);
  analogWrite(pwm_pin, 255);

  // Brake
  digitalWrite(dir_1a_pin, LOW);
  digitalWrite(dir_1a_pin, LOW);
  analogWrite(pwm_pin, 0);
  delay(1000);
               
}
