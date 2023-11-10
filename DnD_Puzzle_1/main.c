/*
 * main.c
 *
 *  Created on: 6 sty 2022
 *      Author: kosmicznyBandyta
 */

#include <avr/interrupt.h>

#include "Headers/outputs.h"
#include "Headers/inputs.h"
#include "Headers/led_display.h"

int main(void) {
	init_outputs();
	init_inputs();
	init_led_display();

	// enable global interrupts - secret function
	sei();

#if IS_DISPLAY_TEST == 1
	while (1)
		display_number(6054);
#else
	uint16_t number = count_to_zero_in(600);

	while (1) {
		if (number != 0 || !IS_PHOTOTRANSISTOR_DOWN)
			number = count_to_zero_continue(number);
		if (IS_PHOTOTRANSISTOR_DOWN && IS_BUTTON_DOWN) {
			PORT(SPEAKER_PORT) &= ~(1 << SPEAKER);
			_delay_ms(1000);
			PORT(SPEAKER_PORT) |= (1 << SPEAKER);
			dispose_led_display();
			break;
		}
	}
#endif
}
