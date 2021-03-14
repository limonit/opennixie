/*
 * DS3231.c
 *
 * Created: 2018-04-01 12:31:39
 *  Author: Trojan
 */ 

#include "openNixie.h"
#include <avr/io.h>		// include I/O definitions (port names, pin names, etc)
#include <avr/interrupt.h>
#include "i2c_master.h"
#include "DS3231.h"


#define ds1307_W 0b11010000
#define ds1307_R 0b11010001

extern struct oepnNixieTime oepnNixieTime;
/*
static void ds1307getTime(char *time);
static inline void ds1307setTime(char *time);
*/


void ds1307getTime(char *time)
{
	char getTimeMessage[3] = {0,0,0};
	char addressSetMessage[1] = {0x0};
	
	i2c_init();
	i2c_transmit(ds1307_W, addressSetMessage, 1);
	i2c_receive(ds1307_R, getTimeMessage, 3);
	
	time[0] = getTimeMessage[0];
	time[1] = getTimeMessage[1];
	time[2] = getTimeMessage[2];
}

void ds1307setTime(char *time)
{
	char s_time[4] = {0, time[0], time[1], time[2]};
	i2c_init();
	i2c_transmit(ds1307_W, s_time, 4);
	
	char control[] = {0xE, 0b00011100};
		
	i2c_init();
	i2c_transmit(ds1307_W, control, 2);
}

char ds1307getTemp (void)
{

	char message[1] = {0};
	char addressSetMessage[1] = {TEMP_H};
	
	i2c_init();
	i2c_transmit(ds1307_W, addressSetMessage, 1);
	i2c_receive(ds1307_R,message, 1);
	
	return message[0];
}