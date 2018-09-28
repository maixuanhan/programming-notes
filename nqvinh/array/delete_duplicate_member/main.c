#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
	4 . How are duplicates removed from a given array?
*/

#define ARRAYSIZE 20

void printArray(unsigned int array[], unsigned int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		printf("%d\t", array[i]);

	printf("\n");

	return;
}

void initArray(unsigned int array[], unsigned int arraySize)
{
	int i = 0;
	memset(array, 0 , arraySize);

	for (i = 0; i < arraySize; i++)
	{
		// random number in range 1 -> 40
		array[i] = rand() % (40 - 1 + 1) + 1;
	}

	printArray(array, arraySize);
	return;
}

void deleteDuplicateMember(unsigned int array[], unsigned int arraySize)
{
	int index  = 0;
	int Flag   = 0;
	unsigned int tmp[arraySize];

	for (int i = 0; i < arraySize; ++i)
	{
		Flag = 0;
		for (int n = 0; n < index; n++)
		{
			if (tmp[n] == array[i])
			{
				Flag = 1;
			}
		}

		if (Flag == 0)
		{
			tmp[index] = array[i];
			index++;
		}
	}

	printf("After delete Duplicate member:\n");
	printArray(tmp, index);

	return;
}


int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];

	// Use current time as seed for random generator
	srand(time(0));

	// run three time
	for (int i = 0; i < 3; i++)
	{
		// Init an array type int with 10 members content random number in range 1 -> 100
		initArray(array, ARRAYSIZE);

		deleteDuplicateMember(array, ARRAYSIZE);
		printf("\n\n");
	}

	return 0;
}
