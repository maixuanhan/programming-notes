#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/*
	6. How do you find all pairs of an integer array whose sum is equal to a given number?
*/

#define ARRAYSIZE 15

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

void findAllPair(unsigned int array[], unsigned int arraySize, unsigned int givenNum)
{
    bool flag = false;
	for (int i = 0; i < arraySize; ++i)
	{
        for(int j = i + 1; j < arraySize; j++)
        {
            if ((array[i] + array[j]) == givenNum)
            {
                printf(" %d  +  %d = %d\n", array[i], array[j], givenNum);
                #ifndef FIND_FLAG
                #define FIND_FLAG
                    flag = true;
                #endif
            }
        }
	}

    if (!flag)
    {
        printf("can not find any pair equal to %d", givenNum);
    }
    return;
}


int main(int argc, char const *argv[])
{
	unsigned int array[ARRAYSIZE];
    unsigned int givenNumber = 0;
	// Use current time as seed for random generator
	srand(time(0));

    givenNumber = rand() % (40 - 1 + 1) + 1;
    printf("Number: %d \n", givenNumber);
    initArray(array, ARRAYSIZE);
    printArray(array, ARRAYSIZE);
    findAllPair(array, ARRAYSIZE, givenNumber);

	return 0;
}
