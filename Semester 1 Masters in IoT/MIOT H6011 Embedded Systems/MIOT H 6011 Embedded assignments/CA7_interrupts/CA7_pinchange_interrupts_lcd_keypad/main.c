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
#include <avr/interrupt.h>
#include <avr/sleep.h>

int main (void)
{
static char keypressed, oldkeypressed=0;			//initializing variables
lcdInit();									//initializing LCD
keypadSetupPins();							// calling function to setup pins and i/o registers
lcdWriteCommand(DISPLAY_ON|BLINK|UNDERLINE);
lcdWriteCommand(CLEAR_DISPLAY);

//Enable PCINT1 interrupt
PCICR |= (1<<PCIE1);

//Enable specific pins to generate	PCINT1
PCMSK1 |= ((1<<PCINT8)	| (1<<PCINT9) | (1<<PCINT10) | (1<<PCINT11));

sei();   //telling CPU to allow interrupt request IRQ

while(1)
{
	sleep_mode(); 		//code stops here CPU freeze
	cli();				//globally disable interrupt - ignore int for now
keypressed = keypadGetKeyPressed();		//twiddling the cols
	sei();		//re-enable interrupts

	PCIFR |= (1<<PCIF1);	// manually clear int flag

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

ISR(PCINT1_vect)
{
//wake up cpu
}




