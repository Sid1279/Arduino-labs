#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 8, 7, 5, 4);

int pushButton1 = 2;
int pushButton2 = 3;

int state1;
int state2;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);-
}

void loop() {
  state1 = digitalRead(pushButton1);
  state2 = digitalRead(pushButton2);
  
  lcd.clear();
  if (!state1 && !state2)
  {
    lcd.setCursor(0,0);
    lcd.print("Both are on!!!");
    lcd.setCursor(0,1);
  }
  else if (!state1)
  {
  	lcd.setCursor(0,0);
    lcd.print("Button 1 is on");
    lcd.setCursor(0,1);
    lcd.print("Button 2 is off");
  }
  else if (!state2)
  {
    lcd.setCursor(0,0);
    lcd.print("Button 1 is off");
    lcd.setCursor(0,1);
    lcd.print("Button 2 is on");
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Button 1 is off");
    lcd.setCursor(0,1);
    lcd.print("Button 2 is off");
  }
  delay(100);
  
}
 