#include <time.h>
#include <stdint.h>
#include "timer.h"
//I think I set the timers as unsigned chars because of the space but 
//this might mess with the way the program interprets the numbers
//casting an unsigned char to an integer might be hard
//we need a way to keep these variables at the required bitsize for the registers
//and also keep them as readable numbers
//we'll use stdint.h
unsigned char delayTimer = 0;
unsigned char soundTimer = 0;

unsigned char getDelayTimerVal(unsigned char *destRegister)
{
	*destRegister = delayTimer;
	return 0;
}

unsigned char setDelayTimerVal(unsigned char *sourceRegister)
{
	delayTimer = *sourceRegister;
	return 0;
}

unsigned char setSoundTimerVal(unsigned char *sourceRegister)
{
	soundTimer = *sourceRegister;
	return 0;
}
void decrementDT()
{
	if (delayTimer != 0)
	{
		delayTimer--;
	} //this is a placeholder, we'll figure it out later
}
