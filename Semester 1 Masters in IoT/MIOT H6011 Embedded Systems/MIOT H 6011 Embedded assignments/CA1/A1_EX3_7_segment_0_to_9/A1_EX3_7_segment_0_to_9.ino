
// Exercise 3: Create a new Arduino Project and write a program to output a count on your 7-seg display 
//from zero to nine with a one second delay between each increment.  
//When the count reaches nine it should loop around to zero again and keep going.

void setup() {
  // put your setup code here, to run once:
DDRD=0xFF;
}

void loop() {
                  // loop for displaying 0 to 9....
PORTD = 0x3F;
delay(1000);      // delay(milli seconds) one second delay....    
PORTD = 0x06;
delay(1000);
PORTD = 0x5B;
delay(1000);
PORTD = 0x4F;
delay(1000);
PORTD = 0x66;
delay(1000);
PORTD = 0x6D;
delay(1000);
PORTD = 0x7D;
delay(1000);
PORTD = 0x07;
delay(1000);
PORTD = 0x7F;
delay(1000);
PORTD = 0x6F;
delay(1000);
}
