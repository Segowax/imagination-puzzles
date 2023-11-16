/*
 * lcd.h
 *
 *  Created on: Nov 5, 2023
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"

#include <avr/io.h>
#include <util/delay.h>

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

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define SET_RS PORT(LCD_RSPORT) |= (1 << LCD_RS)
#define SET_RW PORT(LCD_RWPORT) |= (1 << LCD_RW)
#define SET_E PORT(LCD_EPORT) |= (1 << LCD_E)
#define CLR_RS PORT(LCD_RSPORT) &= ~(1 << LCD_RS)
#define CLR_RW PORT(LCD_RWPORT) &= ~(1 << LCD_RW)
#define CLR_E PORT(LCD_EPORT) &= ~(1 << LCD_E)

void init_lcd();
void data_dir_out();
void data_dir_in();
void lcd_write_byte(unsigned char _data);
void lcd_write_cmd(uint8_t cmd);
void lcd_write_data(uint8_t data);
uint8_t lcd_read_byte(void);
uint8_t check_BF(void);

#endif /* LCD_LCD_H_ */
