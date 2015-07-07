#include <TrinketKeyboard.h>
// Button Activated Photobooth for  ADAFRUIT TRINKET and TKEY script
// double slash = comments - text is ignored by compiler/arduino
// For use with DSLR Remote Pro, AutoHotKey script, trinket and button
// Connect the two leads from the button to pin #0 and GND
// CHANGE THESE TWO VARIABLES TO SUIT:
// KEYCODE_B
const char activateWakeKey   = KEYCODE_A;  // change to same as in AutoHotKey script - usually KEY_F12
const char activateTakeKey   = KEYCODE_B;  // change to same as in AutoHotKey script - usually KEY_F4


/*      								*\
			DO NOT EDIT BELOW THIS LINE
	-----------------------------------------------------------
\*	                						*/
#define WAKEPIN 0
#define TAKEPIN 2

void setup()
{
  // button pins as inputs
  pinMode(WAKEPIN, INPUT);
  pinMode(TAKEPIN, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(WAKEPIN, HIGH);
  digitalWrite(TAKEPIN, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  TrinketKeyboard.poll();

  if (digitalRead(WAKEPIN) == LOW)
  {
    TrinketKeyboard.pressKey(0, activateWakeKey);
    delay(30);
    // this releases the key (otherwise it is held down!)
    TrinketKeyboard.pressKey(0, 0);
  }

  if (digitalRead(TAKEPIN) == LOW)
  {
    TrinketKeyboard.pressKey(0, activateTakeKey);
    // this releases the key (otherwise it is held down!)
    delay(30);
    TrinketKeyboard.pressKey(0, 0);
  }
}
