/*
 * CFile1.c
 *
 * Created: 1/21/2021 11:34:50 PM
 *  Author: HP
 */ 
#include <avr/io.h>
#include "SPI.h"
#define SLAVE 0
#define MASTER 1
void SPI_inti(int mode){
	   if(mode==MASTER){
		   SPCR |= (1<<MSTR);
		   DDRB |= (1<<4) | (1<<5) | (1<<7);
	   }
	   SPCR |= (1<<SPE) | (1<<SPR1) | (1<<SPR0);
}
void SPI_SEND(char Data){
	
	SPDR =Data;
	while(!(SPSR &(1<<SPIF)));
	
}
void SPI_SEND_NUMB(int Data_num){
	char str[10];
	itoa(Data_num,str,10);
	SPI_SEND_STR(str);
}
void SPI_SEND_STR(char* String){
	for (int i=0;String[i]!='\0';i++)
	{
		SPI_SEND(String[i]);
	}
}
char SPI_RECIVE(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
int SPI_RECIVE_NUMB(){
	while(!(SPSR & (1<<SPIF)));
		
	return (int)SPDR;
}
