/*
 * button.c
 *
 * Created: 2020-09-09 22:17:52
 *  Author: Trojan
 */ 
#include "button.h"
	
void
buttonInit(struct button *self, uint pin)
{
	self->pin = pin;
	self->ms_timer = 0;
	self->keyPressed = 0;
	self->isKeyLongPressed = 0;
	
	gpio_set_dir(pin, false);
    gpio_set_pulls(pin, true, false);
}

void
button10MsStep(struct button *self)
{
	if (!gpio_get(self->pin)) {
		self->ms_timer++;
		if (self->ms_timer == 2) {
			self->keyPressed = true;
			self->ms_timer++;
		}
		if (self->ms_timer > 80) {
			self->isKeyLongPressed = true;
		}
	} else {
		self->ms_timer = 0;
		self->isKeyLongPressed = false;
	}
}

bool
buttonIsKeyPressed(struct button *self)
{
	if (self->keyPressed) {
		self->keyPressed = false;
		return true;
	}
	return false;
}

bool
buttonIsKeyLongPressed(struct button *self)
{
	return self->isKeyLongPressed;
}