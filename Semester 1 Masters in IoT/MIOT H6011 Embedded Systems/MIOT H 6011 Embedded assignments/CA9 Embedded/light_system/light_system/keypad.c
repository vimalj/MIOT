/*
 * keypad.c
 *
 *  Created on: 07-Nov-2018
 *      Author: hp
 */

/*
 * key.c
 *
 *  Created on: 02-Nov-2018
 *      Author: hp
 */

#include "keypad.h"
#include <util/delay.h>

/*
 * set up the keypad pin direction
 * and drive the col pin
 */
void keypadSetupPins(void)
{
	//SET column pin as output
	COL_DIR |= ((1<<COL_1_PIN)|(1<<COL_2_PIN)|(1<<COL_3_PIN));

	//Set rows pin as Inputs
	ROW_DIR &= ~((1<<ROW_1_PIN | 1<<ROW_2_PIN | 1<<ROW_3_PIN | 1<<ROW_4_PIN));

	//Enable Pullups resistor on row pin
	ROW_PORT |= ((1<<ROW_1_PIN | 1<<ROW_2_PIN | 1<<ROW_3_PIN | 1<<ROW_4_PIN));

	//Send out three 0's on columns
	COL_PORT |= ((1<<COL_1_PIN)|(1<<COL_2_PIN)|(1<<COL_3_PIN));

}

/*
 * Scan the keypad to determine which key is pressed.
 * Returns 0 if no key pressed and returns ascii code if key pressed.
 * Sets all the cols to low when done.
 */
char keypadGetKeyPressed(void)
/* displays the key's pressed in the lcd*/
{
	char rValue =0;
	//send 011 on the col
	// send 0 on the col 1
	COL_PORT &=~ (1<<COL_1_PIN);
	//Send out 11 on col 2 and 3
	COL_PORT |= ((1<<COL_2_PIN) | (1<<COL_3_PIN)) ;

	//CRUCIAL - delay allow value to propagate
	_delay_ms(1);


	//Test row 1
	if(!(ROW_INPUT & (1<<ROW_1_PIN)))
	{
		//there is a 1 on row pin 1
		rValue = '1';

	}

	//Test row 2
	if(!(ROW_INPUT & (1<<ROW_2_PIN)))
	{
		//there is a 1 on row pin 2
		rValue = '4';
	}

	//Test row 3
	if(!(ROW_INPUT & (1<<ROW_3_PIN)))
	{
		//there is a 7 on row pin 3
		rValue = '7';
	}
	if(!(ROW_INPUT & (1<<ROW_4_PIN)))
		{
			//there is a * on row pin 4
			rValue = '*';
		}

	//send 101 on the co2
	//send 0 on col 2
	COL_PORT &= ~ (1<<COL_2_PIN);
	// Send 11 on the col 1 and 3
	COL_PORT |= ((1<<COL_1_PIN) | (1<<COL_3_PIN));

	_delay_us(1);

	//Test row 1
	if(!(ROW_INPUT & (1<<ROW_1_PIN)))
	{
		//there is a 2 on row pin 1
		rValue = '2';
	}

	//Test row 2
	if(!(ROW_INPUT & (1<<ROW_2_PIN)))
	{
		//there is a 5 on row pin 2
		rValue = '5';
	}

	//Test row 3
	if(!(ROW_INPUT & (1<<ROW_3_PIN)))
	{
		//there is a 8 on row pin 3
		rValue = '8';
	}

	//Test row 4
	if(!(ROW_INPUT & (1<<ROW_4_PIN)))
		{
			//there is a 0 on row pin 4
			rValue = '0';
		}

	//send 110 on the column 3
	//send 0 on col 3
	COL_PORT &= ~ (1<<COL_3_PIN);
	// Send 11 on the col 1 and 2
	COL_PORT |= ((1<<COL_1_PIN) | (1<<COL_2_PIN));

	_delay_us(1);

	//Test row 1
	if(!(ROW_INPUT & (1<<ROW_1_PIN)))
	{
		//there is a 3 on row pin 1
		rValue = '3';

	}

	//Test row 2
	if(!(ROW_INPUT & (1<<ROW_2_PIN)))
	{
		//there is a 6 on row pin 2
		rValue = '6';
	}

	//Test row 3
	if(!(ROW_INPUT & (1<<ROW_3_PIN)))
	{
		//there is a 9 on row pin 3
		rValue = '9';
	}


	//Test row 4
	if(!(ROW_INPUT & (1<<ROW_4_PIN)))
		{
		////there is a # on row 4 pin
		rValue = '#';

		}
	//Send out three 0's on columns
		COL_PORT &= ~((1<<COL_1_PIN)|(1<<COL_2_PIN)|(1<<COL_3_PIN));

	return rValue;
}

//void backspace(void)
//{
			//	lcdWriteCommand(CURSOR_SHIFT_LEFT);
				//lcdWriteChar(' ');
				//lcdWriteCommand(CURSOR_SHIFT_LEFT);
				//_delay_ms(100);

//}





