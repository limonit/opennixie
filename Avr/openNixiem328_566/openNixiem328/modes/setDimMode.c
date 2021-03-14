/*
 * setDimMode.c
 *
 * Created: 2020-09-13 21:03:04
 *  Author: Trojan
 */ 
#include "displayHAL.h"
#include "OpenNixieTime.h"
#include "setTimeMode.h"
#include "displayTimeMode.h"
#include "RC6.h"
#include "main.h"
#include <avr/eeprom.h>
#include <util/delay.h>

extern volatile unsigned sysTick;
extern volatile unsigned sysTick100ms;
extern enum Mode mode;
extern unsigned char rc6CommandReceived;
extern RC6Decoder rc6decoder;
extern EEMEM unsigned char dimStartHour;
extern EEMEM unsigned char dimEndHour;
extern unsigned char dimStartHour_ram;
extern unsigned char dimEndHour_ram;

static enum {HRSTART_1, HRSTART_2, HREND_1, HREND_2} subState = HRSTART_1;
static unsigned char hrStart1 = 10, hrStart2 = 10, hrEnd1 = 10, hrEnd2 = 10;
static bool received = false;
static unsigned timeoutTimer;

void
setDimModeOnEnter()
{
	dimStartHour_ram = eeprom_read_byte(&dimStartHour);
	dimEndHour_ram = eeprom_read_byte(&dimEndHour);
	
	displayHALSetImmediatly(dimStartHour_ram/10, dimStartHour_ram%10 ,dimEndHour_ram/10,dimEndHour_ram%10);
	subState = HRSTART_1;
	hrStart1 = 10;
	hrStart2 = 10;
	hrEnd1=10;
	hrEnd2=10;
	
	timeoutTimer = sysTick;
}

void
setDimModeLoop()
{

	if (sysTick - timeoutTimer > 10) {
		mode = DISPLAY_TIME;
		return;
	}
		
	if (received) {
		received = false;
		if (subState == HRSTART_1) {
			if (rc6CommandReceived >=0 && rc6CommandReceived <= 2) {
				hrStart1 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(rc6CommandReceived, hrStart2, hrEnd1, hrEnd2);
				_delay_ms(100);
			}
		}
			
		else if (subState == HRSTART_2) {
			if ((hrStart1 >=0 && hrStart1 <= 1 && rc6CommandReceived >=0 && rc6CommandReceived <= 9) ||
			(hrStart1 == 2 && rc6CommandReceived >=0 && rc6CommandReceived <= 3)) {
				hrStart2 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(hrStart1, rc6CommandReceived, hrEnd1, hrEnd2);
				_delay_ms(100);
			}
		}
			
		else if (subState == HREND_1) {
			if (rc6CommandReceived >=0 && rc6CommandReceived <= 2) {
				hrEnd1 = rc6CommandReceived;
				subState++;
				} else if (rc6CommandReceived >=0 && rc6CommandReceived <= 9) {
				displayHALSetImmediatly(hrStart1, hrStart2, rc6CommandReceived, hrEnd2);
				_delay_ms(100);
			}
		}
			
		else if (subState == HREND_2) {
			if  ((hrEnd1 >=0 && hrEnd1 <= 1 && rc6CommandReceived >=0 && rc6CommandReceived <= 9) ||
			(hrEnd1 == 2 && rc6CommandReceived >=0 && rc6CommandReceived <= 3)) {
				hrEnd2 = rc6CommandReceived;
				dimStartHour_ram = 10*hrStart1 + hrStart2;
				dimEndHour_ram = 10*hrEnd1 + hrEnd2;
				mode = DISPLAY_TIME;
			}
		}
		
		rc6CommandReceived = 0xFF;
		displayHALSetImmediatly(hrStart1, hrStart2, hrEnd1, hrEnd2);
		RC6DecoderUnlock(rc6decoder);
	}
}

void
setDimModeOnExit()
{
	eeprom_update_byte(&dimStartHour, dimStartHour_ram);
	eeprom_update_byte(&dimEndHour, dimEndHour_ram);
}

void
setDimModeOnCommandReceived()
{
	if (!RC6DecoderIsRepeated(rc6decoder)) {
		received = true;
		} else {
		RC6DecoderUnlock(rc6decoder);
	}
	timeoutTimer = sysTick;
}