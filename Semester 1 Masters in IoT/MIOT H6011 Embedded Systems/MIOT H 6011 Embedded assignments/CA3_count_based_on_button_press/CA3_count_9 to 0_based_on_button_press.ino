//Build an AVR based system that will count button presses and display the count on a seven segment display.
#include <avr/io.h>
#include <util/delay.h>

#define DEC_0 0x3F
#define DEC_1 0x06
#define DEC_2 0x5B
#define DEC_3 0x4F
#define DEC_4 0x66
#define DEC_5 0x6D
#define DEC_6 0x7D
#define DEC_7 0x07
#define DEC_8 0x7F
#define DEC_9 0x6F
#define number 9
int roll[9] = { DEC_9, DEC_8, DEC_7, DEC_6, DEC_5, DEC_4, DEC_3, DEC_2, DEC_1} ;

int main(void)
{

  uint8_t CV , OV=1,count=0;
  DDRD  = 0xFF;      // port D as ouput.
  DDRB  &=~(1<<4);    // port B bit 4 (pin 12 on arduino) as button
  PORTB |= (1<<4);    // pull up

  PORTD =DEC_0;

  while(1)
  {

    CV =PINB &(1<<4);   // assigning bit 4 value anded with input port b

    if(CV==0 && OV != 0 )   // button is pressed
     {

      if(count<number)
      {
       PORTD =roll[count];
       count++;
      }
      else             // button not pressed
      {count =0;
       PORTD =DEC_0;}
     }
    OV = CV; //
    _delay_ms(10);  //
}}
