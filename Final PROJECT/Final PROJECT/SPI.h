/*
 * SPI.h
 *
 * Created: 1/22/2021 2:19:02 PM
 *  Author: HP
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_inti();
void SPI_SEND(char Data);
void SPI_SEND_NUMB(int Data_num);
void SPI_SEND_STR(char* String);
char SPI_RECIVE();
int SPI_RECIVE_NUMB();



#endif /* SPI_H_ */