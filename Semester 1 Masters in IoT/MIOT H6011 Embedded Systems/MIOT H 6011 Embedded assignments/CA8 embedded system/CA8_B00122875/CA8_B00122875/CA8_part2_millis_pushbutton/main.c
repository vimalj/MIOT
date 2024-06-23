/*
 * main.c
 *
 *  Created on: 19 Nov 2018
 *      Author: VimalJ
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <time.h>
#include "millis.h"

void vmillis(uint32_t interval);
void vmillis(uint32_t interval)
{
millisInit();
uint32_t previousMillis=0;

{
		uint32_t currentMillis = millis();
		if ((currentMillis - previousMillis) >= interval)
		{previousMillis = currentMillis;}
}
}

int main(void)
{
	cli();


	DDRB |= (1<<5);			//LED PIN direction

	DDRD &= ~(1<<2);		//pull up resistor INT0  PD2pin
	PORTD |= (1<<2);

	EICRA |= (1<<ISC01);	//configure falling edge
	EIMSK |= (1<<INT0);		//enable int0

	sei();		//global enable interrupt- put 1 in I bit SREG tells CPU to allow interrupts
					//without this cpu cannot recognize interrupt/ISR.

	while(1)
	{
		sleep_mode();	//CPU stops executing code
		//if here- interrupt occurred
	}
}

ISR(INT0_vect)
{
	vmillis(20);		//not good for ISRs avoid delays

	if (EIFR & (1<<INTF0))
	{
	//clear bounce manually flag
	EIFR |= (1<<INTF0);				//write 1 to flag
	}

	if( !(PIND & (1<<2))) 			// pd2 is low
	{
		PORTB ^= (1<<5);			//toggle led of Arduino
	}
}





