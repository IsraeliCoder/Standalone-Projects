#include "Hashing.h"

int hashing(char* string)
{
	
	int runningIndex = 0;
	int numberToReturn = 0;

	while (string[runningIndex] != '\n')
	{
		numberToReturn += 31 * string[runningIndex] + string[runningIndex];
		numberToReturn %= MAX_NUMBER_FOR_HASHING;
		runningIndex++;
	}

	return numberToReturn;

}
