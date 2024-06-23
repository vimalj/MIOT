/*
 * millis.c
 */
# include <avr/io.h>
# include <avr/interrupt.h>
#include "millis.h"
#include <time.h>

static uint32_t elapsedMillis;


// Time CTC interrupt - 1ms
ISR ( TIMER0_COMPA_vect )
{
elapsedMillis++;
}

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
	TCCR0A |= (1 << WGM01);  // Configure timer 0 for CTC mode
	TIMSK0 |= (1 << OCIE0A);  // Enable CTC interrupt
	sei () ; // Enable global interrupts
	OCR0A = 249; // Set CTC compare value to 1Hz at 1 MHz AVR clock , with a prescaler of 64
	TCNT0 = 0;
	elapsedMillis=0;
	TCCR0B |= (1 << CS00) | (1 << CS01) ; // set pre-scaler to 64 and start the timer FCPU
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

	uint32_t localmillis;
	cli();
	localmillis= elapsedMillis;
	sei();
	return localmillis;
}




