/*
* displayTimeMode.c
*
* Created: 2020-09-11 23:54:39
*  Author: Trojan
*/

#include "displayHAL.h"
#include "button.h"
#include "ledHAL.h"
#include "OpenNixieTime.h"
#include "displayTimeMode.h"
#include "main.h"
#include <avr/wdt.h>
#include <avr/eeprom.h>

extern volatile unsigned sysTick;
extern struct button buttonUp;
extern struct button buttonDown;
extern struct button buttonIn;
extern enum Mode mode;
extern unsigned sysTickLimit;

EEMEM unsigned char dimStartHour;
EEMEM unsigned char dimEndHour;
EEMEM unsigned char ledStartHour;
EEMEM unsigned char ledEndHour;
EEMEM unsigned char crossfade;

unsigned char dimStartHour_ram;
unsigned char dimEndHour_ram;
unsigned char ledStartHour_ram;
unsigned char ledEndHour_ram;
unsigned char crossfade_ram;

static void displayTimeModeCorrectTickLimit();

void displayTimeModeOnEnter()
{
	openNixieTimeGetHAL();
	displayHALSetCrossfade(openNixieTimeGetHours()/10 ? openNixieTimeGetHours()/10 : 10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
	dimStartHour_ram = eeprom_read_byte(&dimStartHour);
	dimEndHour_ram = eeprom_read_byte(&dimEndHour);
	ledStartHour_ram = eeprom_read_byte(&ledStartHour);
	ledEndHour_ram = eeprom_read_byte(&ledEndHour);
	crossfade_ram = eeprom_read_byte(&crossfade);
	wdt_enable(WDTO_8S);
	wdt_reset();
}

void displayTimeModeHandleLed()
{
	if (ledEndHour_ram - ledStartHour_ram >= 0) {
		if (openNixieTimeGetHours() >= ledStartHour_ram && openNixieTimeGetHours() < ledEndHour_ram) {
			    ledHALon();
			} else {
			    ledHALoff();
		}
		} else {
		if (openNixieTimeGetHours() >= ledEndHour_ram && openNixieTimeGetHours() < ledStartHour_ram) {
			    ledHALoff();
			} else {
			    ledHALon();
		}
	}
}

void displayTimeModeHandleDim()
{
	if (dimEndHour_ram - dimStartHour_ram >= 0) {
		if (openNixieTimeGetHours() >= dimStartHour_ram && openNixieTimeGetHours() < dimEndHour_ram) {
			displayHALSetDim(true);
			} else {
			displayHALSetDim(false);
		}
		} else {
		if(openNixieTimeGetHours() >= dimEndHour_ram && openNixieTimeGetHours() < dimStartHour_ram) {
			displayHALSetDim(false);
			} else {
			displayHALSetDim(true);
		}
	}
}

void displayTimeModeLoop()
{
	static unsigned timeUpdate = 0;
	
	if (sysTick - timeUpdate > 5) {
		wdt_reset();
		timeUpdate = sysTick;
		if (crossfade_ram)
		    displayHALSetCrossfade(openNixieTimeGetHours()/10 ? openNixieTimeGetHours()/10 : 10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
		else
		    displayHALSetImmediatly(openNixieTimeGetHours()/10 ? openNixieTimeGetHours()/10 : 10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
		displayTimeModeCorrectTickLimit();
		
		displayTimeModeHandleDim();
		displayTimeModeHandleLed();
	}
	
	if(buttonIsKeyPressed(&buttonUp) || buttonIsKeyLongPressed(&buttonUp)) {
		timeUpdate = sysTick - 5;
		displayHALSetImmediatly(
		sysTickLimit/10000,
		(sysTickLimit - (sysTickLimit/10000) * 10000) / 1000,
		(sysTickLimit - (sysTickLimit/1000) * 1000) / 100,
		(sysTickLimit - (sysTickLimit/100) * 100) / 10
		);
	}
	
	if(buttonIsKeyLongPressed(&buttonDown)) {
		timeUpdate = sysTick;
		displayHALSetImmediatly(openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10 ,openNixieTimeGetSeconds()/10, openNixieTimeGetSeconds()%10);
		timeUpdate = sysTick - 9;
	}

	if (buttonIsKeyPressed(&buttonIn)) {
		mode = SET_TIME;
	}
}

void displayTimeModeOnExit()
{
	wdt_disable();
	buttonIsKeyPressed(&buttonDown);  //consume pending event
}

static void displayTimeModeCorrectTickLimit()
{
	static unsigned char lastCorrectionHour_20 = 90;
	static unsigned char lastCorrectionHour_50 = 90;
	unsigned char lastHour = openNixieTimeGetHours();
	unsigned char lastMinute = openNixieTimeGetMinutes();
	unsigned char lastSecond = openNixieTimeGetSeconds();
	
	if (((lastCorrectionHour_20 != lastHour) && (lastMinute == 20)) || ((lastCorrectionHour_50 != lastHour) && (lastMinute == 50))) {
		if (lastMinute == 20)
		lastCorrectionHour_20 = lastHour;
		if (lastMinute == 50)
		lastCorrectionHour_50 = lastHour;
		openNixieTimeGetHAL();
		unsigned char currentHour = openNixieTimeGetHours();
		unsigned char currentMinute = openNixieTimeGetMinutes();
		unsigned char currentSecond = openNixieTimeGetSeconds();
		
		if (currentHour != lastHour) {
			sysTickLimit = 31250;  // reset...
			return;    // ...too big difference, something is wrong
		}
		
		int diff = ((signed char)currentSecond - (signed char)lastSecond) + 60 * ((signed char)currentMinute - (signed char)lastMinute);
		sysTickLimit -= 18 * diff;
		
		if (sysTickLimit > 40000 || sysTickLimit < 20000) {
			sysTickLimit = 31250;  // reset, something is wrong.
		}
	}
}