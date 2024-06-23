/*
 * adc.h
 *
 *  Created on: 07-Dec-2018
 *      Author: hp
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

 //Set up the ADC for a single read, AVcc as ref, 128 prescale

void adcInit(uint8_t channel);


//Perform a single read from the ADC. Waits for ADC completion.

uint16_t adcRead(void);







#endif /* ADC_H_ */
