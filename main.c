#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "memory.h"

extern FILE *currentGame;

int main()
{
   loadProgram("PONG");
   return 0;
}
