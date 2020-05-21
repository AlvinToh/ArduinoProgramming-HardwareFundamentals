int i = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (i >= 0) {
    Serial.println(i);
    i--;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
