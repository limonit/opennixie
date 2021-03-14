/*
 * DS3231.h
 *
 * Created: 2018-04-01 12:31:04
 *  Author: Trojan
 */ 


#ifndef DS3231_H_
#define DS3231_H_

#define A1M1 0x7    // use alarm setting as RAM storage
#define A1M2 0x8
#define TEMP_H 0x11

void ds1307getTime();    // loads time from ds1307 into oepnNixieTime
void ds1307setTime();   // updates DS1307 with time from oepnNixieTime (resets seconds)
char ds1307getTemp(void);


#endif /* DS3231_H_ */