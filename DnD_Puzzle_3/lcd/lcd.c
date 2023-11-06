/*
 * lcd.c
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/io.h>
#include "lcd.h"

void init_lcd() {
	data_dir_out();
	DDR(LCD_RSPORT) |= (1 << LCD_RS);
	DDR(LCD_EPORT) |= (1 << LCD_E);

#if USE_RW == 1
	DDR(LCD_RWPORT) |= (1 << LCD_RW);
#endif
}

void data_dir_out() {
	DDR(LCD_D7PORT) |= (1 << LCD_D7);
	DDR(LCD_D6PORT) |= (1 << LCD_D6);
	DDR(LCD_D5PORT) |= (1 << LCD_D5);
	DDR(LCD_D4PORT) |= (1 << LCD_D4);
}
