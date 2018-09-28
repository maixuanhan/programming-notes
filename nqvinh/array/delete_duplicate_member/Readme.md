# How are duplicates removed from a given array?

### Solution: Create a new array and copy each element  is not present from Origin Array.
###### Implementation code:

    for (int i = 0; i < arraySize; ++i)
	{
    	//reset Flag
		Flag = 0;

        // check member is presented or not in tmp Array
		for (int n = 0; n < index; n++)
		{
			if (tmp[n] == array[i])
			{
            	// presented
				Flag = 1;
			}
		}

		// if not present, add
		if (Flag == 0)
		{
            tmp[index] = array[i];
			index++;
		}
	}
