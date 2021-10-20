#include <time.h>
#include "timer.h"

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

