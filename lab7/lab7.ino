#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte pacManOpen[] = {
  B01110,
  B11011,
  B11100,
  B11000,
  B11000,
  B11100,
  B11111,
  B01110
};

byte pacManClosed[] = {
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110
};

byte pacManOpen2[] = {
  B01110,
  B11011,
  B00111,
  B00011,
  B00011,
  B00111,
  B11111,
  B01110
};

int position = 0;
int direction = 1;
int openMouth = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.createChar(1, pacManClosed);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  if (position == 0)
  {
    direction = 1;
    lcd.createChar(0, pacManOpen);
  }
  else
  {
    direction = -1;
    lcd.createChar(0, pacManOpen2);
  }
  
  while ((position != 0 && direction == -1)||(position != 15 && direction == 1))
  {
    lcd.clear();
    lcd.setCursor(position,0);
    lcd.write(byte(openMouth));
    lcd.setCursor(0,1);
    if (direction == 1)
    {
      lcd.print("Moving right");
    }
    else
    {
      lcd.print("Moving left");
    }
    position += direction;
    if (openMouth == 0)
    {
      openMouth = 1;
    }
    else
    {
      openMouth = 0;

    }
    delay(500);
    
  }
    
}