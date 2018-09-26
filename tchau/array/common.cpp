#include <iostream>
#include "common.hpp"

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}




void bubbleSort(int array[])
{
	int n = sizeof(array);
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n-1-i; ++j)
		{
			if (array[j] > array[j+1])
			{
				swap(&array[j], &array[j+1]);
			}
		}
	}
}

void bubbleSort2(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
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
