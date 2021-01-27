/*
 * UART.c
 *
 * Created: 1/15/2021 8:25:02 PM
 *  Author: HP
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "UART.h"
#include <stdlib.h>

void UART_inti(){
	UCSRB |=(1<<TXEN)|(1<<RXEN);
	UBRRL=103; //rate 9600
}
void UART_SEND(char Data){
	while(!(UCSRA &(1<<UDRE)));
	UDR =Data;
	
	
}
void UART_SEND_NUMB(int Data_num){
	char str[10];
	itoa(Data_num,str,10);
	UART_SEND_STR(str);
}
void UART_SEND_STR(char* String){
	for (int i=0;String[i]!='\0';i++)
	{
		UART_SEND(String[i]);
	}
}
char UART_RECIVE(){
	while(!(UCSRA &(1<<RXC))){
		
	}
	return UDR;
}
int UART_RECIVE_NUMB(){
	while(!(UCSRA &(1<<RXC))){
		
	}
	return (int)UDR;
}

