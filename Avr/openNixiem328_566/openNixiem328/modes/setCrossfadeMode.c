/*
* setCrossfadeMode.c
*
* Created: 2020-09-14 22:58:40
*  Author: Trojan
*/
#include "displayHAL.h"
#include "OpenNixieTime.h"
#include "displayTimeMode.h"
#include "RC6.h"
#include "main.h"
#include <avr/eeprom.h>

extern volatile unsigned sysTick;
extern enum Mode mode;
extern unsigned char crossfade_ram;
extern unsigned char rc6CommandReceived;
extern RC6Decoder rc6decoder;
EEMEM extern unsigned char crossfade;

static unsigned timeoutTimer;
static bool received = false;

void
setCrossfadeModeOnEnter()
{
	timeoutTimer = sysTick;
	crossfade_ram = eeprom_read_byte(&crossfade);
	displayHALSetCrossfade(10, 10, 10, 10);
	displayHALSetDim(false);
}

void
setCrossfadeModeLoop()
{
	static unsigned timeUpdate = 0;
	
	if (sysTick - timeUpdate > 1) {
		timeUpdate = sysTick;
		if (crossfade_ram) {
			displayHALSetCrossfade(10, 10, openNixieTimeGetSeconds()/10, openNixieTimeGetSeconds()%10);
			} else {
			displayHALSetImmediatly(10, 10, openNixieTimeGetSeconds()/10, openNixieTimeGetSeconds()%10);
		}
	}
	
	if (received) {
		received = false;
		timeoutTimer = sysTick;
		
		if (rc6CommandReceived == 0) {
			crossfade_ram = 0;
		}
		
		if (rc6CommandReceived == 1) {
			crossfade_ram = 1;
		}
		
		if (rc6CommandReceived == 2) {
			mode = DISPLAY_TIME;
		}
	}
	RC6DecoderUnlock(rc6decoder);
	if (sysTick - timeoutTimer > 10) {
		mode = DISPLAY_TIME;
		return;
	}
}

void
setCrossfadeModeOnExit()
{
	eeprom_write_byte(&crossfade, crossfade_ram);
}

void
setCrossfadeModeOnCommandReceived()
{
	if (!RC6DecoderIsRepeated(rc6decoder)) {
		received = true;
		} else {
		RC6DecoderUnlock(rc6decoder);
	}
	timeoutTimer = sysTick;
}