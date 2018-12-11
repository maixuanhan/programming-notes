#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*
	6. How do you reverse an array?
*/

#define ARRAYSIZE 15

void swap(unsigned int *a, unsigned int *b)
{
	unsigned int tmp = 0;

	tmp = *a;
	*a  = *b;
	*b  = tmp;

	return;
}

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

	return;
}

void reverseArray(unsigned int array[], unsigned int arraySize)
{
	for (int i = 0; i < (arraySize / 2); i++)
	{
        swap(&array[i], &array[arraySize -1 - i]);
    }
}


int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];
	// Use current time as seed for random generator
	srand(time(0));

    initArray(array, ARRAYSIZE);
    printArray(array, ARRAYSIZE);

    reverseArray(array, ARRAYSIZE);
    printf("Array after reversing...\n");
    printArray(array, ARRAYSIZE);

	return 0;
}
