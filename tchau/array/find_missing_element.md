## Find missing number from array 1..100
- Find the sum of the original array.
- Find the sum of the missing-one-number array.
- The different between values of two sums is the missing number.

Reference C++ code
```C++
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
```
