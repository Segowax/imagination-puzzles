/*
 * main.c
 *
 *  Created on: 6 sty 2022
 *      Author: kosmicznyBandyta
 */

// provided header files
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Headers/keys.h"
// my header files
#include "Headers/leds.h"
#include "Headers/led_display.h"

int main(void) {
	init_leds();
	init_buttons();
	init_led_display();
	// enable global interrupts - secret function
	sei();

	uint16_t number = count_to_zero_in(600);

	while (1) {
		if (number != 0)
			number = count_to_zero_continue(number);
	}
}
