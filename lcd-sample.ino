//If 8x2 display is wired correctly it should print out 'this works!' on 2 lines

//0802-A HD44780 14 pin display schema - to Arduino pins:
// Odd Even ->   Odd                         Even
// 13 | 14  ->  DB6-D11                   | DB7-D12
// 11 | 12  ->  DB4-D9                    | DB5-D10
// 9  | 10  ->  DB2-NotConnected          | DB3-NotConnected
// 7  | 8   ->  DB0-NotConnected          | DB1-NotConnected
// 5  | 6   ->  R/W-GND                   | Enable-D8
// 3  | 4   ->  Vo(Contrast)-via 420R GND | RS-D7
// 1  | 2   ->  Vss-GND                   | Vdd-5V


#include <LiquidCrystal.h>

//LiquidCrystal (RS, E, D4, D5, D6, D7);  // Set these pins up with pins on the next line
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   // put your Arduino pin numbers here

//Addition to display RS, E and D pins connect
//Display pin 5 'RW' to Arduino GND
//Display pin 3 'Vo' connect to ground via resistor of between 0 and 470 Ohms to set the contrast - I used 430 ohms resistor


void setup()
  {
  lcd.begin(8, 2);         // LCD parameters here - 8x2 
  lcd.print("this");
  lcd.setCursor(0,1);
  lcd.print("works!");
  }

void loop()
  {
    // do nothing in 'loop'
  }