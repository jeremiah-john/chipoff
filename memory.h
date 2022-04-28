#ifndef MEMORY_HEADER
#define MEMORY_HEADER

int loadProgram(char *fileName);
int writeMemToMem(int firstLocation, int secondLocation);
int writeRegToMem(int regNumber, int memoryLocation);
int writeRegToReg(int firstReg, int secondReg);
#endif
