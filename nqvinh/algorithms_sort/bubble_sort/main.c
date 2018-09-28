#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	1 . How is a bubble sort algorithm implemented?.

	::  Bubble Sort is the simplest sorting algorithm that works by repeatedly
	::  swapping the adjacent elements if they are in wrong order.

	Example:
	First Pass:
	( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
	( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
	( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
	( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

	Second Pass:
	( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
	( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
	Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

	Third Pass:
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
	( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
*/

#define ARRAYSIZE 10

void swap(int *a, int *b)
{
	int tmp = 0;

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
		array[i] = rand() % (100 - 0 + 1) + 0;
	}

	printArray(array, arraySize);

}

void bubbleSort(unsigned int array[], unsigned int arraySize)
{
	for (int n = (arraySize - 1); n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			if (array[i] > array [i + 1])
			{
				swap(&array[i], &array [i + 1]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];
	// Use current time as seed for random generator
	srand(time(0));

	// Init an array type int with 10 members content random number in range 0 -> 100
	initArray(array, ARRAYSIZE);

	printf("After bubble sorting... \n");

	bubbleSort(array, ARRAYSIZE);

	printArray(array, ARRAYSIZE);

	return 0;
}
