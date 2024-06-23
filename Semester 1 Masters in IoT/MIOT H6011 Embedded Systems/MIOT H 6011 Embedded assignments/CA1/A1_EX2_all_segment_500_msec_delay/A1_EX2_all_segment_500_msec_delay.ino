// Exercise 2:
// Modify Exercise 1 to turn on each segment in turn.  Only one segment at a time should be illuminated.  Each segment should be illuminated for 500mS.


void setup() {
  // put your setup code here, to run once:

 DDRD = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
   int i;
   for (i=0; i<8;i++)
   {
    digitalWrite (i, HIGH);
    delay (500);
    digitalWrite (i, LOW);
    delay (500);
   }
}
