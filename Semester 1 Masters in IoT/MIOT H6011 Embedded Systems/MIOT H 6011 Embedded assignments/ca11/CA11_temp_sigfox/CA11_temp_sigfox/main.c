/*
 * main.c
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "usart.h"
#include "adc.h"
#include <stdio.h>
#include "dbg_putchar.h"
#include "millis.h"

void snocCmd(char cmdStr[]);

int main(void)
{
	cli();

	adcInit(5);
	usartInit();
	dbg_tx_init();


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
	vmillis(20);

	if (EIFR & (1<<INTF0))
	{
	//clear bounce manually flag
	EIFR |= (1<<INTF0);				//write 1 to flag
	}

	if( !(PIND & (1<<2))) 			// pd2 is low
	{
		PORTB |= (1<<5);			// led of Arduino ON
		char myTempStr[20];
		char hexStr[20];
		char commandStr[20];

		uint8_t adc= adcRead();

		double tempC = ((5.0/1024)*adc)/0.01;  			// ((ref_voltage/number of steps) * adc)/ 10mV

			usartSendString("-Current Value of temperature in celcius ");
			sprintf(myTempStr, "%.2lf\n", tempC);
			usartSendString(myTempStr); // Sending temp to cool term


			int i = 0;
				while(myTempStr[i]!='\n')
				{
					sprintf(hexStr + i*2, "%x", myTempStr[i]);
					i++;
				}
				usartSendString("--Temperature from ascii to Hex: ");
				usartSendString(hexStr);
				usartSendChar('\n');

				usartSendString("---Temperature in form of Hex onto sigfox: ");
				sprintf(commandStr, "AT$SF=%s\n", hexStr);
				snocCmd(commandStr); // Sending temp to SNOC
				usartSendString(" \n ");

		PORTB = ~(1<<5);			// led of Arduino OFF after operation
	}
}


void snocCmd(char cmdStr[])
{
	char rxStr[20];
	uint8_t rxIndex = 0;
	uint8_t newLineReceived = 0;

	dbg_putStr(cmdStr);			//Command to SNOC
	usartSendString(cmdStr);	//echo command to PC

	while(!newLineReceived)
	{
		while(!usartCharReceived())
		{
		}

		//Char has been received!
		rxStr[rxIndex] = usartReadChar();

		if(rxStr[rxIndex] == '\n')
		{
			newLineReceived = 1;
			rxStr[rxIndex] = '\0';
		}
		else
		{
			rxIndex++;
		}
	}

	//echo received string to PC
	usartSendString(rxStr);
}


