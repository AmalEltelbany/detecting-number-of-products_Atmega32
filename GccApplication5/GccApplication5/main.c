#include <avr/io.h> 
#define F_CPU8000000UL //defining the clock speed of the microprocessor for the delay  

#include <util/delay.h> 
int main(){ 
//Initialization 
unsigned char sgment []={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XDE};
DDRC=0xFF; 
DDRA |= (1<<0) | (1<<1) | (1<<2); // Set the direction of the PORTA0 ,PORTA1 and  PORTA2 to output 
DDRA &= ~(1<<3); // Set the direction of the PORTA3 to input 
DDRD &= (~(1<<2)); /*ddrc0 = 0 input*/
PORTA = 0x01; // Set the PORTA value to one to light the green  light and make sure all other bits are zero 
PORTA |= (1<<3); // Enables the internal pull up for PORTA3 
PORTC=0X7E;

unsigned char counter = 0; 
//loop 
while(1){ 
 /* Since we don't have sensors for counting 
 * the boxes nor a DC motor i will use a 
 * counter that counts to 12 then stops 
 * as if it counts the boxes and waits 
 * for the restart button to be pressed 
 * to count again 
 */ 
 if(((PINA>>3)&1) == 0) 
 { PORTC=0X7E;
 counter = 0; 
 PORTA |= (1<<0); //turn on the green light 
 PORTA &= ~((1<<1) | (1<<2)); //turn off the red light and the buzzer 
 } 
 if(counter == 9) 
 { 
 PORTA &= ~(1<<0); //turn off the green light 
 PORTA |= (1<<1) | (1<<2); //turn on the red light and the buzzer 
 } 
if (!(PIND&(1<<2))) /*cheek pinc0 1 */
{   if(counter>=9){counter=9;}
else{
	counter++;
	PORTC=sgment[counter]; 
	_delay_ms(1000);
}
// while(PINC&(1<<0));  /*poling*/

 
 } 
} 
}