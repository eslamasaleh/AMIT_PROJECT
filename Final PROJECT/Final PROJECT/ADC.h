/*
 * ADC.h
 *
 * Created: 1/15/2021 10:49:02 PM
 *  Author: HP
 */ 

#
#ifndef ADC_H_
#define ADC_H_



void ADC_inti(int channel,int rmode,int prescale);
void ADC_CHANNEL(int channel);
void ADC_R(int rmode);
void ADC_PRESCALE(int prescale);
int ADC_READ();



#endif /* ADC_H_ */