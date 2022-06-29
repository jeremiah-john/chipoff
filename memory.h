#ifndef MEMORY_HEADER
#define MEMORY_HEADER

int loadProgram(char *fileName);
short getInstruction(short address); //address is short because most times, the value provided will be the programCounter
#endif
