/*
 * lcd.h
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"
#include "../common.h"

#include <avr/io.h>

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#if ((LCD_Y == 4) && (LCD_X == 20))
#define LCD_LINE1 0x00
#define LCD_LINE2 0x28
#define LCD_LINE3 0x14
#define LCD_LINE4 0x54
#else
#define LCD_LINE1 0x00
#define LCD_LINE2 0x40
#define LCD_LINE3 0x10
#define LCD_LINE4 0x50
#endif

#define SET_RS PORT(LCD_RSPORT) |= (1 << LCD_RS)
#define SET_RW PORT(LCD_RWPORT) |= (1 << LCD_RW)
#define SET_E PORT(LCD_EPORT) |= (1 << LCD_E)
#define SET_LED PORT(LCD_LEDPORT) |= (1 << LCD_LED)
#define CLR_RS PORT(LCD_RSPORT) &= ~(1 << LCD_RS)
#define CLR_RW PORT(LCD_RWPORT) &= ~(1 << LCD_RW)
#define CLR_E PORT(LCD_EPORT) &= ~(1 << LCD_E)
#define CLR_LED PORT(LCD_LEDPORT) &= ~(1 << LCD_LED)

/* LCD HD44780 commends */
// Clear Display
#define LCDC_CLEAR 0x01

// Cursor home
#define LCDC_HOME 0x02

// Entry mode set
#define LCDC_ENTRY 0x04
	#define LCDC_ENTRYR 0x02
	#define LCDC_ENTRYL	0
	#define LCDC_MOVE 0x01

// Display On/Off
#define LCDC_ONOFF 0x08
	#define LCDC_DISPLAY_ON 0x04
	#define LCDC_DISPLAY_OFF 0
	#define LCDC_CURSOR_ON 0x02
	#define LCDC_CURSOR_OFF 0
	#define LCDC_CURSOR_BLINKING_MODE 0x01

// Function set
#define LCDC_FUNC 0x20
	#define LCDC_FUNC_8B 0x10
	#define LCDC_FUNC_4B 0
	#define LCD_FUNC_2L 0x08
	#define LCD_FUNC_1L 0
	#define LCD_FUNC_5x10 0x04
	#define LCD_FUNC_5x7 0

// public functions
void lcd_cls(void);
void lcd_cursor_on(void);
void lcd_cursor_off(void);
void lcd_cursor_blink_on(void);
void lcd_cursor_blink_off(void);
void lcd_defchar(uint8_t nr, const uint8_t *def_znak);
void lcd_defchar_E(uint8_t nr, const uint8_t *def_znak);
void lcd_defchar_P(uint8_t nr, const uint8_t *def_znak);
void lcd_home(void);
void lcd_init(void);
void lcd_int(int val);
void lcd_int_with_label(char* text, int val);
void lcd_str(char *str);
void lcd_str_E(char *str);
void lcd_str_P(char *str);

uint8_t lcd_read_byte(void);
uint8_t check_BF(void);

#endif /* LCD_LCD_H_ */
