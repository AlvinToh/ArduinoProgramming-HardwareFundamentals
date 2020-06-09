// Pins for motor A
const int a_pwm_pin = 9;
const int a_dir1_pin = 8;
const int a_dir2_pin = 7;

// Pins for motor B
const int b_pwm_pin = 10;
const int b_dir1_pin = 11;
const int b_dir2_pin = 12;

void setup() {
  
  // Set up pins for motor A
  pinMode(a_pwm_pin, OUTPUT);
  pinMode(a_dir1_pin, OUTPUT);
  pinMode(a_dir2_pin, OUTPUT);
  
  // Set up pins for motor B
  pinMode(b_pwm_pin, OUTPUT);
  pinMode(b_dir1_pin, OUTPUT);
  pinMode(b_dir2_pin, OUTPUT);
}

void loop() {

  // Forward at full speed
  forward(255);
  delay(1000);
  
  // Turn left at half speed
  left(127);
  delay(1000);
  
  // Turn right at half speed
  right(127);
  delay(1000);
  
  // Backward at half speed
  backward(127);
  delay(1000);
  
  // Stop
  stop();
  delay(1000);
}

// Drive forward
void forward(int speed) {
  
  // Check to make sure speed is 0-255
  if ( speed < 0 ) {
    speed = 0;
  }
  if ( speed > 255 ) {
    speed = 255;
  }
  
  // Motor A forward
  digitalWrite(a_dir1_pin, HIGH);
  digitalWrite(a_dir2_pin, LOW);
  analogWrite(a_pwm_pin, speed);
  
  // Motor B forward
  digitalWrite(b_dir1_pin, HIGH);
  digitalWrite(b_dir2_pin, LOW);
  analogWrite(b_pwm_pin, speed);
}

// Drive backward
void backward(int speed) {
  
  // Check to make sure speed is 0-255
  if ( speed < 0 ) {
    speed = 0;
  }
  if ( speed > 255 ) {
    speed = 255;
  }
  
  // Motor A backward
  digitalWrite(a_dir1_pin, LOW);
  digitalWrite(a_dir2_pin, HIGH);
  analogWrite(a_pwm_pin, speed);
  
  // Motor B backward
  digitalWrite(b_dir1_pin, LOW);
  digitalWrite(b_dir2_pin, HIGH);
  analogWrite(b_pwm_pin, speed);
}

// Turn left
void left(int speed) {
  
  // Check to make sure speed is 0-255
  if ( speed < 0 ) {
    speed = 0;
  }
  if ( speed > 255 ) {
    speed = 255;
  }
  
  // Motor A backward
  digitalWrite(a_dir1_pin, LOW);
  digitalWrite(a_dir2_pin, HIGH);
  analogWrite(a_pwm_pin, speed);
  
  // Motor B forward
  digitalWrite(b_dir1_pin, HIGH);
  digitalWrite(b_dir2_pin, LOW);
  analogWrite(b_pwm_pin, speed);
}

// Turn right
void right(int speed) { 
  
  // Check to make sure speed is 0-255
  if ( speed < 0 ) {
    speed = 0;
  }
  if ( speed > 255 ) {
    speed = 255;
  }
  
  // Motor A forward
  digitalWrite(a_dir1_pin, HIGH);
  digitalWrite(a_dir2_pin, LOW);
  analogWrite(a_pwm_pin, speed);
  
  // Motor B backward
  digitalWrite(b_dir1_pin, LOW);
  digitalWrite(b_dir2_pin, HIGH);
  analogWrite(b_pwm_pin, speed);
}

// Stop
void stop() {
  
  // Motor A brake
  digitalWrite(a_dir1_pin, LOW);
  digitalWrite(a_dir2_pin, LOW);
  analogWrite(a_pwm_pin, 0);
  
  // Motor B brake
  digitalWrite(b_dir1_pin, LOW);
  digitalWrite(b_dir2_pin, LOW);
  analogWrite(b_pwm_pin, 0);
}
