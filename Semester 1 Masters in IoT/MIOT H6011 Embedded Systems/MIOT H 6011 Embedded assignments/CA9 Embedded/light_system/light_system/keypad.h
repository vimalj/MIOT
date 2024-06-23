/*
 * key.h
 *
 *  Created on: 01-Nov-2018
 *      Author: nikhil
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#include <util/delay.h>

#define NUM_COLS	3
#define NUM_ROWS	4

#define COL_DIR		DDRB
#define COL_PORT	PORTB
#define COL_1_PIN 	2
#define COL_2_PIN	3
#define COL_3_PIN	4

//NB it is important that the row pins all trigger the same
//Pin change interrupt - see p70 of the datasheet
#define ROW_DIR		DDRC
#define ROW_PORT	PORTC
#define ROW_INPUT   PINC
#define ROW_1_PIN	0
#define ROW_2_PIN 	1
#define ROW_3_PIN	2
#define ROW_4_PIN	3

/*
 * Set up the keypad pin directions
 * and drive the column pins low.
 */
void keypadSetupPins(void);

/*
 * Scan the keypad to determine which key is pressed.
 * Returns 0 if no key pressed and returns ascii code if key pressed.
 * Sets all the cols to low when done.
 */
char keypadGetKeyPressed(void);

void backspace(void);

#endif /* KEYPAD_H_ */
