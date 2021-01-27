/*
 * Final PROJECT.c
 *
 * Created: 1/15/2021 8:24:11 PM
 * Author : HP
 */ 

#include <avr/io.h>
#include "UART.h"
#include "ADC.h"
#include "Timer.h"
#include "SPI.h"
#include <avr/interrupt.h>
static int fanflag =0;
int main(void)
{
    /* Replace with your application code */
	DDRB |= (1<<4) | (1<<5) | (1<<7);
	DDRB &= ~(1<<6);
	ADC_inti(0,1,7);
	
	TIMER_Inti();
	SPI_inti(1);
	UART_inti();
	
	
	while(1){
		char a=UART_RECIVE();
		if(a=='x' & fanflag==0){
			SPI_SEND(a);
			fanflag=1;
		}
		else if(a=='s' & fanflag==1){
			SPI_SEND(a);
			fanflag=0;
		}
		else if(fanflag==0){
			SPI_SEND(a);
			
		}
		
	
    
}}
ISR(TIMER0_OVF_vect){
	static int x=0;
	
	x++;
	if(x==152 & fanflag==0){
		int a=ADC_READ();
		
		if(a>=30 ){
			SPI_SEND('e');
			
		}
		else if(a<30){
			SPI_SEND('f');
			
		}
		
		UART_SEND_NUMB(a);
		x=0;
	
	}
	else if(x==152){
		x=0;
	}
	
	
	
}
