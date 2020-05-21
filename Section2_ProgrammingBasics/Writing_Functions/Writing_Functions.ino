int i = 0;
int e;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sayHi();
}

void loop() {
  // put your main code here, to run repeatedly:
  e = isEven(i);
  Serial.print(i);
  Serial.print(": ");
  if (e == 1) {
    Serial.println("even");
  } else {
    Serial.println("odd");
  }

  i++;

  delay(500);
}

int isEven(int a) {
  if (a % 2 == 0) {
    return 1;
  }
  return 0;
}

void sayHi() {
  Serial.println("Hi");
}
