#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. How do you find the missing number in a given integer array of 1 to 100?
SOLUTIONS:
	Sumary of full array minus to Sumary of missing number array.
*/

/*
	Build: gcc main.c -o main
	Run:   ./main 55
*/

void mixArray(unsigned int array[], unsigned int arraySize)
{
	int i, tmp, a, b;
	for (i = 0; i < (arraySize - 1); i++)
	{
		// (rand() % (upper - lower + 1)) + lower;
		// upper = 98, lower = 0;
		// int a = (rand() % (98 - 0 + 1)) + 0;
		// int b = (rand() % (98 - 0 + 1)) + 0;
		a = rand() % (arraySize - 1);
		b = rand() % (arraySize - 1);
		// swap 2 array member
		tmp      = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

void initArray(unsigned int array[], unsigned int missingNum, unsigned int arraySize)
{
	int flag = 0;
	if ((missingNum < 1) || (missingNum > 100))
	{
		printf("Wrong missing number\n");
		exit(0);
	}

	for (int i = 0; i < (arraySize - 1); i++)
	{
		if ((i + 1) == missingNum)
		{
			flag = 1;
		}
		array[i] = i + 1 + flag;
	}

	mixArray(array, arraySize);
}

unsigned int findMissingNumber(unsigned int array[], unsigned int arraySize)
{
	unsigned int orgSum = 0;
	unsigned int curSum = 0;

	// sum from 5 to 88: (5+88)*84:2 = 3906
	orgSum = ((1+100)*100)/2;

	for (int i = 0; i < (arraySize - 1); i++)
	{
		curSum += array[i];
	}
	return (orgSum - curSum);
}

int main(int argc, char const *argv[])
{
	unsigned int array[100];
	unsigned int arraySize = sizeof(array)/sizeof(array[0]);

	if (argc != 2)
	{
		printf("Invalid agrument!\n");
		exit(0);
	}

	// Use current time as seed for random generator
	srand(time(0));

	// Init an array with missing number is 2nd arg
	initArray(array, atoi(argv[1]), arraySize);

	printf("Missing Number is %d\n", findMissingNumber(array, arraySize));
	return 0;
}
