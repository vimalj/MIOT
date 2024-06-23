/*
 * main.c
 *
 *  Created on: 19 Nov 2018
 *      Author: VimalJ
 */

# include <avr/io.h>
# include <avr/interrupt.h>
#include <time.h>
#include "millis.h"
#include <avr/sleep.h>

uint32_t interval = 250;

int main (void)
{
cli();					//clearing/disabling all interrupts

millisInit();
uint32_t previousMillis=0;
DDRB |= (1 << 5) ; 		// Set LED as output

sei();					//enable global interrupt

while(1)
{
		sleep_mode();
		//CPU stops executing code running in low power mode as normal computer sleeps until any key is pressed

		uint32_t currentMillis = millis();
		if ((currentMillis - previousMillis) >= interval)
		{PORTB ^=(1<<5);
		previousMillis = currentMillis;}
}
}


/*
 * Test your new millis module by using it to control the timing of a blinking LED on your board.
•	Toggle the LED every 250mS.
•	Put the MCU in IDLE mode between LED toggles.



•	Answer these questions in your screencast:
o	What is waking up your CPU?
		Interrupt trigger signal request-rising/falling edge
		(any type of hardware/timer/adc/pushbutton generate interrupt)

o	How often is your CPU waking up?
	-BY IRQ- every time an Interrupt Service Request ISR is received by cpu.
	-otherwise it stays in sleep/idle mode.
	-once per millisecond



o	What would be the effect of changing the millis module such that the millis count was only incremented every 10ms instead of every 1ms? Could you save some power?  What would need to change?
 *
 *arduino updates function millis() with 8 bit timer.
 * it uses overflow with a prescaler value of 64.
 * the ISR is run approximately once per millisecond on a 16MHz system
 *When ISR runs it increment(elapsedmillis++) variable that is used by the millis() function.
 * If lot of other ISRs have a higher interrupt priorities, it is possible that the code for the millis() never runs.
 *
 * we can still save power as cpu willremain in sleep mode till next ISR
 */



