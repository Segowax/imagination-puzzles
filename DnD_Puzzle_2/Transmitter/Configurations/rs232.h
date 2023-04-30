/*
 * rs232.h
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#ifndef CONFIGURATIONS_RS232_H_
#define CONFIGURATIONS_RS232_H_

#define UART_BAUD 9600
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)

void USART_Init(uint16_t ubrr);
void USART_Transmit(char data);
void rs232_str(char *str);
void rs232_str_P(const char *str);

#endif /* CONFIGURATIONS_RS232_H_ */
