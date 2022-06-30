#include "standard.h"
#include "processor.h"
/*
 * an unsigned char is 8 bits, 1 byte. while a short is 16 bits: 2 bytes. perhaps we can use a macro for these to
 * remove any confusion? (comment made 6/28/2022)
 */
 
static unsigned char V[16]; //the general purpose registers, in Chip-8 documentation referred to as Vx. from V0 to VF
//VF is used as a flag by some instructions, not used by any program
//delay and sound timers are specified in timer.c and there are access functions for those already

//specify 16-bit I register
short iReg;
short programCounter; //program counter is 16 bits
unsigned char stackPointer; //stackPointer points to the topmost level of stack, must be 8-bit

short stack[16]; //stack has 16 16-bit values.

int startProgram()
{
	programCounter = 512; //we set the start of the program, that is, the address of the first instruction
	return 0;
}

short getProgramCounter()
{
	return programCounter;
}
void setProgramCounter(short newVal)
{
	programCounter = newVal;
}

void executeInstruction(short instruction)
{
	//lets do a set of nested if statements, where the topmost if statements check the first four bits, then
	//the nested if statements check subsequent bits

	//lets make a temporary variable that we can do repeating masking and bitshift operations on
	//also let us make our masks
	//we will have to bit shift the tempInstructionVar to different lengths depending on context of
	//current opcode specified
	short tempInstructionVar = instruction;
	const unsigned short firstFour = 0xF000;
	const unsigned short secondFour = 0x0F00;
	const unsigned short thirdFour = 0x00F0;
	const unsigned short fourthFour = 0x000F;
	const unsigned short remainderTwelve = 0x0FFF; //for instructions such as JP (1nnn) that rely on remaining twelve bits in instruction to determine address
	const unsigned short lastEight = 0x00FF;
	const unsigned short middleEight = 0x0FF0;
	//no need to implement opcode 0nnn
	tempInstructionVar = (tempInstructionVar & firstFour) >> 12;
	if (tempInstructionVar = 0) //if it starts with 0, then it must be either instruction CLS or RET
	{

	}
	else if (tempInstructionVar = 1) //must be the JP instruction
	{

	}
	else if (tempInstructionVar = 2) //must be Call instruction
	{

	}
}
