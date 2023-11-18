/*
 * displayHAL.c
 *
 * Created: 2020-06-15 23:51:05
 *  Author: Trojan
 */ 

#include "displayHAL.h"
#include "pico/stdlib.h"
#include <string.h>

unsigned char lookUpTable[11] = {4, 6, 7, 3, 2, 8, 9, 0, 1, 5, 12};
unsigned char displayContent[4] = {10, 10, 10, 10};
unsigned char displayContent2[4] = {10, 10, 10, 10};
bool dim = false;
unsigned char stage = REFRESH_100US_INTERVAL_NUMBER;
	
void
displayHALTurnOff()
{
  gpio_clr_mask ((1<<PIN_TUBE_1) | (1<<PIN_TUBE_2) | (1<<PIN_TUBE_3) | (1<<PIN_TUBE_4));
  gpio_set_mask ((1<<PIN_A) | (1 << PIN_B) | (1 << PIN_C) | (1 <<PIN_D));
}

void inline
displayHALInit()
{
    gpio_init_mask((1<<PIN_A) | (1 << PIN_B) | (1 << PIN_C) | (1 <<PIN_D));
    gpio_init_mask((1<<PIN_TUBE_1) | (1<<PIN_TUBE_2) | (1<<PIN_TUBE_3) | (1<<PIN_TUBE_4));
    gpio_set_dir_out_masked((1<<PIN_A) | (1 << PIN_B) | (1 << PIN_C) | (1 <<PIN_D));
    gpio_set_dir_out_masked((1<<PIN_TUBE_1) | (1<<PIN_TUBE_2) | (1<<PIN_TUBE_3) | (1<<PIN_TUBE_4));
    //gpio_set_dir_out_masked(0b1111111100);

	displayHALTurnOff();
}

void
displayHAL100usStep()
{
	static unsigned char multiplexCounter = 0;
	static unsigned char currentTube = 0;
	static int stageCounter = 0;
	
	if (++multiplexCounter == REFRESH_100US_INTERVAL_NUMBER)
	{
		multiplexCounter = 0;
		displayHALTurnOff();
		
		static unsigned char cntr = 0;
		if (!dim || (++cntr & 1)) {
			if(++currentTube > 3) currentTube=0;

			if (currentTube == 0) {
				gpio_put(PIN_TUBE_1, 1);
			}
			if (currentTube == 1) {
				gpio_put(PIN_TUBE_2, 1);
			}
			if (currentTube == 2) {
				gpio_put(PIN_TUBE_3, 1);
			}
			if (currentTube == 3) {
				gpio_put(PIN_TUBE_4, 1);
			}
		}
	}

	if (++stageCounter > CROSSFADE_100US_INTERVAL_NUMBER)
	{
		if (stage <= REFRESH_100US_INTERVAL_NUMBER) {
			stage++;
		}
		stageCounter=0;
	}
	
	unsigned char outputDigit;
	
	if (multiplexCounter >= stage)
	{
		outputDigit = lookUpTable[displayContent[currentTube]];
	} else {
		outputDigit = lookUpTable[displayContent2[currentTube]];
	}
		
	if (!(outputDigit & 0x1)) {
		gpio_put(PIN_A, 0);
		} else {
		gpio_put(PIN_A, 1);
	}
	if (!(outputDigit & 0x2)) {
		gpio_put(PIN_B, 0);
		} else {
		gpio_put(PIN_B, 1);
	}
	if (!(outputDigit & 0x4)) {
		gpio_put(PIN_C, 0);
		} else {
		gpio_put(PIN_C, 1);
	}
	if (!(outputDigit & 0x8)) {
		gpio_put(PIN_D, 0);
		} else {
		gpio_put(PIN_D, 1);
	}
}

void
displayHALSetDim(bool _dim)
{
	dim = _dim;
}

void
displayHALToggleDim()
{
	if (dim) {
		dim = false;
	} else {
		dim = true;
	}
}

void
displayHALSetCrossfade(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	memcpy(displayContent, displayContent2, sizeof(displayContent));
	displayContent2[0] = a;
	displayContent2[1] = b;
	displayContent2[2] = c;
	displayContent2[3] = d;
	//if (!memcmp(displayContent2, displayContent, sizeof(displayContent))) {
	    stage = 0;
	//}
}

void
displayHALSetImmediatly(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	stage = REFRESH_100US_INTERVAL_NUMBER;
	displayContent2[0] = a;
	displayContent2[1] = b;
	displayContent2[2] = c;
	displayContent2[3] = d;
}
