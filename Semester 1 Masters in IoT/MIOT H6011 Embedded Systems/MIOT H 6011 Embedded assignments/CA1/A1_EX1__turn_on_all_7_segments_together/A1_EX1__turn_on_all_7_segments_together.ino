
//Exercise 1:
//Create a new Arduino project and write an Arduino Wiring program that switches on and off all the segments together once every 500mS.

void setup() {
  // put your setup code here, to run once:

 DDRD = 0xFF; //data direction for port D register read/write
}

void loop() {
  // put your main code here, to run repeatedly:
   
   digitalWrite (PORTD=0xFF, HIGH);   //glow all segments of 7 segment display together
   delay(500);                        //delay for 500 ms
   digitalWrite (PORTD=0x00, LOW);    //turn off all segments 
   delay(500);                        //delay for 500ms again and the loop repeats...... 
}
