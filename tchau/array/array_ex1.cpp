#include <iostream>
#include <cstdlib>

using namespace std;

/*
* Function: findMissedNumberInIntegerArray
*
* Question: How do you find the missing number in a given integer array of 1 to 100? 
*/


int findMissedNumberInIntegerArray(int arr[])
{
	int sum = 0;
	int tmpSum = 0;
	
	//n*(n+1)/2 = sum(1,n)
	tmpSum = 100*(100+1)/2;
	
	for(int i=1; i<=99; i++)
	{
		sum+=arr[i-1];
	}

	return tmpSum - sum;
}

// init the array of 1..100 with a missing number
void init_test(int *array, int &missing_num)
{
	if (array == NULL) return;

	missing_num = rand() % 100 + 1;
	int seed = 1;
	int i = 0;
	while (seed <= 100)
	{
		if (seed != missing_num)
		{
			array[i] = seed;
			++i;
		}
		++seed;
	}

	for (int i = 0; i < 30; ++i)
	{
		int a = rand() % 99;
		int b = rand() % 99;

		int t = array[a];
		array[a] = array[b];
		array[b] = t;
	}
}

int main(int argc, char const *argv[])
{
	int arr[100];
	int ret = 0;

	srand(time(NULL));

	// run 10 test cases
	for (int i = 0; i<10; ++i)
	{
		int missing_num;
		init_test(arr, missing_num);

		ret = findMissedNumberInIntegerArray(arr);
		cout<< "EXPECT: "<< missing_num<<" - RESULT: "<< ret<< endl;
	}
	return 0;
}
