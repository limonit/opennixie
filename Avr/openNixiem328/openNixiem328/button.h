/*
 * button.h
 *
 * Created: 2020-09-09 22:48:00
 *  Author: Trojan
 */ 

#include <stdbool.h>

struct button {
	volatile unsigned char *portIn;
	char pin;
	unsigned int ms_timer;
	
	bool keyPressed;
	bool isKeyLongPressed;
};

void
buttonInit(struct button *self, volatile unsigned char *portIn, volatile unsigned char* portDdr, unsigned char pin);

void
button10MsStep(struct button *self);

bool
buttonIsKeyPressed(struct button *self);

bool
buttonIsKeyLongPressed(struct button *self);