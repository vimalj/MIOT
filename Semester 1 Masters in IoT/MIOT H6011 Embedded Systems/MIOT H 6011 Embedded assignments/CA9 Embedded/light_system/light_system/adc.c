/*
 * adc.c
 *
 *  Created on: 07-Dec-2018
 *      Author: hp
 */


#include "adc.h"

void adcInit(uint8_t Input)
{
	//Make an input pin
	DDRC &= ~(1<<Input);

	//Connect Input  to ADC
	ADMUX = Input;

	//use AVcc as ref voltage
	ADMUX |= (1<<REFS0);

	//8 bit result
	ADMUX |= (1<<ADLAR);

	//128 prescale = 125kHz ADC clock
	ADCSRA |= ((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));

	//switch on ADC
	ADCSRA |= (1<<ADEN);
}

uint16_t adcRead(void)
{
	uint16_t adcOut;

	//start conversion
	ADCSRA |= (1<<ADSC);

	//wait for ADC to complete
	//wait until ADSC bit goes low
	while(ADCSRA & (1<<ADSC))
	{

	}

	//ADC is complete - grab result...
	adcOut = ADCH;

	return adcOut;

}
