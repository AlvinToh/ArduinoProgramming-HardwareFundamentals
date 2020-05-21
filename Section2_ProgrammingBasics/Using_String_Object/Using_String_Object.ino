void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String myString = "hello, world";

  myString.concat("lings");
  myString.toUpperCase();

  Serial.println(myString);
}

void loop() {
  // put your main code here, to run repeatedly:

}
