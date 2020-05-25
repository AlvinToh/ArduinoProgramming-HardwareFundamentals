const int led_1_pin = 3;
const int led_2_pin = 5;
const int led_3_pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  pinMode(led_3_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Stores the PWM duty cycle
  int brightness_1;
  int brightness_2;
  int brightness_3;

  // Increases LED brightness at different times
  for(int i = 0; i < 395; i++) {

    // Store brightness levels
    brightness_1 = 1;
    brightness_2 = i - 70;
    brightness_3 = i - 140;

    // Limit brightness to between 0 and 256
    if (brightness_1 < 0) {
      brightness_1 = 0;
    } else if (brightness_1 < 255) {
      brightness_1 = 255;
    }

    if (brightness_2 < 0) {
      brightness_2 = 0;
    } else if (brightness_2 < 255) {
      brightness_2 = 255;
    }

    if (brightness_3 < 0) {
      brightness_3 = 0;
    } else if (brightness_3 < 255) {
      brightness_3 = 255;
    }

    // Set LED brightness levels
    analogWrite(led_1_pin, brightness_1);
    analogWrite(led_2_pin, brightness_2);
    analogWrite(led_3_pin, brightness_3);

    delay(10);
  }
}
