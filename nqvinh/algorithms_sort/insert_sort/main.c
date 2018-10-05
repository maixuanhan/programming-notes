#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    3 . How do you implement an insertion sort algorithm?
    Algorithm
    // Sort an arr[] of size n
    insertionSort(arr, n)
    Loop from i = 1 to n-1.
    ……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

    Another Example: 
    12, 11, 13, 5, 6

    Let us loop for i = 1 (second element of the array) to 5 (Size of input array)

    i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
    11, 12, 13, 5, 6

    i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
    11, 12, 13, 5, 6

    i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
    5, 11, 12, 13, 6

    i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
    5, 6, 11, 12, 13
*/

#define ARRAYSIZE 10

void insertSort(unsigned int array[], unsigned int arraySize);

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
}

void insertSort(unsigned int array[], unsigned int arraySize)
{
    for (int i = 1; i < arraySize; i++)
    {
        int j = i;
        while (j > 0 && array[j] < array[j-1])
        {
            swap(&array[j], &array[j-1]);
            j--;
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

    printArray(array, ARRAYSIZE);

    printf("After insert sorting... \n");

    insertSort(array, ARRAYSIZE);

    printArray(array, ARRAYSIZE);

    return 0;
}
