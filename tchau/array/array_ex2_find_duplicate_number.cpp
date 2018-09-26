#include <iostream>
#include <cstdlib>
#include "common.hpp"

using namespace std;


/*
* Function: find_duplicate_number
*
* Question: How do you find the duplicate number on a given integer array?
*/

void find_duplicate_number(int array[], int n)
{
	
	printArray(array,10);
	bubbleSort2(array,10);
	cout << "hello" << endl;
	printArray(array,10);

	int current = array[0];
	int cnt 	= 1;
	for (int i = 1; i < n; ++i)
	{
		if (current == array[i])
		{
			cnt++;
		}
		else 
		{
			if (cnt >= 2)
			{
				cout << "Duplicate number: " << current << endl;
				cnt = 1;
				current = array[i];
			}
			else
			{
				current = array[i];
			}
		}
	}
}





int main(int argc, char const *argv[])
{
	int arr[] = {10,2,54,0,34,2,1,4,1,10};
	cout << "hi" << endl;
	find_duplicate_number(arr,10);
	return 0;
}
