#ifndef MEMORY_HEADER
#define MEMORY_HEADER

int loadProgram(char *fileName);
int writeMemtoMem(int firstLocation, int secondLocation);
#endif
#ifndef MEMORYREGISTEROPS_HEADER
#define MEMORYREGISTEROPS_HEADER
int writeRegToMem(int regNumber, int memoryLocation);
int writeRegtoReg(int firstRegistry, int secondRegistry);
int writeMemtoReg(int memoryLocation, int regNumber);
#endif
