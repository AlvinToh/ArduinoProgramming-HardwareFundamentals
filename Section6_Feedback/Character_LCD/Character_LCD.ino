#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter = millis()/ 1000;
  lcd.setCursor(0, 1);
  lcd.print(counter);
}
