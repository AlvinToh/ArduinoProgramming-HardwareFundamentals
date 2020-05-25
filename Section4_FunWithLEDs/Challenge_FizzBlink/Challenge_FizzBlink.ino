const int led_5_pin = 5;
int counter = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_5_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (counter % 3 == 0) {
      digitalWrite(led_5_pin, HIGH);
      delay(500);
      digitalWrite(led_5_pin, LOW);
      delay(500);
    } else {
      Serial.println(counter);
  }

  counter++;
  delay(500);
}
