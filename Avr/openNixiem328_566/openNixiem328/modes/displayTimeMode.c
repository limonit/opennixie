/*
* displayTimeMode.c
*
* Created: 2020-09-11 23:54:39
*  Author: Trojan
*/

#include "displayHAL.h"
#include "OpenNixieTime.h"
#include "displayTimeMode.h"
#include "RC6.h"
#include "main.h"
#include <avr/wdt.h>
#include <avr/eeprom.h>

unsigned char dimStartHour_ram;
unsigned char dimEndHour_ram;
unsigned char crossfade_ram;

extern volatile unsigned int sysTick;
extern volatile unsigned int sysTick100ms;
extern enum Mode mode;
extern unsigned sysTickLimit;
extern unsigned char rc6CommandReceived;
extern RC6Decoder rc6decoder;
extern OpenNixieTime openNixieTime;    // singleton time representation

static enum {SUB1, SUB2, SUB3, SUB4} subState = SUB1;
static unsigned timeoutTimer = 0;

EEMEM unsigned char dimStartHour;
EEMEM unsigned char dimEndHour;
EEMEM unsigned char crossfade;

static void displayTimeModeCorrectTickLimit();

void displayTimeModeOnEnter()
{
	openNixieTimeGetHAL();
	displayHALSetCrossfade(openNixieTimeGetHours()/10 ? openNixieTimeGetHours()/10 : 10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
	dimStartHour_ram = eeprom_read_byte(&dimStartHour);
	dimEndHour_ram = eeprom_read_byte(&dimEndHour);
	crossfade_ram = eeprom_read_byte(&crossfade);
	wdt_enable(WDTO_8S);
	wdt_reset();
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
	}
	
	if (sysTick - timeoutTimer > 5) {
		subState = SUB1;
	}
}

void displayTimeModeOnExit()
{
	wdt_disable();
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

void
displayTimeModeOnCommandReceived()
{
		
	if (!RC6DecoderIsRepeated(rc6decoder)) {
		timeoutTimer = sysTick;
		
		if (rc6CommandReceived == 9 && subState != SUB3) {
			subState++;
		}
		
		 else if (subState == SUB3 && rc6CommandReceived == 9) {
			subState = SUB1;
			mode = SET_TIME;
		}
		
		else if (subState == SUB3 && rc6CommandReceived == 8) {
			subState = SUB1;
			mode = SET_DIM;
		}
		
		else if (subState == SUB3 && rc6CommandReceived == 7) {
			subState = SUB1;
			mode = SET_CROSSFADE;
		}
		
		else {
			subState = SUB1;
		}
	}


	RC6DecoderUnlock(rc6decoder);
}