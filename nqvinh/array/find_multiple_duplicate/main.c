#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
	3 . How do you find duplicate numbers in an array if it contains multiple duplicates?
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

	for (i = 0; i < arraySize; i++)
	{
		// random number in range 1 -> 40
		array[i] = rand() % (40 - 1 + 1) + 1;
	}

	printArray(array, arraySize);
	return;
}

void findDuplicate(unsigned int array[], unsigned int arraySize)
{
	int findedFlag = 0;
	int repeatFlag = 0;
	// an array with N member have maximum (N/2) duplication number.
	// Create tmp Array[n/2] hold duplicate number
	unsigned int tmpSize = arraySize / 2;
	unsigned int tmp[tmpSize];
	int index = 0;

	memset(tmp, 0, tmpSize);

	for (int i = 0; i < arraySize; ++i)
	{
		for (int j = (i + 1); j < arraySize; ++j)
		{
			if (array[i] == array[j])
			{
				repeatFlag = 0;
				for (int n = 0; n < tmpSize; n++)
				{
					if (tmp[n] == array[i])
					{
						repeatFlag = 1;
					}
				}
				if (repeatFlag == 0)
				{
					tmp[index] = array[i];
					index++;
					findedFlag = 1;
				}
			}
		}
	}

	if (findedFlag == 1)
	{
		printf("Duplicate number: ");
		printArray(tmp, index);
	}
	else
	{
		printf("NO dupicate number\n");
	}

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

		findDuplicate(array, ARRAYSIZE);
		printf("\n\n");
	}

	return 0;
}
