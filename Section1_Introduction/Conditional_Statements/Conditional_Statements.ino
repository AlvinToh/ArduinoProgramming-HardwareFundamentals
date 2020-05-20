int a = 11;
int b = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if ((a != 5) || ( b > 3)) {
    Serial.println("True");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
