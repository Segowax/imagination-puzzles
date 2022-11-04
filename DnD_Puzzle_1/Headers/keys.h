/*
 * buttons.h
 *
 *  Created on: 30 paü 2022
 *      Author: KosmicznyBandyta
 */

#ifndef KEYS_H_
#define KEYS_H_

#define KEYS_DDR DDRB
#define KEYS_PORT PORTB
#define KEY1_PIN (1<<PB0)
#define KEY2_PIN (1<<PB1)
#define KEY3_PIN (1<<PB2)
#define KEY4_PIN (1<<PB3)
#define KEY5_PIN (1<<PB4)
#define IS_KEY1_DOWN !(PINB & KEY1_PIN)
#define IS_KEY2_DOWN !(PINB & KEY2_PIN)
#define IS_KEY3_DOWN !(PINB & KEY3_PIN)
#define IS_KEY4_DOWN !(PINB & KEY4_PIN)
#define IS_KEY5_DOWN !(PINB & KEY5_PIN)

void init_buttons();
uint8_t is_key_down(uint8_t key);

#endif /* KEYS_H_ */
