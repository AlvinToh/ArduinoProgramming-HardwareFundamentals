#include <LiquidCrystal.h>

// Pins
const int l_pin = 8;
const int r_pin = 9;

// Number of columns on LCD
const int lcd_width = 16;

// LCD object
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

// Define a custom LCD character (5x7) that looks
// like a person.
byte person[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010,
  B01010,
};

// Character's position
int person_x = 8;

// Button states
int l_prev = HIGH;
int r_prev = HIGH;

void setup()
{
  
  // Set pullups on buttons
  pinMode(l_pin, INPUT_PULLUP);
  pinMode(r_pin, INPUT_PULLUP);
  
  // Initialize and clear LCD 
  lcd.begin(16, 2);
  lcd.clear();
  
  // Register custom character
  lcd.createChar(0, person);
}

void loop()
{
  
  // Look for left button press and move character to the left
  int l_state = digitalRead(l_pin);
  if ( (l_prev == HIGH) && (l_state == LOW) ) {
    person_x--;
    if ( person_x < 0 ) {
      person_x = 0;
    }
  }
  
  // Look for righ button press and move character to the righ
  int r_state = digitalRead(r_pin);
  if ( (r_prev == HIGH) && (r_state == LOW) ) {
    person_x++;
    if ( person_x >= lcd_width ) {
      person_x = lcd_width - 1;
    }
  }
  
  // Remember previous button states
  l_prev = l_state;
  r_prev = r_state;
  
  // Clear screen, draw character
  lcd.clear();
  lcd.setCursor(person_x, 1);
  lcd.write(byte(0));
  
  delay(20);
}
