const int len = 10;
char my_array[len] = "hello";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(my_array);
  delay(1000);
}
