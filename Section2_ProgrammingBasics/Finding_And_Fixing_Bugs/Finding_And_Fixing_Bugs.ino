void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i < 10; i++) {
    Serial.println(i);
    if ( i == 10) {
      Serial.println("Turn LED on");
      // LED Turn on
    }
  }

  delay(1000);
}
