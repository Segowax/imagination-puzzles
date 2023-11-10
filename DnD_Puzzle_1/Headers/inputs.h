/*
 * inputs.h
 *
 *  Created on: Nov 10, 2023
 *      Author: KosmicznyBandyta
 */

#include "../configuration.h"
#include "common.h"

#ifndef HEADERS_INPUTS_H_

#define IS_PHOTOTRANSISTOR_DOWN !(PIN(PHOTOTRANSITOR_PORT) & (1 << PHOTOTRANSITOR))
#define IS_BUTTON_DOWN !(PIN(BUTTON_PORT) & (1 << BUTTON))
#define IS_SECRET_DOWN !(PIN(SECRET_PORT) & (1 << SECRET))

void init_inputs();

#endif /* HEADERS_INPUTS_H_ */
