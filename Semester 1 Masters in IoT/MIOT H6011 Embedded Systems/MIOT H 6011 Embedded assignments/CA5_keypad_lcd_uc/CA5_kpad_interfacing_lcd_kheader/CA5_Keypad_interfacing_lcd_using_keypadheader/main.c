/*
 * main.c
 *
 *
 *
 */

#include <avr/io.h>				//library input output header files
#include <util/delay.h>			//delay header file
#include "keypad.h"				//  user defined keypad header file of declarations.
#include "lcd.h"				//  user defined LCD header file of declarations.

int main (void)
{
char keypressed, oldkeypressed=0;			//initializing variables
lcdInit();									//initializing LCD
keypadSetupPins();							// calling function to setup pins and i/o registers
lcdWriteCommand(DISPLAY_ON|BLINK|UNDERLINE);
lcdWriteCommand(CLEAR_DISPLAY);

while(1)
{
keypressed = keypadGetKeyPressed();		//assigning function to scan key press to variable

if (keypressed != 0 && (keypressed != oldkeypressed))
{
//condition for key-press if it is not 0 anded with oldkeypress give output as per function.

 if (keypressed == '*')
 {
	 lcdWriteCommand(CURSOR_SHIFT_LEFT);
	 lcdWriteChar(' ');
	 lcdWriteCommand(CURSOR_SHIFT_LEFT);
 	 }

else if (keypressed == '#')
	{
	 lcdWriteCommand(CLEAR_DISPLAY);
	}

	 else lcdWriteChar(keypressed);
}

 oldkeypressed=keypressed;
 _delay_ms(20);
}
}








