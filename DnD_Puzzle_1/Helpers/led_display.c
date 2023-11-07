/*
 * led_display.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>

#include "../Headers/led_display.h"
#include "../Headers/keys.h"

volatile uint8_t digit1;
volatile uint8_t digit2;
volatile uint8_t digit3;
volatile uint8_t digit4;

void init_led_display() {
	ANODE_DDR |= ANODE1 | ANODE2 | ANODE3 | ANODE4;
	ANODE_PORT |= ANODE1 | ANODE2 | ANODE3 | ANODE4;
	SEGMENTS_DDR |= SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E
			| SEGMENT_F | SEGMENT_G | SEGMENT_H;
	SEGMENTS_PORT = SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E
			| SEGMENT_F | SEGMENT_G | SEGMENT_H;
	// Set Timer0
	TCCR0 |= (1 << WGM01); 					// CTC mode enable
	OCR0 = 38; 								// compare cell in CTC mode
	TCCR0 |= (1 << CS00) | (1 << CS02); 	// 1024 prescaler
	TIMSK |= (1 << OCIE0); // Timer/Counter0 Output Compare Match Interrupt Enable
	// 			CPU		/ prescaler / OCR0 value
	// result: 8000000 Hz / 1024 / 38 + 1 ~= 200 Hz
}

void dispose_led_display() {
	ANODE_DDR = 0;
	ANODE_PORT = 0;
	SEGMENTS_DDR = 0;
	SEGMENTS_PORT = 0;
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
	while (!IS_KEY1_DOWN) {
		number = buffer;
		digit1 = (number - (number % 1000)) / 1000;
		number %= 1000;
		digit2 = (number - (number % 100)) / 100;
		number %= 100;
		digit3 = (number - (number % 10)) / 10;
		number %= 10;
		digit4 = number;

		if (buffer == 0)
			break;

		_delay_ms(100);
		buffer--;
	}

	return digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
}
