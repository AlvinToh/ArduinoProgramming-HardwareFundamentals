void setup() {
  Serial.begin(9600);
}
 
void loop() {
 
  String fname = "";
  String lname = "";
 
  // Ask for and read first name
  Serial.println("Enter your first name");
  while ( fname.equals("") ) {
    fname = Serial.readString();
  }
 
  // Ask for and read last name
  Serial.println("Enter your last name");
  while ( lname.equals("") ) {
    lname = Serial.readString();
  }
 
  // Concatenate first and last name with a space in between
  fname.concat(" ");
  fname.concat(lname);
 
  // Say hello to the user
  Serial.print("Hello, ");
  Serial.println(fname);
  Serial.println();
}
