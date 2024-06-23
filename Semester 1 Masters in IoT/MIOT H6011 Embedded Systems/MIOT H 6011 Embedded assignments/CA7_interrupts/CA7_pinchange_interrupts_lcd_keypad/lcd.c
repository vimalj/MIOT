// Function definitions of All declared functions in header file.
//Modified according to sr595.c
#include <avr/io.h>
#include <util/delay.h>
#include "sr595.h"
#include "lcd.h"

void lcdInit(void)		// Setting input and output ports only
{
	//LCD_DATA_DIR = 0xFF; // Setting Port D as output
	SR595Init();
	LCD_CONTROL_DIR |= (1<<E_PIN); // E pin high (1<<4 or 0b0001 0000) (A4 on arduino uc chip)
	LCD_CONTROL_DIR |= (1<<RS_PIN); //RS pin high (1<<5 or 0b0010 0000)	(A5 on arduino uc chip)
  _delay_ms(20);      //boot delay
}

void lcdWriteCommand(uint8_t command)		// Turning on LCD with cursor (0x0F) or without cursor (0x0C)

  {
    LCD_CONTROL_PORT &= ~(1<<RS_PIN);   //RS is 0b0000 0000 (low)
      _delay_us(1);

      //LCD_DATA_PORT = command;   // (0x0F) user will give (hex code) command for output through port D on lcd

      SR595Send(command);
      _delay_us(1);

      LCD_CONTROL_PORT |= (1<<E_PIN);	// 	E is 0b0001 0000 setting high E pin(A4) if it is low otherwise ok
      _delay_us(1);
      LCD_CONTROL_PORT &= ~(1<<E_PIN); // E is 0b0000 0000 setting low
      _delay_ms(2);			// if hex code is 0x0F this will turn on lcd with blinking cursor.
  }

	void lcdWriteChar(char letter)		// This function will display character
  {
      LCD_CONTROL_PORT |= (1<<RS_PIN);   //RS is 0b0010 0000  (high)
      _delay_us(1);

      SR595Send(letter);
     // LCD_DATA_PORT = letter   //command for entering suitable ASCII equivalent hex code or alphabet directly (eg; ASCII A,B,C is 0x41, 0x42, 0x43 in hex)
      _delay_us(1);

      LCD_CONTROL_PORT |= (1<<E_PIN);    //E high
      _delay_us(1);
      LCD_CONTROL_PORT &= ~(1<<E_PIN);		// E low
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
