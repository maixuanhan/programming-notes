#include <iostream>
#include "common.hpp"

using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
* the first loop will be run (n-1) times that is enough
* the second loop need only run (n-1-i) times because
* when the first loop did 1 time we have done a number.
*/

void bubbleSort(int array[], int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < (n-1)-i; ++j)
		{
			if (array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
			}
		}
	}
}


void printArray(int array[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}
