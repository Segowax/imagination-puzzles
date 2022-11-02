/*
 * leds.h
 *
 *  Created on: 30 paü 2022
 *      Author: KosmicznyBandyta
 */

#ifndef LEDS_H_
#define LEDS_H_

#define LEDS_DDR DDRD
#define LEDS_PORT PORTD
#define LED1_PIN (1 << PD0)
#define LED2_PIN (1 << PD1)
#define LED3_PIN (1 << PD2)
#define LED4_PIN (1 << PD3)
#define LED5_PIN (1 << PD4)
#define LED6_PIN (1 << PD5)
#define LED7_PIN (1 << PD6)
#define LED8_PIN (1 << PD7)
#define TOGGLE_LED1_PIN PORTD ^= LED1_PIN
#define TOGGLE_LED2_PIN PORTD ^= LED2_PIN
#define TOGGLE_LED3_PIN PORTD ^= LED3_PIN
#define TOGGLE_LED4_PIN PORTD ^= LED4_PIN
#define TOGGLE_LED5_PIN PORTD ^= LED5_PIN
#define TOGGLE_LED6_PIN PORTD ^= LED6_PIN
#define TOGGLE_LED7_PIN PORTD ^= LED7_PIN
#define TOGGLE_LED8_PIN PORTD ^= LED8_PIN

void initMyLeds();

#endif /* LEDS_H_ */
