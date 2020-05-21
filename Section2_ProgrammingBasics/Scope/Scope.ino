int i = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 3;
  int b = 5;

  Serial.println(add(a, b));

  delay(500);
}

int add(int x, int y) {
  //Serial.println(a);
  Serial.print(x);
  Serial.print("+");
  Serial.println(y);
  return x + y;
}
