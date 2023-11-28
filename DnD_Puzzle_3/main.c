/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd_hd44780/lcd.h"

int main() {

	init_lcd();
	lcd_str("Test");

	_delay_ms(1000);

	while (1) {
	}
}
