
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

uint8_t roll[] = { DEC_0, DEC_1, DEC_2, DEC_3, DEC_4, DEC_5, DEC_6, DEC_7, DEC_8, DEC_9 };

void setup() {
  // put your setup code here, to run once:
DDRD=0xFF;
}

void loop() {
      for (int i=0; i<10; i++)
      {
        PORTD = roll[i];
        delay (1000);
      }
}
