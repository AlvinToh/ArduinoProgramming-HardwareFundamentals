#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Create an object.

int note_duration [] {300, 300, 300, 300, 300, 300, 600, 300, 300, 300, 300, 300, 300, 600};
int note_freq [] {262, 262, 392, 392, 440, 440, 392, 349, 349, 329, 329, 294, 294, 262};
int note_duration2 [] {300, 300, 300, 300, 300, 300};
int note_freq2 [] {262, 196, 193, 220, 246, 262};
int speaker = 9;
const int but_pin1 = 10;
const int but_pin2 = 8;


//Global var
int but_time = 0;
int debounce_time = 20;
int read_but1;
int read_but2;
int but1_stat = HIGH;
int but2_stat = HIGH;
int but1_prev = HIGH;
int but2_prev = HIGH;

void setup() {
  lcd.begin(16, 2);//Set the display ratio
  pinMode(but_pin1, INPUT_PULLUP);
  pinMode(but_pin2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  read_but1 = digitalRead(but_pin1);
  read_but2 = digitalRead(but_pin2);
  
  if (read_but1 != but1_prev  || read_but2 != but2_prev){
    but_time = millis();//calls a timer function 
  }

  //If the time the button was held down is greater than our debounce time + but time continue on
  if (millis() > debounce_time + but_time) {
    if (read_but1 != but1_stat || read_but2 != but2_stat) {
      but1_stat = read_but1;
      but2_stat = read_but2;
      if (but1_stat == LOW) {
        for(int i = 0; i < 14; i++){
          lcd.setCursor(0,0);
          lcd.print("Now Playing");
          lcd.setCursor(0,1);
          lcd.print("Twinkle Twinkle Little Star");
          tone(speaker, note_freq[i],note_duration[i]);
          delay(note_duration[i]*1.5);
        }
        lcd.clear();
      }
      if (but2_stat == LOW) {
        for(int x = 0; x<6; x++) {
          lcd.setCursor(0,0);
          lcd.print("Now Playing");
          lcd.setCursor(0,1);
          lcd.print("I have no idea");
          tone(speaker, note_freq2[x],note_duration2[x]);
          delay(note_duration2[x]*1.5);
        }
        lcd.clear();
      }
    }
  }
  //remember the button state for the next loop
  but1_prev = read_but1;
  but2_prev = read_but2;
}
