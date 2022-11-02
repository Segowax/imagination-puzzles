/*
 * buttons.h
 *
 *  Created on: 30 paü 2022
 *      Author: KosmicznyBandyta
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#define BUTTONS_DDR DDRB
#define BUTTONS_PORT PORTB
#define BUTTON1_PIN (1<<PB0)
#define BUTTON2_PIN (1<<PB1)
#define BUTTON3_PIN (1<<PB2)
#define BUTTON4_PIN (1<<PB3)
#define BUTTON5_PIN (1<<PB4)
#define IS_BUTTON1_DOWN !(PINB & BUTTON1_PIN)
#define IS_BUTTON2_DOWN !(PINB & BUTTON2_PIN)
#define IS_BUTTON3_DOWN !(PINB & BUTTON3_PIN)
#define IS_BUTTON4_DOWN !(PINB & BUTTON4_PIN)
#define IS_BUTTON5_DOWN !(PINB & BUTTON5_PIN)

void initMyButtons();
uint8_t isKeyDown(uint8_t key);

#endif /* BUTTONS_H_ */
