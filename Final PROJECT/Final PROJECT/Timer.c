/*
 * Timer.c
 *
 * Created: 1/21/2021 10:44:43 PM
 *  Author: HP
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer.h"
void TIMER_Inti(){
	// prescaling 64
	
	TCCR0 |= ((1<<CS02)|(1<<CS00));
	TIMSK|= (1<<TOIE0);
	//TCNT0 = 111;//255-144 ///for the normal method at start
	
	sei();
}
