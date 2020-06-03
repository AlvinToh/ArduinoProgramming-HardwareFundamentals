#include <LiquidCrystal.h>

// Pins
const int temp_pin = A0;

// LCD object
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup()
{
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  
  float voltage;
  float temp_c;

  // Read voltage and convert to temperature (Celsius)
  voltage = analogRead(temp_pin) * 5.0 / 1023;
  temp_c = 100.0 * voltage - 50;
  
  // Print temperature to LCD
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print(temp_c);
  lcd.print(" C");
  
  delay(500);
}
