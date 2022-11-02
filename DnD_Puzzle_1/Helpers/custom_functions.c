/*
 * custom_functions.c
 *
 *  Created on: 1 lis 2022
 *      Author: KosmicznyBandyta
 */

#include <util/delay.h>

#include "../Headers/custom_functions.h"

void my_delay_ms(uint16_t miliseconds) {
	while(miliseconds > 0)
	{
		_delay_ms(1);
		miliseconds--;
	}
}
