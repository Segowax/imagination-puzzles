/*
 * main.c
 *
 *  Created on: 6 sty 2022
 *      Author: kosmicznyBandyta
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Headers/keys.h"
#include "Headers/led_display.h"
#include "Headers/outputs.h"

int main(void) {
	init_buttons();
	init_leds();
	init_led_display();

	// enable global interrupts - secret function
	sei();

	uint16_t number = count_to_zero_in(300);

	while (1) {
		if (number != 0 || !IS_KEY1_DOWN)
			number = count_to_zero_continue(number);
		if (IS_KEY1_DOWN && IS_KEY2_DOWN) {
			ON_OUTPUT1_PIN;
			_delay_ms(1000);
			OFF_OUTPUT1_PIN;
			dispose_led_display();
			break;
		}
	}
}
