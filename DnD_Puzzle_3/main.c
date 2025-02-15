/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd_hd44780/lcd.h"
#include "Outputs/outputs.h"
#include "Inputs/inputs.h"

#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>

const uint8_t tab1[] = { 0, 0, 14, 1, 15, 17, 15, 2 };
const uint8_t tab2[] PROGMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };
const uint8_t tab3[] EEMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };

//private zone
void display_text(char text[]);
void display_text_for(char text[], uint16_t ms);

int main() {
	inputs_init();
	outputs_init();
	pwm_init();

	lcd_init();

	_delay_ms(10);

	// display LED test
	SET_LED;
	_delay_ms(100);
	CLR_LED;
	_delay_ms(100);
	SET_LED;

	OCR2 = 0;
	display_text("Pulse width [%]: ");
	while (1) {
		if (is_button_down()) {
			if (OCR2 == 255)
				OCR2 = 0;
			OCR2++;
			while (is_button_down())
				;
		}
	}
}

void display_text(char text[]) {
	lcd_cls();
	lcd_str(text);
}

void display_text_for(char text[], uint16_t ms) {
	lcd_cls();
	lcd_str(text);
	while (ms) {
		_delay_ms(1);
		ms--;
	}
}
