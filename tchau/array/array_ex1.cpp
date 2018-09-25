#include <iostream>
#include <cstring>

using namespace std;

#define MIN 1
#define MAX 100
#define DEBUG 0


/*
* Function: findMissedNumberInIntegerArray
*
* Question: How do you find the missing number in a given integer array of 1 to 100? 
*/


int findMissedNumberInIntegerArray(int arr[], int min, int max)
{
	int sum = 0;
	int tmpSum = 0;
	for(int i=min; i<=max; i++)
	{
		tmpSum+=i;
		sum+=arr[i-1];
#if DEBUG
		cout<<"Line: "<<__LINE__<< " Func: "<<__FUNCTION__;
		cout<<"a["<<i-1<<"] = "<<arr[i-1]<<endl;
#endif
	}

#if DEBUG
	cout<<"Sum: "<<sum<<endl;
	cout<<"tmpSum: "<<tmpSum<<endl;
#endif

	return tmpSum - sum;
}



int main(int argc, char const *argv[])
{
	int arr[MAX];
	int ret = 0;
	int num = 0;

	cout<<"Please enter the number that's missed (1-100): ";
	cin>>num;

#if DEBUG
	cout<<"The number that you enter: "<<num<<endl;
#endif
	if (num < MIN  || num > MAX)
	{
		cout<<"We only accept the number from "<<MIN<<" to "<<MAX<<endl;
		return -1;
	}

	memset(arr, 0, MAX);
	for (int i = MIN; i <= MAX; ++i)
	{
		if (i != num)
		{
			arr[i-1] = i;
#if DEBUG
			cout<<"Added a["<<i-1<<"] = "<<arr[i-1]<<endl;
#endif
		}
	}

	ret = findMissedNumberInIntegerArray(arr, MIN, MAX);
	cout<< "Your array has missed: "<< ret<< endl;
	return 0;
}