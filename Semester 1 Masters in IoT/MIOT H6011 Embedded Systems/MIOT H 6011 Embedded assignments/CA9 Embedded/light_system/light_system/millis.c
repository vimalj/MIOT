/*
 * millis.c
 *
 *  Created on: 07-Dec-2018
 *      Author: hp
 */


#include "millis.h"

// In this case the static keyword means that while the elapsedMillis variable
// is a global variable it is only visible in this file (millis.c) i.e.
// It is accessable by all funcions in this file only.
static uint32_t elapsedMillis;


/*
 * This function should set up timer 0 to expire at some sub-muliple of 1mS.
 * Use mode 2 - CTC
 * Enable the comparison interrupt (OCIE0A)
 * Load the OCR0A with the correct value
 * Initialise elapsedMillis to zero.
 * Set correct prescale and start timer.
 */
void millisInit(void)
{
	TCCR0A = (1<<WGM01);  // compare to capture mode
	TIMSK0 = (1<<OCIE0A); // set interrupts
	sei();   // enable global interrupt
	TCNT0 = 0;
	OCR0A = 249;  //divide system clockto find out exact count required
	elapsedMillis = 0;
	TCCR0B = ((1<<CS01)|(1<<CS00)); //set prescaler to 64

}

/*
 * Don't forget to write the ISR!
 */

ISR (TIMER0_COMPA_vect)
{

	elapsedMillis++;
}


/* This function should return the number of milliseconds passed since
 * the millisInit() function was called.
 * The count of elapsedMillis is incremented by an ISR.
 */

uint32_t millis(void)
{
  /* Question: What happens if the ISR runs in the middle of accessing your
   * uint32_t elapsedMillis count variable?
   * Do you need to do anything to ensure this function works correctly in
   * that case?
   */
	uint32_t millis_time;

	cli();

	millis_time = elapsedMillis;

	sei();

	return millis_time;
}
