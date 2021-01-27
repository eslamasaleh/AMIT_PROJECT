/*
 * SLAVE.c
 *
 * Created: 1/22/2021 2:44:34 PM
 * Author : HP
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "UART.h"

int main(void)
{
	SPI_inti(0);
	
	DDRB |= (1<<6);
	DDRB &= ~(1<<4);
	DDRB &= ~(1<<5);
	DDRB &= ~(1<<7);
	DDRD =0xff;
    /* Replace with your application code */
    while (1) 
    {
		char test = SPI_RECIVE();
		switch(test){
			case 'a':
						PORTD |=(1<<0);
						break;
			case 'b':
						PORTD |=(1<<1);
						break;
			case 'c':
						PORTD &=~(1<<0);
						break;
			case 'd':
						PORTD &=~(1<<1);
						break;
						
			case 'e':
						PORTD |=(1<<2);
						break;
			case 'f': 
						PORTD &=~(1<<2);

						break;
						
			case 'x':
						PORTD =0;
						break;			
		}
			
		
    }
}

