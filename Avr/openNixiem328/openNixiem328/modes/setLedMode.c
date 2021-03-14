/*
 * setLedMode.c
 *
 * Created: 2020-09-14 22:19:14
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "button.h"
#include "OpenNixieTime.h"
#include "setLedMode.h"
#include "displayTimeMode.h"
#include "ledHAL.h"
#include "main.h"
#include <avr/eeprom.h>

EEMEM extern unsigned char ledStartHour;
EEMEM extern unsigned char ledEndHour;
extern unsigned char ledStartHour_ram;
extern unsigned char ledEndHour_ram;

extern volatile unsigned int sysTick50ms;
extern struct button buttonUp;
extern struct button buttonDown;
extern struct button buttonIn;
extern enum Mode mode;

void
setLedModeOnEnter()
{
	ledStartHour_ram = eeprom_read_byte(&ledStartHour);
	ledEndHour_ram = eeprom_read_byte(&ledEndHour);
	
	displayHALSetImmediatly(ledStartHour_ram/10, ledStartHour_ram%10 ,ledEndHour_ram/10,ledEndHour_ram%10);
}

void
setLedModeLoop()
{
	static int dimInterval = 0;
	static int buttonCheck = 0;
	
	if (sysTick50ms - dimInterval > 5) {
		dimInterval = sysTick50ms;
		displayHALToggleDim(true);
		ledHALToggle();
	}
	
	if((buttonIsKeyPressed(&buttonDown) || buttonIsKeyLongPressed(&buttonDown)) && (buttonCheck != sysTick50ms)) {
		ledEndHour_ram++;
		if (ledEndHour_ram > 23) ledEndHour_ram = 0;
		displayHALSetImmediatly(ledStartHour_ram/10, ledStartHour_ram%10, ledEndHour_ram/10, ledEndHour_ram%10);
		buttonCheck = sysTick50ms;
	}
	
	if((buttonIsKeyPressed(&buttonUp) || buttonIsKeyLongPressed(&buttonUp)) && (buttonCheck != sysTick50ms)) {
		ledStartHour_ram++;
		if (ledStartHour_ram > 23) ledStartHour_ram = 0;
		displayHALSetImmediatly(ledStartHour_ram/10, ledStartHour_ram%10, ledEndHour_ram/10, ledEndHour_ram%10);
		buttonCheck = sysTick50ms;
	}
	
	if (buttonIsKeyPressed(&buttonIn)) {
		mode = SET_CROSSFADE;
	}
}

void
setLedModeOnExit()
{
	eeprom_update_byte(&ledStartHour, ledStartHour_ram);
	eeprom_update_byte(&ledEndHour, ledEndHour_ram);	
}