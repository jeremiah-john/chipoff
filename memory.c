#include "standard.h"
#include "memory.h"

static unsigned char mainMemory[4096];

//IMPORTANT: all chip 8 instructions are 2 bytes long, meaning one byte takes up two memory spaces
//the current LoadProgram function handles this well, and all first bytes of each instruction will be placed
//in even address spaces
int loadProgram(char *gameFileName)
{
	
        FILE *currentGame;
	currentGame = fopen(gameFileName,"r");
	if(currentGame == NULL) //if there was a problem opening the file
	{
		perror("Error Opening Game File: ");
	}
	else
	{
		//we should include option to load programs for ETI 660 into location 1536 instead of 512
		unsigned char *nextBlock = mainMemory[512]; //contains the next block of data in the mainmemory array to write to
		//most programs will start at location 512
		while (!feof(currentGame))
		{
			if(nextBlock > &mainMemory[4095]) //if the game is too big to fit in memory, fatal quit
			{

				fprintf(stderr, "game file is too big!, exiting with value -1\n");
				exit(-1);
			}
			fread(nextBlock, sizeof(unsigned char),1,currentGame); //read 1 byte from currentGame file into the nextBlock of memory
			nextBlock++; //will move up in memory by 1 * sizeof(unsinged char)
		}
	}
	fclose(currentGame);
	return 0;
}
//move the memory in the first location to the second location
int writeMemToMem(int firstLocation, int secondLocation)
{	//if the memory locations are not valid, fatal quit
	if(firstLocation >= 4096 || secondLocation >= 4096)
	{
		fprintf(stderr, "the program is trying to access memory outside what is allocated for it! (only 4096 bytes accessible) exiting with SIGSEGV value (11)\n");
		exit(11);
	}
	
	mainMemory[secondLocation] = mainMemory[firstLocation];
	//find out if we clean firstLocation data or keep it
	return 0;
}
