/*
 * button.h
 *
 * Created: 2020-09-09 22:48:00
 *  Author: Trojan
 */ 

#include <stdbool.h>
#include "pico/stdlib.h"

struct button {
	uint pin;
	unsigned int ms_timer;
	
	bool keyPressed;
	bool isKeyLongPressed;
};

void
buttonInit(struct button *self, uint pin);

void
button10MsStep(struct button *self);

bool
buttonIsKeyPressed(struct button *self);

bool
buttonIsKeyLongPressed(struct button *self);