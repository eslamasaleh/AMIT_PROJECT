/*
 * CFile1.c
 *
 * Created: 1/15/2021 10:09:14 PM
 *  Author: HP
 */ 
#include <avr/io.h>

void ADC_inti(int channel,int rmode,int prescale){
	ADC_CHANNEL(channel);
	ADC_R(rmode);
	ADC_PRESCALE(prescale);
	ADCSRA |= (1<<ADEN);
}
void ADC_CHANNEL(int channel){
	ADMUX =0;
	ADMUX =channel;
	DDRA &=~(1<<channel);
	
}
void ADC_R(int rmode){
	ADMUX=(rmode<<6);
	
}
void ADC_PRESCALE(int data){
	ADCSRA =0;
	ADCSRA=data;
	
	
}
int ADC_READ(){
	ADCSRA |=(1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	int val = ADCL;
	val |= (ADCH<<8);
	int x=val*4.887585532746823;
	return x/10;
}