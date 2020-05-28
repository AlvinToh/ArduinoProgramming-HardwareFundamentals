int led_pin [] = {3, 5, 6, 9, 10, 11};
const int ms = 100;
const int low = 10;
const int med = 140;
const int high = 255;
 
void setup() {
  for (int i=0; i<sizeof(led_pin); i++) {
    pinMode (led_pin [i], OUTPUT);
  }
}
 
void loop() {
  for (int i = 0; i<sizeof(led_pin); i++){
     ShowLarsonScanner(i);
  }
  for ( int i= sizeof(led_pin); i>-1; i--){
    ShowLarsonScanner(i); 
  }
}

void ShowLarsonScanner(int r) {
  analogWrite(led_pin[r], high);
      delay (ms);
      if ( r == 1 || r!= 4) {
        analogWrite(led_pin[r - 1], med);
        analogWrite(led_pin[r + 1], med);
      } else if (r == 0) {
        analogWrite(led_pin[r + 1], med);
      } else if (r == 5) {
        analogWrite(led_pin[r - 1], med);
      } else {
        analogWrite(led_pin[r - 1], med);
        analogWrite(led_pin[r + 1], med);
        analogWrite(led_pin[r - 2], low);
        analogWrite(led_pin[r + 2], low);
      }
  for ( int a = 0; a< sizeof(led_pin); a++) {
    digitalWrite ( led_pin [a], LOW );
  }
}
 
 
