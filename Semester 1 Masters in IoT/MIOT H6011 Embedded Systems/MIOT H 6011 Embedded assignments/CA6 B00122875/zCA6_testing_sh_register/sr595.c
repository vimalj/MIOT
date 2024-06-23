// SN 74HC595N   shift register function definition file (storage- 1 byte)

#include <avr/io.h>
#include <util/delay.h>
#include "sr595.h"

void SR595Init()
{
	SR_DATA_DIR |= ((1<<latchPin)|(1<<clockPin)|(1<<dataPin));
}
void SR595Latch()
{
	SR_DATA_PORT |=(1<<latchPin);//HIGH
	SR_DATA_PORT &=~(1<<latchPin);//LOW
}
void SR595Clock()
{
	  SR_DATA_PORT |=(1<<clockPin);//HIGH
	  SR_DATA_PORT &=~(1<<clockPin);//LOW
}

void SR595Send(uint8_t byteToSend)
{
	SR_DATA_PORT &=(~(1<<latchPin));

   for(uint8_t i=0;i<8;i++)
   {
      if (byteToSend & (1<<i))
      {

    	  SR_DATA_PORT|=(1<<dataPin);
      }
      else
      {

    	  SR_DATA_PORT&=~(1<<dataPin);
      }
    SR595Clock();
   }
SR595Latch();
}



