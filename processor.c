#include "standard.h"
#include "processor.h"

static unsigned char V[16]; //the general purpose registers, in Chip-8 documentation referred to as Vx. from V0 to VF
//VF is used as a flag by some instructions, not used by any program
//delay and sound timers are specified in timer.c and there are access functions for those already
short programCounter; //program counter is 16 bits
unsigned char stackPointer; //stackPointer points to the topmost level of stack, must be 8-bit

short stack[16]; //stack has 16 16-bit values.
