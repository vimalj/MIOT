// CA2: Build a system on your breadboard that will convert the 4-bit binary read in on a bank of switches to the appropriate hex digit displayed on a seven segment display.

#define HEX_0 0x3F
#define HEX_1 0x06
#define HEX_2 0x5B
#define HEX_3 0x4F
#define HEX_4 0x66
#define HEX_5 0x6D
#define HEX_6 0x7D
#define HEX_7 0x07
#define HEX_8 0x7F
#define HEX_9 0x6F
#define HEX_10 0x77
#define HEX_11 0x7C
#define HEX_12 0x39
#define HEX_13 0x5E
#define HEX_14 0x79
#define HEX_15 0x71

void setup() {
DDRB = 0x00;          
PORTB = 0b11111111;   // PORTB maps to Arduino digital pins 8 to 13 (The two high bits (6 & 7) map to the crystal pins and are not usable)
DDRD=0xFF;            //sets Arduino pins 0 to 7 as outputs using port D
}

void loop() {
      uint8_t x= PINB;   //PINB - The Port B Input Pins Register - read only
      x &= 0b00001111;  // taking copy of PINB (input register) and masking upper 4 bits to 0
      
     if (x==0x0F) {PORTD = HEX_0;} 
else if (x==0x0E) {PORTD = HEX_1;}
else if (x==0x0D) {PORTD = HEX_2;}
else if (x==0x0C) {PORTD = HEX_3;}
else if (x==0x0B) {PORTD = HEX_4;}
else if (x==0x0A) {PORTD = HEX_5;}
else if (x==0x09) {PORTD = HEX_6;}
else if (x==0x08) {PORTD = HEX_7;}
else if (x==0x07) {PORTD = HEX_8;}
else if (x==0x06) {PORTD = HEX_9;}
else if (x==0x05) {PORTD = HEX_10;}
else if (x==0x04) {PORTD = HEX_11;}
else if (x==0x03) {PORTD = HEX_12;}
else if (x==0x02) {PORTD = HEX_13;}
else if (x==0x01) {PORTD = HEX_14;}
else if (x==0x00) {PORTD = HEX_15;}
}
