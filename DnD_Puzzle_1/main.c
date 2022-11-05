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
#include "Headers/leds.h"
#include "Headers/led_display.h"

int main(void) {
	init_buttons();
	init_led_display();

	// enable global interrupts - secret function
	sei();

	uint16_t number = count_to_zero_in(300);

	while (1) {
		if (number != 0)
			number = count_to_zero_continue(number);
	}
}
