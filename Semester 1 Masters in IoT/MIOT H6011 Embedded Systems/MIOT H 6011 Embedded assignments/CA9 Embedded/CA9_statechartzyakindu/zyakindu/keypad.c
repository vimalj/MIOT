#include <avr/io.h>				//library input output header files
#include "keypad.h"
#include "millis.h"
/*
--------------Set up the keypad pin directions----------
------------- and drive the column pins low-------------
 */

void keypadSetupPins(void)
{
	//Set column pins as output pins
	COL_DIR |= ( (1<<COL_1_PIN) | (1<<COL_2_PIN) | (1<<COL_3_PIN) );

	//Set row pins as inputs
	ROW_DIR &= ~((1<<ROW_1_PIN) |  (1<<ROW_2_PIN) | (1<<ROW_3_PIN) | (1<<ROW_4_PIN));

	//Enable pull ups 1's on row pins
	ROW_PORT |= ((1<<ROW_1_PIN) |  (1<<ROW_2_PIN) | (1<<ROW_3_PIN) | (1<<ROW_4_PIN));

	// Sending out 0's on columns
	COL_PORT |= ( (1<<COL_1_PIN) | (1<<COL_2_PIN) | (1<<COL_3_PIN) );
}

/*
 * Scan the keypad to determine which key is pressed.
 * Returns 0 if no key pressed and returns ASCII code if key pressed.
 * Sets all the columns to low when done.
 */
char keypadGetKeyPressed(void)
{
	char retval=0;   // initializing variable for returning ASCII value/ character.

	//-------- Set 011 on columns ------checking all rows through column 1
	COL_PORT &= ~(1<<COL_1_PIN);
	COL_PORT |= ((1<<COL_2_PIN) | (1<<COL_3_PIN));

	//crucial: delay to allow values to propagate to rows
	vmillis(1);

	//test row 1 on column 1
	if (!(ROW_INPUT & (1<< ROW_1_PIN)))	//if(NOT(PINC & (1<<0)))->anded value with PINC is not 1 then it must be pressed
	{
		//there is 0 on RC11 pin => key 1 is pressed
		retval = '1';
	}

	//test row 2  on column 1
		if (!(ROW_INPUT & (1<< ROW_2_PIN)))
		{
			//there is 0 on RC21 => key 4 is pressed
			retval = '4';
		}
	//test row 3 on column 1
		if (!(ROW_INPUT & (1<< ROW_3_PIN)))
			{
				//there is 0 on RC31 pin => key 7 is pressed
				retval = '7';
			}
	//test row 4 column 1
		if (!(ROW_INPUT & (1<< ROW_4_PIN)))
			{
			//there is 0 on RC41 pin => key * is pressed
			retval = '*';

			}

	//--------- Set 101 on columns ------checking all rows using column 2
		COL_PORT &= ~(1<<COL_2_PIN);		//setting column 2 low
		COL_PORT |= ((1<<COL_1_PIN) | (1<<COL_3_PIN));
		vmillis(1);	//delay to allow values to propagate to rows

	//test row 1 column 2
			if (!(ROW_INPUT & (1<< ROW_1_PIN)))
			{
				//there is 0 on RC12 pin => key 2 is pressed
				retval = '2';
			}

	//test row 2 column 2
			if (!(ROW_INPUT & (1<< ROW_2_PIN)))
			{
				//there is 0 on RC22 pin => key 5 is pressed
				retval = '5';
				}

	//test row 3 column 2
		if (!(ROW_INPUT & (1<< ROW_3_PIN)))
			{
				//there is 0 on RC32 pin => key 8 is pressed
				retval = '8';
			}
	//test row 4 column 2
		if (!(ROW_INPUT & (1<< ROW_4_PIN)))
			{
				//there is 0 on RC42 pin => key 0 is pressed
				retval = '0';
			}


//------------ Set 110 on columns ----------checking all rows using column 3
			COL_PORT &= ~(1<<COL_3_PIN);
			COL_PORT |= ((1<<COL_1_PIN) | (1<<COL_2_PIN));
		//delay to allow values to propagate to rows
			vmillis(1);

		//test row 1 column 3
				if (!(ROW_INPUT & (1<< ROW_1_PIN)))
				{
					//there is 0 on RC13 pin => key 2 is pressed
					retval = '3';
				}

		//test row 2 column 3
				if (!(ROW_INPUT & (1<< ROW_2_PIN)))
				{
					//there is 0 on RC23 pin => key 5 is pressed
					retval = '6';
					}

		//test row 3 column 3
			if (!(ROW_INPUT & (1<< ROW_3_PIN)))
				{
					//there is 0 on RC33 pin => key 8 is pressed
					retval = '9';
				}
		//test row 4 column 3
			if (!(ROW_INPUT & (1<< ROW_4_PIN)))
				{
					//there is 0 on RC43 pin => key 0 is pressed
					retval = '#';
				}

	return retval;
}
