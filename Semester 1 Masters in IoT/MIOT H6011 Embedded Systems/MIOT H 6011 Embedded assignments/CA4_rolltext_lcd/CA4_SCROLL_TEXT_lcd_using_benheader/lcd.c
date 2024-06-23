
// Function definitions of All declared functions in header file function definitions

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void lcdInit(void)		// Setting input and output ports only
{
  DDRD = 0xFF; // Setting Port D as output

  DDRC |= (1<<E_PIN); // E pin  (1<<4 or 0b0001 0000) (A4 on arduino uc chip) data direction using port C. 0 0r 1
  DDRC |= (1<<RS_PIN); //RS pin	(1<<5 or 0b0010 0000)	(A5 on arduino uc chip)
  _delay_ms(20);      //boot delay
}

void lcdWriteCommand(uint8_t command)		// Turning on LCD with cursor (0x0F) or without cursor (0x0C)

  {
    PORTC &= ~(1<<RS_PIN);   //RS is 0b0000 0000 (set pin A5 0 or low)
      _delay_us(1);

      PORTD = command;   // (0x0F) user will give (hex code) command for output through port D on lcd
      _delay_us(1);

      PORTC |= (1<<E_PIN);	// 	E is 0b0001 0000 setting high E pin(A4) if it is low otherwise ok
      _delay_us(1);
      PORTC &= ~(1<<E_PIN); // E is 0b0000 0000 setting low
      _delay_ms(2);			// if hex code is 0x0F this will turn on lcd with blinking cursor.
  }

	void lcdWriteChar(char letter)		// This function will display character
  {
      PORTC |= (1<<RS_PIN);   //RS is 0b0010 0000  high
      _delay_us(1);

      PORTD = letter;   //command for entering suitable ASCII equivalent hex code or alphabet directly (eg; ASCII A,B,C is 0x41, 0x42, 0x43 in hex)
      _delay_us(1);

      PORTC |= (1<<E_PIN);    //E high
      _delay_us(1);
      PORTC &= ~(1<<E_PIN);		// E low
      _delay_ms(2);
  }										// This will display character

void lcdWriteString (char str[]) 	// similarly this function can display character string by creating an array

{
	uint8_t i=0;

	while (str[i] !='\0') {
		lcdWriteChar (str[i]);// print string
		i++;
	}
}
