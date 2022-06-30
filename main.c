#include "standard.h"
#include "memory.h"
#include "processor.h"

void mainLoop()
{
	//fetch part
	short currentInstruction = getInstruction(getProgramCounter());
	setProgramCounter(getProgramCounter() + 2); //set PC to next instruction in memory (which is 2 bytes ahead)

	//decode-execute part here
	//executeInstruction(currentInstruction);
}

int main()
{
   loadProgram("PONG");
   mainLoop();
   return 0;
}
