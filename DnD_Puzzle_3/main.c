/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "lcd_hd44780/lcd.h"

const uint8_t tab1[] = { 0, 0, 14, 1, 15, 17, 15, 2 };
const uint8_t tab2[] PROGMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };
uint8_t tab3[] EEMEM = { 0, 0, 14, 1, 15, 17, 15, 2 };

//private zone
void display_text(char text[], uint16_t ms);

int main() {
	_delay_ms(500);

	lcd_init();

	_delay_ms(2000);

	lcd_defchar(0x80, tab1);
	lcd_defchar_P(0x81, tab2);
	lcd_defchar_E(0x82, tab3);

	while (1) {
		display_text("Test " "\x80", 1000);
		display_text("Test1 " "\x81", 1000);
		display_text("Test2 " "\x82", 1000);
		display_text("Test3 ", 1000);
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
