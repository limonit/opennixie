#include <stdlib.h>
#include "RC6.h"

#define S_L 320
#define S_H 590
#define L_L 750
#define L_H 1150

enum RC6State {IDLE, LEADER1, LEADER2, S1, S2, H1, H2, H3, H4, H5, T1, T2, CR1};

struct RC6Decoder_ {
	unsigned char RC6_CommandRecv;
	unsigned char RC6_CommandPrev;
	unsigned char RC6_Command;
	
	unsigned char RC6_ControlRecv;
	unsigned char RC6_Control;
	
	bool RC6Repeated;
	
	unsigned char half_bit;
	unsigned char bit_cntr;
	unsigned char toggle;
	unsigned char togglePrev;
	
	bool locksBuffer;
	bool isLocked;
	
	enum RC6State RC6DecoderState;
	
	volatile unsigned int timerValue;
	
	void (*RC6Callback)(RC6Decoder self);         //  method called by decoder when correct RC6 message is received
	bool (*RC6GetPinState)(void);                 //  method called by decoder to check Pin state of receiver
	unsigned int(*RC6GetMicrosecondTimer)(void);   //  method called by decoder to get free running milisecond timer value
};

static void RC6idle(RC6Decoder self)
{
	self->RC6DecoderState = IDLE;
	self->half_bit = 0;
	self->bit_cntr = 0;
	self->RC6_CommandRecv = 0;
	self->RC6_ControlRecv = 0;
}


void RC6DecoderOnPinChange(RC6Decoder self)
{
	unsigned length = self->RC6GetMicrosecondTimer() - self->timerValue;

	self->timerValue = self->RC6GetMicrosecondTimer();
	
	if(self->RC6DecoderState == IDLE)
	{
		if (length > 3 * L_L && length < 3 * L_H && self->RC6GetPinState()) 
		{
			self->RC6DecoderState = LEADER1;
			return;
		}
		else RC6idle(self);
	}
	
	if(self->RC6DecoderState == LEADER1)
	{

		if (length > L_L && length < L_H && (!self->RC6GetPinState())) {self->RC6DecoderState = LEADER2; return;}
		else RC6idle(self);
	}

	if (self->RC6DecoderState == LEADER2)
	{
		

		if(length > S_L && length < S_H  && self->RC6GetPinState())
		{

			self->RC6DecoderState = S1;
			return;
		}
		else RC6idle(self);
	}

	if (self->RC6DecoderState == S1)
	{
		if(length > L_L && length < L_H  && (!self->RC6GetPinState()))
		{
			self->RC6DecoderState = S2;
			return;
		}
		else RC6idle(self);
	}

	if(self->RC6DecoderState == S2)
	{
		
		if(length > S_L && length < S_H  && self->RC6GetPinState())
		{
			self->RC6DecoderState = H1;
			return;
		}
		else RC6idle(self);
	}

	if(self->RC6DecoderState == H1)
	{
		
		if(length > S_L && length < S_H  && (!self->RC6GetPinState()))
		{
			self->RC6DecoderState = H2;
			return;
		}
		else RC6idle(self);
	}

	if(self->RC6DecoderState == H2)
	{

		if(length > S_L && length < S_H  && self->RC6GetPinState())
		{
			self->RC6DecoderState = H3;
			return;
		}
		else RC6idle(self);
	}

	if(self->RC6DecoderState == H3)
	{
		if(length > S_L && length < S_H  && (!self->RC6GetPinState()))
		{
			self->RC6DecoderState = H4;
			return;
		}
		else RC6idle(self);
	}


	if(self->RC6DecoderState == H4) {
		if(length > S_L && length < S_H &&  self->RC6GetPinState())
		{
			self->RC6DecoderState = H5; 
			self->toggle = 0; 
			return;
		}
		else if (length > S_L+L_L && length < S_H + L_H &&  self->RC6GetPinState())
		{
			self->RC6DecoderState = T1; 
			self->toggle = 1; 
			return;
		}
		else RC6idle(self);
	}

	if(self->RC6DecoderState == H5)
	{
		if(length > L_L && length < L_H  && (!self->RC6GetPinState()))
		{
			self->RC6DecoderState = T1;  
			return;
		}
		else  RC6idle(self);
	}
	
	if(self->RC6DecoderState == T1){
		if(length > L_L && length < L_H)
		{
			self->RC6DecoderState = T2; 
			return;
		}
		else if (length > S_L + L_L && length < S_H + L_H)
		{
			self->RC6DecoderState = CR1; 
			self->half_bit = 1; 
			length = L_L + 1;
		}
		else  RC6idle(self);
	}
	
	if(self->RC6DecoderState == T2)
	{
		if(length > S_L && length < S_H )
		{
			self->RC6DecoderState = CR1;  
			self->half_bit = 1; 
			length = L_L + 1;
		}
		else  RC6idle(self);
	}
	
	
	if(self->RC6DecoderState == CR1)
	{
		if(length > S_L && length < S_H )
		{
			self->half_bit ^= 1;
		}
		else if(length > L_L && length < L_H );
		else RC6idle(self);
		
		if(self->half_bit && self->bit_cntr >= 8)
		{
			self->RC6_CommandRecv  = (self->RC6_CommandRecv << 1);
			if(self->RC6GetPinState()) self->RC6_CommandRecv++;
			self->bit_cntr++;
		}
		
		if(self->half_bit && self->bit_cntr < 8)
		{
			self->RC6_ControlRecv  = (self->RC6_ControlRecv<<1);
			if(self->RC6GetPinState()) self->RC6_ControlRecv++;
			self->bit_cntr++;
		}
		
		if(self->bit_cntr == 16)
		{
			if (!(self->locksBuffer && self->isLocked))
			{
				self->RC6_Command = self->RC6_CommandRecv;
				self->RC6_Control = self->RC6_ControlRecv;
				
				if (self->toggle == self->togglePrev && self->RC6_Command == self->RC6_CommandPrev) {
					self->RC6Repeated = true;
					} else {
					self->RC6Repeated = false;
				}
				
				if (self->locksBuffer) {
					self->isLocked = true;
				}
				
				self->RC6_CommandPrev = self->RC6_Command;
				self->togglePrev = self->toggle;
				
				self->RC6Callback(self);
			}
			RC6idle(self);	
		}
	}
}

RC6Decoder RC6DecoderCreate(void (*RC6Callback)(RC6Decoder self), bool (*RC6GetPinState)(void), unsigned int(*RC6GetMicrosecondTimer)(void), bool locksBuffer)
{
	RC6Decoder self = malloc(sizeof(struct RC6Decoder_));
	self->RC6Callback = RC6Callback;
	self->RC6GetPinState = RC6GetPinState;
	self->RC6GetMicrosecondTimer = RC6GetMicrosecondTimer;
	
	self->locksBuffer = locksBuffer;
	
	RC6idle(self); 
	RC6DecoderUnlock(self);
	return self;
}

unsigned char RC6DecoderGetControl (RC6Decoder self)
{
	return self->RC6_Control;
}

unsigned char RC6DecoderGetCommand (RC6Decoder self)
{
	return self->RC6_Command;
}

unsigned char RC6DecoderIsRepeated (RC6Decoder self)
{
	return self->RC6Repeated;
}

void RC6DecoderUnlock(RC6Decoder self)
{
	self->isLocked = false;
}
