/*
 * setCrossfadeMode.c
 *
 * Created: 2020-09-14 22:58:40
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "button.h"
#include "ledHAL.h"
#include "OpenNixieTime.h"
#include "displayTimeMode.h"
#include "main.h"
#include <avr/eeprom.h>

extern volatile unsigned int sysTick;
extern struct button buttonUp;
extern struct button buttonDown;
extern struct button buttonIn;

extern enum Mode mode;

EEMEM extern unsigned char crossfade;
extern unsigned char crossfade_ram;
extern volatile unsigned int sysTick;

void
setCrossfadeModeOnEnter()
{
    crossfade_ram = eeprom_read_byte(&crossfade);
	displayHALSetCrossfade(10, 10, 10, 10);
	displayHALSetDim(false);
}

void
setCrossfadeModeLoop()
{
	static unsigned char numberDisplayed = 0;
	static unsigned timeUpdate = 0;
	
	if (sysTick - timeUpdate > 2) {
		timeUpdate = sysTick;
		numberDisplayed++;
		if (numberDisplayed > 99) {
			numberDisplayed = 0;
		}
		
		if (crossfade_ram) {
			displayHALSetCrossfade(10, 10, numberDisplayed/10, numberDisplayed%10);
			} else {
			displayHALSetImmediatly(10, 10, numberDisplayed/10, numberDisplayed%10);
		}
			
	}
	
	if (buttonIsKeyPressed(&buttonUp) || buttonIsKeyPressed(&buttonDown)) {
		if (crossfade_ram) {
			crossfade_ram = 0;
			} else {
			crossfade_ram = 1;
		}
	}
	
	if (buttonIsKeyPressed(&buttonIn)) {
		mode = DISPLAY_TIME;
	}
}

void
setCrossfadeModeOnExit()
{
	eeprom_write_byte(&crossfade, crossfade_ram);
}