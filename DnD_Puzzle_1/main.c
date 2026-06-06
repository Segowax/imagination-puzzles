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
	_delay_ms(1000);
#if IS_DISPLAY_TEST == 10
	while (1)
		display_number(9000);
#else
	uint16_t number = count_to_zero_in(600);

	while (1) {
		if (number != 0 || !IS_PHOTOTRANSISTOR_DOWN)
			number = count_to_zero_continue(number);
		if (IS_PHOTOTRANSISTOR_DOWN && IS_BUTTON_DOWN) {
			SPEAKER_TURN_ON;
			_delay_ms(1000);
			SPEAKER_TURN_OFF;
			dispose_led_display();
			break;
		}
	}
#endif
}
