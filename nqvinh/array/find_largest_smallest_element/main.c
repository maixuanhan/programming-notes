#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	5 . How do you find the largest and smallest number in an unsorted integer array?
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

unsigned int findLargestEle(unsigned int array[], unsigned int arraySize)
{
	unsigned int theLargest = array[0];
	for (int i = 1; i < arraySize; ++i)
	{
		if (array[i] > theLargest)
		{
			theLargest = array[i];
		}
	}
	return theLargest;
}

unsigned int findSmallestEle(unsigned int array[], unsigned int arraySize)
{
	unsigned int theSmallest = array[0];
	for (int i = 1; i < arraySize; ++i)
	{
		if (array[i] < theSmallest)
		{
			theSmallest = array[i];
		}
	}
	return theSmallest;
}


int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];

	// Use current time as seed for random generator
	srand(time(0));

    initArray(array, ARRAYSIZE);

    printf("the largest element is %d\n", findLargestEle(array, ARRAYSIZE));
    printf("the largest element is %d\n", findSmallestEle(array, ARRAYSIZE));

	return 0;
}
