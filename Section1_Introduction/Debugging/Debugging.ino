void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("A ");
  delay(1000);
  Serial.println("B");
  delay(1000);
}
