void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String input = "Eating trees is great!";
  input.replace('A', '4');
  input.replace('a', '4');
  input.replace('E', '3');
  input.replace('e', '3');
  input.replace('I', '1');
  input.replace('i', '1');

  Serial.println(input);
}


void loop() {
  // put your main code here, to run repeatedly:

}
