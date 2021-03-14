/*
 * setDimMode.c
 *
 * Created: 2020-09-13 21:03:04
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "button.h"
#include "OpenNixieTime.h"
#include "setTimeMode.h"
#include "displayTimeMode.h"
#include "main.h"
#include <avr/eeprom.h>

//extern volatile unsigned int sysTick;
extern volatile unsigned int sysTick50ms;
extern struct button buttonUp;
extern struct button buttonDown;
extern struct button buttonIn;
extern enum Mode mode;

extern EEMEM unsigned char dimStartHour;
extern EEMEM unsigned char dimEndHour;
extern unsigned char dimStartHour_ram;
extern unsigned char dimEndHour_ram;

void
setDimModeOnEnter()
{
	dimStartHour_ram = eeprom_read_byte(&dimStartHour);
	dimEndHour_ram = eeprom_read_byte(&dimEndHour);
	
	displayHALSetImmediatly(dimStartHour_ram/10, dimStartHour_ram%10 ,dimEndHour_ram/10,dimEndHour_ram%10);
	
}

void
setDimModeLoop()
{
	static int dimInterval = 0;
	static int buttonCheck = 0;
	
	if (sysTick50ms - dimInterval > 5) {
		dimInterval = sysTick50ms;
		displayHALToggleDim(true);
	}
	
	if((buttonIsKeyPressed(&buttonDown) || buttonIsKeyLongPressed(&buttonDown)) && (buttonCheck != sysTick50ms)) {
		dimEndHour_ram++;
		if (dimEndHour_ram > 23) dimEndHour_ram = 0;
		displayHALSetImmediatly(dimStartHour_ram/10, dimStartHour_ram%10 ,dimEndHour_ram/10,dimEndHour_ram%10);
		buttonCheck = sysTick50ms;
	}
	
	if((buttonIsKeyPressed(&buttonUp) || buttonIsKeyLongPressed(&buttonUp)) && (buttonCheck != sysTick50ms)) {
		dimStartHour_ram++;
		if (dimStartHour_ram > 23) dimStartHour_ram = 0;
		displayHALSetImmediatly(dimStartHour_ram/10, dimStartHour_ram%10 ,dimEndHour_ram/10,dimEndHour_ram%10);
		buttonCheck = sysTick50ms;
	}

	if (buttonIsKeyPressed(&buttonIn)) {
		mode = SET_LED;
	}
}

void
setDimModeOnExit()
{
	eeprom_update_byte(&dimStartHour, dimStartHour_ram);
	eeprom_update_byte(&dimEndHour, dimEndHour_ram);
}