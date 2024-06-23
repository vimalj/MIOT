
#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void adcInit(uint8_t channel);	//Set up the ADC for a single read, AVcc as ref, 128 prescale

uint16_t adcRead(void);			//Perform a single read from the ADC. Waits for ADC completion.

#endif /* ADC_H_ */
