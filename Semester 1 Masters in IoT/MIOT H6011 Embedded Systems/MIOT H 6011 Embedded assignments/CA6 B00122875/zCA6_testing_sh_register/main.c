//testing shift register self library files
#include <avr/io.h>				//library input output header files
#include <util/delay.h>			//delay header file
#include "sr595.h"


int main(void)
{
	uint8_t led[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	while(1)
	{
		SR595Init();
	{
			for(uint8_t m=0;m<8;m++)
			{
			    SR595Send(led[m]);
			    _delay_ms(500);
			   }
	}
	}
}




