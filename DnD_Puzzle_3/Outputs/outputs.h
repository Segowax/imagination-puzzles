/*
 * outputs.h
 *
 *  Created on: 12 sie 2024
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"
#include "../common.h"

#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#ifndef OUTPUTS_OUTPUTS_H_
#define OUTPUTS_OUTPUTS_H_

void outputs_init();
void pwm_init();

#endif /* OUTPUTS_OUTPUTS_H_ */
