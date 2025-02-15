/*
 * inputs.h
 *
 *  Created on: 12 sie 2024
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"
#include "../common.h"

#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <stdbool.h>

#ifndef INPUTS_INPUTS_H_
#define INPUTS_INPUTS_H_

#define IS_BUTTON_DOWN !(PIN(BUTTON_PORT) & (1 << BUTTON))

void inputs_init();
bool is_button_down();

#endif /* INPUTS_INPUTS_H_ */
