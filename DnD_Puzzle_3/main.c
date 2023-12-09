/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd_hd44780/lcd.h"

//private zone
void display_text(char text[], uint16_t ms);

int main() {

	init_lcd();

	_delay_ms(1000);

	while (1) {
		display_text("Test", 1000);
		display_text("Test1", 1000);
		display_text("Test2", 1000);
		display_text("Test3", 1000);
	}
}

void display_text(char text[], uint16_t ms) {
	lcd_cls();
	lcd_str(text);
	while (ms) {
		_delay_ms(1);
		ms--;
	}
}
