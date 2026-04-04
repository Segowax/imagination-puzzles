/*
 * rs232.h
 *
 *  Created on: 4 kwi 2026
 *      Author: kosmi
 */

#ifndef CONFIGURATIONS_RS232_H_
#define CONFIGURATIONS_RS232_H_

#define UART_BAUD 9600
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)

void USART_Init(uint16_t baud);
uint8_t USART_Receive();

#endif /* CONFIGURATIONS_RS232_H_ */
