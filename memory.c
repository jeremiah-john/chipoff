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
		unsigned char *nextBlock = &mainMemory[512]; //contains the next block of data in the mainmemory array to write to
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
/* get the instruction starting at the provided address
 * instructions are 2 bytes long while address space is 1 byte,
 * meaning this function must combine 2 address spaces into one short
 * (6/29/2022) going to try just casting the address into a short pointer
 * but perhaps it would safe to avoid alignment issues and just bit shift the first value by 8 bits, then add to
 * that the second value
 */
short getInstruction(short address)
{
	int addressConvertedToInt = (int) address;
	short firstHalf = (short) mainMemory[addressConvertedToInt];//first half of instruction
	short secondHalf = (short) mainMemory[addressConvertedToInt+1];//second half of instruction
	firstHalf = firstHalf << 8; //shifts the first half to the "first half" of the short so we can more easily
	//combine the two parts of the instructions
	firstHalf += secondHalf;
	return firstHalf;
}
