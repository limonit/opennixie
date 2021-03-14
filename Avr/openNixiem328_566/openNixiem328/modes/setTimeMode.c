/*
 * setTimeMode.c
 *
 * Created: 2020-09-13 19:10:42
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "OpenNixieTime.h"
#include "setTimeMode.h"
#include "RC6.h"
#include "main.h"
#include <util/delay.h>
#include <stdbool.h>

extern volatile unsigned int sysTick;
extern volatile unsigned int sysTick100ms;
extern enum Mode mode;
extern unsigned char rc6CommandReceived;
extern RC6Decoder rc6decoder;

static enum {HR1, HR2, MIN1, MIN2} subState = HR1;
static unsigned char hr1 = 10, hr2 = 10, min1=10, min2=10;
static bool received = false;
static unsigned timeoutTimer;

void setTimeModeOnEnter()
{
	displayHALSetImmediatly(10, 10, 10, 10);
	timeoutTimer = sysTick;
}

void setTimeModeLoop()
{
	if (sysTick - timeoutTimer > 10) {
		mode = DISPLAY_TIME;
		return;
	}
	
	if (received) {
		received = false;
		if (subState == HR1) {
			if (rc6CommandReceived >=0 && rc6CommandReceived <= 2) {
				hr1 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(rc6CommandReceived, hr2, min1, min2);
				_delay_ms(100);
			}
		}
		
		else if (subState == HR2) {
			if ((hr1 >=0 && hr1 <= 1 && rc6CommandReceived >=0 && rc6CommandReceived <= 9) ||
			(hr1 == 2 && rc6CommandReceived >=0 && rc6CommandReceived <= 3)) {
				hr2 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(hr1, rc6CommandReceived, min1, min2);
				_delay_ms(100);
			}
		}
		
		else if (subState == MIN1) {
			if (rc6CommandReceived >=0 && rc6CommandReceived <= 5) {
				min1 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(hr1, hr2, rc6CommandReceived, min2);
				_delay_ms(100);
			}
		}
		
		else if (subState == MIN2) {
			if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				min2 = rc6CommandReceived;
				mode = DISPLAY_TIME;
				openNixieTimeSet(hr1*10+hr2, min1*10+min2, 0);
				openNixieTimeStoreHAL();
			}
		}
		
		rc6CommandReceived = 0xFF;
		displayHALSetImmediatly(hr1, hr2, min1, min2);
		RC6DecoderUnlock(rc6decoder);
	}
}

void setTimeModeOnExit()
{
	hr1=10;
	hr2=10;
	min1=10;
	min2=10;
	subState=HR1;
}

void
setTimeModeOnCommandReceived()
{
	if (!RC6DecoderIsRepeated(rc6decoder)) {
		received = true;
		} else {
		RC6DecoderUnlock(rc6decoder);
	}
	timeoutTimer = sysTick;
}