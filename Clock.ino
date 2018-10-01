#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 9, 7, 6, 5, 4);

// Pin Definitions
int LM35Pin = A0;


// Variables
int h = 7; 
int m = 16;
int s = 00;
int flag;
int TIME; 
const int hs = 8;
const int ms = 9;
int state1;
int state2;

// Setup
void setup() {
  initDisplay();
}

// Main Program Loop
void loop() {
  lcd.setCursor(0, 0);
  s = s + 1;
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  if (flag < 12) lcd.print(" AM");
  if (flag == 12) lcd.print(" PM");
  if (flag > 12) lcd.print(" PM");
  if (flag == 24) flag = 0;
  delay(1000);
  lcd.clear();
  if ( s == 60) {
    s = 0;
    m = m + 1;
  }

  if (m == 60) {
    m = 0;
    h = h + 1;
    flag = flag + 1;
  }
  
  if ( h == 13) {
    h = 1;
  }
  lcd.setCursor(0,1 );
  lcd.print("Ready");
  
  state1 = digitalRead(hs);
  if (state1 == 1) {
    h = h + 1;
    flag = flag + 1;
    if (flag < 12) lcd.print(" AM");
    if (flag == 12) lcd.print(" PM");
    if (flag > 12)  lcd.print(" PM");
    if (flag == 24) flag=0;
    if (h == 13) h = 1;
  }
  
  state2 = digitalRead(ms);
  if (state2 == 1) {
    s = 0;
    m = m + 1;
  }

}

// Initialize Display
void initDisplay() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Ready");
}

// Refresh Display
void refreshDisplay(String d, String m, String y, String h, String m, String s) {
  char str[12];
  sprintf( str, "%s/%s/%s %s:%s:%s", d, m, y, h, m, s );
  lcd.print( str );
}
