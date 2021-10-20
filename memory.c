#include <stdio.h>
#include <errno.h>
#include "memory.h"

unsigned char mainMemory[4096];
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
		unsigned char *nextBlock = mainMemory; //contains the next block of data in the mainmemory array to write to
		while (!feof(currentGame))
		{
			fread(nextBlock, sizeof(unsigned char),1,currentGame);
			nextBlock++;
		}
	}
	fclose(currentGame);
	return 0;
}
