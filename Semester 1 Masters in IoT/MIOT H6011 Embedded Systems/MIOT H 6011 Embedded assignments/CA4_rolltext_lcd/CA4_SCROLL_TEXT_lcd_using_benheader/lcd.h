/*
 * File:   lcd.h
 * Author: Benjamin Toland
 *
 * Created on 18 October 2012, 13:59
 *
 * Modify the defines below to match your circuit
 */

#ifndef LCD_H_
#define  LCD_H_

#include <avr/io.h>
#include <util/delay.h>

//If nibble mode is enabled it is assumed that D4->D7 on the LCD
//are connected to pins 0->3 of the data port.
#define USE_NIBBLE_MODE    0  //0 for false, 1 for true
#define LINE_MODE          0 //0 for ONE line mode, 1 for TWO line mode


#define LCD_CONTROL_PORT   PORTC
#define LCD_CONTROL_DIR    DDRC
#define RS_PIN             5
#define E_PIN              4

#define LCD_DATA_PORT      PORTD
#define LCD_DATA_DIR       DDRD

#define CLEAR_DISPLAY       0x01
#define DISPLAY_CURSOR_HOME 0x02
#define DISPLAY_ON          0x0C
#define DISPLAY_OFF         0x08
#define UNDERLINE           0x02    //OR this with DISPLAY_ON
#define BLINK               0x01    //OR this with DISPLAY_ON
#define ONE_LINE_MODE       0x34
#define TWO_LINE_MODE       0x38
#define SET_ADDRESS         0x80    //You must OR the appropriate address with this
#define DISPLAY_SHIFT_LEFT  0x18
#define DISPLAY_SHIFT_RIGHT 0x1C
#define CURSOR_SHIFT_LEFT   0x10
#define CURSOR_SHIFT_RIGHT  0x14


void lcdInit(void);

void lcdWriteCommand(uint8_t command);

void lcdWriteChar(char ch);

void lcdWriteString(char string[]);

#endif  /* LCD_H */
