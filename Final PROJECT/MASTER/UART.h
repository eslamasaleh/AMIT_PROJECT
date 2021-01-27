/*
 * UART.h
 *
 * Created: 1/15/2021 8:48:13 PM
 *  Author: HP
 */ 

#ifndef UART_H_
#define UART_H_
void UART_inti();
void UART_SEND(char Data);
void UART_SEND_NUMB(int Data_num);
void UART_SEND_STR(char* String);
char UART_RECIVE();
int UART_RECIVE_NUMB();





#endif /* UART_H_ */