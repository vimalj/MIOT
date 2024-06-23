/*
 * main.c
 *
 *  Created on: 17 Sep 2015
 *      Author: benjie
 */

#include <avr/io.h>
#include <util/delay.h>

#include "avr/sleep.h"
#include "millis.h"
#include "keypad.h"
#include "usart.h"
#include "adc.h"
#include "sc_timer/sc_timer_service.h"
#include "src-gen/State_chart.h"
#define KeypadInterval 20
#define ThresholdValue 120

static State_chart sc;


int main(void)
{
	millisInit();
	adcInit(4);
	usartInit();
	char array[5];
	DDRB|=(1<<5);
	static char keypressed, oldkeypressed=0;			//initializing variables
	uint16_t lumValue = 0;
	keypadSetupPins();


	sc_timer_setup();  //setup the statechart timers

	state_chart_init(&sc); //initialize statechart
	state_chart_enter(&sc); //enter the statechart
    uint32_t KeypadScan =millis()+KeypadInterval;

			while(1)
			{

				sleep_mode();//cpu frozen

				if(millis()>= KeypadScan)
				{
					keypressed=keypadGetKeyPressed();
					KeypadScan =millis()+KeypadInterval;
				}

				if ((keypressed != 0) &&  (keypressed != oldkeypressed))
						{
							if (keypressed == '1')
							{
								state_chartIface_raise_oN(&sc);
							}

							else if (keypressed == '2')
							{
								state_chartIface_raise_oFF(&sc);
							}

							else if (keypressed == '3')
							{
								state_chartIface_raise_mODE(&sc);  // mode state
							}
						}
				oldkeypressed = keypressed;
				lumValue = adcRead();
				if(lumValue < ThresholdValue)
				{
					state_chartIface_raise_dARK(&sc);
					usartSendString(" Current Value of ADC ");
					sprintf(array,"%i",lumValue);
					usartSendString(array);
					usartSendString(" ThresholdValue is ");
					sprintf(array,"%i",ThresholdValue);
					usartSendString(array);
					usartSendChar('\n');
				}
				else
				{
					state_chartIface_raise_bRIGHT(&sc);
					usartSendString(" Current Value of ADC ");
					sprintf(array,"%i",lumValue);
					usartSendString(array);
					usartSendString(" ThresholdValue is ");
					sprintf(array,"%i",ThresholdValue);
					usartSendString(array);
					usartSendChar('\n');

				}


				sc_timer_increment(50);
				state_chart_runCycle(&sc);


}
}
//Functions from State_chartRequired.h
void state_chartIface_setLight(const State_chart* handle, const sc_boolean lightOn)
{
    if(lightOn)
        PORTB |= (1<<5);
    else
    	PORTB &= ~(1<<5);
}


