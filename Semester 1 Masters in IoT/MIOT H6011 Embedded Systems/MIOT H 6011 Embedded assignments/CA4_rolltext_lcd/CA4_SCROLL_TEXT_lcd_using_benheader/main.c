/*
 * main.c
 *
 *  Created on: 17 Sep 2015
 *      Author: benjie
 */

#include <avr/io.h>				//library input output header files
#include <util/delay.h>			//delay header file

#include "lcd.h"				// Personally defined (pre defined) or user defined header file of declarations.
// Never include any other source (lcd.c) file here because it is considered one

void lcdInit(void);
void lcdWriteCommand(uint8_t command);
//void lcdWriteChar(char letter);   not in use

int main (void)
  {
	 lcdInit();
	 lcdWriteCommand(DISPLAY_ON);		// 0x0C		while RS is 0 and then write 0x0C then toggle once E high then low
	 lcdWriteCommand(CLEAR_DISPLAY);	// 0x01 	while RS is 0 and then 0x01 is entered the again E pin high and low

	 lcdWriteString ("*VIMAL*");		// While RS=1 write this string character as per ASCII-HEX values and E=1 and E=0
	 lcdWriteCommand(TWO_LINE_MODE);	//0x38
	 lcdWriteCommand(SET_ADDRESS|0x40);	// moving cursor to writable/usable data address (DDR RAM)
	 lcdWriteString ("*JASWAL*");		//While RS=1 write this string character as per ASCII-HEX values and E=1 and E=0

	 while(1)
	  {
	    for( int m=0; m<8; m++)
	    {
	    lcdWriteCommand(DISPLAY_SHIFT_RIGHT);	//while RS is 0 and then write 0x1C then toggle once E high then low
	    _delay_ms(250);
	    }

	    for (int k=8; k>0; k--)
	    {
	    lcdWriteCommand(DISPLAY_SHIFT_LEFT);	//while RS is 0 and then write 0x18 then toggle once E high then low
	    _delay_ms(250);
  	  	}
	  }
 }









