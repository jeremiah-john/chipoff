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
clock_t delayTimerSetTime; //we'll set this time when the delay timer is set
clock_t delayTimerRequestTime; //we set this when an instruction requires the value in the delay Timer
//we then subtract this time from the time the delay timer was last set, multiply (or divide) by the frequency to get the correct current value of the timer
//then we return that in getDelayTimerVal
//we'll do something similar for the sound timer
unsigned char getDelayTimerVal(unsigned char *destRegister)
{
	delayTimerRequestTime = clock();
	double secondsPassed = (double) (delayTimerRequestTime - delayTimerSetTime) / CLOCKS_PER_SEC;
	delayTimer -= (int) secondsPassed*60;
	return 0;
}

unsigned char setDelayTimerVal(unsigned char *sourceRegister)
{
	delayTimer = *sourceRegister;
	delayTimerSetTime = clock();
	return 0;
}

unsigned char setSoundTimerVal(unsigned char *sourceRegister)
{
	soundTimer = *sourceRegister;
	return 0;
}
