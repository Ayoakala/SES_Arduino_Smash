/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/

#include <ProTrinketKeyboard.h>  // Ensure the library is installed

// Switches are connected from ground to these defined pins
const int PIN_BUTTON_CAPITAL_A = 12;
const int PIN_BUTTON_C    = 11;
const int PIN_BUTTON_B    = 10;
const int PIN_BUTTON_A    = 9;

void setup()
{
  // Declare button pins as inputs
  pinMode(PIN_BUTTON_CAPITAL_A, INPUT);
  pinMode(PIN_BUTTON_C,    INPUT);
  pinMode(PIN_BUTTON_B,    INPUT);
  pinMode(PIN_BUTTON_A,    INPUT);


  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_CAPITAL_A, HIGH);
  digitalWrite(PIN_BUTTON_C,    HIGH);
  digitalWrite(PIN_BUTTON_B,    HIGH);
  digitalWrite(PIN_BUTTON_A,    HIGH);

  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  if (digitalRead(PIN_BUTTON_CAPITAL_A) == LOW)
  {
    TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
    // this should type a capital A
    TrinketKeyboard.pressKey(0, 0);
    // this releases the key
  }

//  switch(LOW){
//    case digitalRead(PIN_BUTTON_C): TrinketKeyboard.print("o");
//    break;
//
//    case digitalRead(PIN_BUTTON_B): TrinketKeyboard.print("i");
//    break;
//    
//    case digitalRead(PIN_BUTTON_A): TrinketKeyboard.print("u");
//    break;
//  }
  
  if (digitalRead(PIN_BUTTON_C) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print("o");
  }
  if (digitalRead(PIN_BUTTON_B) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print("i");
  }
  if (digitalRead(PIN_BUTTON_A) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print("u");
  }
}
