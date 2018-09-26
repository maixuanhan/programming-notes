#include <iostream>
#include <cstring>

using namespace std;

#define DEBUG 0


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
	
	for(int i=1; i<=100; i++)
	{
		sum+=arr[i-1];
	}

#if DEBUG
	cout<<"Sum: "<<sum<<endl;
	cout<<"tmpSum: "<<tmpSum<<endl;
#endif

	return tmpSum - sum;
}



int main(int argc, char const *argv[])
{
	int arr[100];
	int ret = 0;

	memset(arr, 0, 100);
	for (int i = 1; i <= 100; ++i)
	{
		arr[i-1] = i;			
#if DEBUG
		cout<<"Added a["<<i-1<<"] = "<<arr[i-1]<<endl;
#endif
	}
	//Missed number (position 36 in the array)
	arr[35] = 0;

	ret = findMissedNumberInIntegerArray(arr);
	cout<< "Your array has missed: "<< ret<< endl;
	return 0;
}
