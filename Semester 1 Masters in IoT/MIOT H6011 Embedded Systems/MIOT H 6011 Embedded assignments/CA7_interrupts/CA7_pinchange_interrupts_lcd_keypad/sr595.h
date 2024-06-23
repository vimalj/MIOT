// SN 74HC595N   shift register header file (storage- 1 byte)
#ifndef SR595_H_
#define  SR595_H_

#include <avr/io.h>
#include <util/delay.h>

#define SR_DATA_PORT   PORTD
#define SR_DATA_DIR    DDRD

#define dataPin 	4
#define latchPin 	5
#define clockPin 	6

void SR595Init();
void SR595Latch();
void SR595Clock();
void SR595Send(uint8_t byteToSend);

#endif  /* SR595_H */
