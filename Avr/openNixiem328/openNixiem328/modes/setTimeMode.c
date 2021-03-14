/*
 * setTimeMode.c
 *
 * Created: 2020-09-13 19:10:42
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "button.h"
#include "OpenNixieTime.h"
#include "setTimeMode.h"
#include "main.h"

#include <stdbool.h>

extern volatile unsigned int sysTick;
extern volatile unsigned int sysTick50ms;
extern struct button buttonUp;
extern struct button buttonDown;
extern struct button buttonIn;
extern enum Mode mode;

void setTimeModeOnEnter()
{
	
}
void setTimeModeLoop()
{
	static unsigned timeUpdate = 0;
	static int dimInterval = 0;
	static int buttonCheck = 0;
	
	if (sysTick50ms - dimInterval > 5) {
		dimInterval = sysTick50ms;
		displayHALToggleDim(true);
	}

	if (sysTick - timeUpdate > 10) {
		timeUpdate = sysTick;
		displayHALSetCrossfade(openNixieTimeGetHours()/10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
	}
	
	if((buttonIsKeyPressed(&buttonDown) || buttonIsKeyLongPressed(&buttonDown)) && (buttonCheck != sysTick50ms)) {
		mode = SET_TIME_HACK;
		openNixieTimeResetSeconds();
		openNixieDecrementTime();	
		displayHALSetImmediatly(openNixieTimeGetHours()/10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
		buttonCheck = sysTick50ms;
	}
	
	if((buttonIsKeyPressed(&buttonUp) || buttonIsKeyLongPressed(&buttonUp)) && (buttonCheck != sysTick50ms)) {
		mode = SET_TIME_HACK;
		openNixieTimeResetSeconds();
		openNixieIncrementTime();			
		displayHALSetImmediatly(openNixieTimeGetHours()/10, openNixieTimeGetHours()%10 ,openNixieTimeGetMinutes()/10, openNixieTimeGetMinutes()%10);
		buttonCheck = sysTick50ms;
	}
	
	if (buttonIsKeyPressed(&buttonIn)) {
		if (mode == SET_TIME_HACK) {
			openNixieTimeStoreHAL();
		}
		mode = SET_DIM;
	}
}
void setTimeModeOnExit()
{
	
}