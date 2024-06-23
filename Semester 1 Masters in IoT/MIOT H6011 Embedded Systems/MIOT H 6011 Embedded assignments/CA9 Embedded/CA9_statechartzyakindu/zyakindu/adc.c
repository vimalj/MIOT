
#include "adc.h"

void adcInit(uint8_t input)
{
	DDRC &= ~(1<<input);		//Set Port C for input

	ADMUX = input;				// input to ADC multiplexer

	ADMUX |= (1<<REFS0);		//use AVcc as reference voltage

	ADMUX |= (1<<ADLAR);		//8 bit result

	ADCSRA |= ((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));		//Set up the ADC for a single read, AVcc as ref, 128 prescale

	ADCSRA |= (1<<ADEN);		//switch on ADC
}

uint16_t adcRead(void)
{
	uint16_t adcoutput;

	ADCSRA |= (1<<ADSC);		//start converting

	//wait for ADC to complete and ADSC bit goes low
	while(ADCSRA & (1<<ADSC))
	{

	}

	// extract result when ADC conversion is complete
	adcoutput = ADCH;
	return adcoutput;
}
