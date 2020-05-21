int a = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while ( i < 3 ) {
    Serial.println("hello, world!");
    a++;
    if (a == 2) {
      continue;
    }
    i++;
  }
  Serial.println("done!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
