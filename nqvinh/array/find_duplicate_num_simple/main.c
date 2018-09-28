#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	2 . How do you find the duplicate number on a given integer array?
*/

#define ARRAYSIZE 10

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

	for (i = 0; i < arraySize; i++)
	{
		array[i] = rand() % (100 - 0 + 1) + 0;
	}

	printArray(array, arraySize);
	return;
}

void findDuplicate(unsigned int array[], unsigned int arraySize)
{
	int findedFlag = 0;
	for (int i = 0; i < arraySize; ++i)
	{
		for (int j = (i + 1); j < arraySize; ++j)
		{
			if (array[i] == array[j])
			{
				findedFlag = 1;
				printf("Duplicate Number = %d\n", array[i]);

			}
		}
	}
	if (!findedFlag)
	{
		printf("!!! NO duplicate Number !!!\n");
	}

	return;
}


int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];

	// Use current time as seed for random generator
	srand(time(0));


	// run five time
	for (int i = 0; i < 5; i++)
	{
		// Init an array type int with 10 members content random number in range 0 -> 100
		initArray(array, ARRAYSIZE);

		findDuplicate(array, ARRAYSIZE);
		printf("\n");
	}

	return 0;
}
