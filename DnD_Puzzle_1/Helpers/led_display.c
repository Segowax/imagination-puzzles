/*
 * led_display.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include "../Headers/inputs.h"
#include "../Headers/led_display.h"

volatile uint8_t digit1;
volatile uint8_t digit2;
volatile uint8_t digit3;
volatile uint8_t digit4;

// private method
void send_number_to_led_display(uint16_t number);

void init_led_display() {
	// set all anodes as outputs
	DDR(ANODE1_PORT) |= (1 << ANODE1);
	DDR(ANODE2_PORT) |= (1 << ANODE2);
	DDR(ANODE3_PORT) |= (1 << ANODE3);
	DDR(ANODE4_PORT) |= (1 << ANODE4);
	// send high state to each anode (turn off)
	PORT(ANODE1_PORT) |= (1 << ANODE1);
	PORT(ANODE2_PORT) |= (1 << ANODE2);
	PORT(ANODE3_PORT) |= (1 << ANODE3);
	PORT(ANODE4_PORT) |= (1 << ANODE4);

	// set all segments as outputs
	DDR(PORT_FOR_ALL_SEGMENTS) = 0b11111111;

	// send hight sate to each segment (turn off)
	PORT(PORT_FOR_ALL_SEGMENTS) = 0b11111111;

	// Set Timer0
	TCCR0 |= (1 << WGM01); 					// CTC mode enable
	OCR0 = 38; 								// compare cell in CTC mode
	TCCR0 |= (1 << CS00) | (1 << CS02); 	// 1024 prescaler
	TIMSK |= (1 << OCIE0); // Timer/Counter0 Output Compare Match Interrupt Enable
	// 			CPU		/ prescaler / OCR0 value
	// result: 8000000 Hz / 1024 / 38 + 1 ~= 200 Hz
}

void dispose_led_display() {
	// set all anodes as inputs
	DDR(ANODE1_PORT) &= ~(1 << ANODE1);
	DDR(ANODE2_PORT) &= ~(1 << ANODE2);
	DDR(ANODE3_PORT) &= ~(1 << ANODE3);
	DDR(ANODE4_PORT) &= ~(1 << ANODE4);
	// send low state to each anode
	PORT(ANODE1_PORT) &= ~(1 << ANODE1);
	PORT(ANODE2_PORT) &= ~(1 << ANODE2);
	PORT(ANODE3_PORT) &= ~(1 << ANODE3);
	PORT(ANODE4_PORT) &= ~(1 << ANODE4);
	// set all segments as inputs
	DDR(PORT_FOR_ALL_SEGMENTS) = 0;
	// send low state to each segment
	PORT(PORT_FOR_ALL_SEGMENTS) = 0;

	//Disable Timer0
	TCCR0 &= ~(1 << WGM01);
	OCR0 = 0;
	TCCR0 &= ~((1 << CS00) | (1 << CS02));
	TIMSK &= ~(1 << OCIE0);
}

/* Function compatible with 4-digits led display.
 * max seconds 999,9 */
uint16_t count_to_zero_in(uint16_t seconds) {
	uint16_t number;
	if (seconds > 999)
		number = 9999;
	else if (seconds < 0)
		number = 0;
	else
		number = seconds * 10;

	return count_to_zero_continue(number);
}

uint16_t count_to_zero_continue(uint16_t number) {
	uint16_t buffer = number;
	while (!IS_PHOTOTRANSISTOR_DOWN) {
		number = buffer;
		send_number_to_led_display(number);

		if (buffer == 0)
			break;

		_delay_ms(100);
		buffer--;
	}

	return digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
}

void display_number(uint16_t number) {
	if (number > 9999)
		number = 9999;
	else if (number < 0)
		number = 0;

	send_number_to_led_display(number);
}

// private zone
void send_number_to_led_display(uint16_t number) {
	digit1 = (number - (number % 1000)) / 1000;
	number %= 1000;
	digit2 = (number - (number % 100)) / 100;
	number %= 100;
	digit3 = (number - (number % 10)) / 10;
	number %= 10;
	digit4 = number;
}
