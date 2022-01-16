#ifndef TIMER_HEADER
#define TIMER_HEADER
unsigned char getDelayTimerVal(unsigned char *destRegister);
unsigned char setDelayTimerVal(unsigned char *sourceRegister);
void decrementDT();
void decrementST();
unsigned char setSoundTimerVal(unsigned char *sourceRegister);
#endif
