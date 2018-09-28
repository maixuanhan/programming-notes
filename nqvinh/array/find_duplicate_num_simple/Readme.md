# How do you find the duplicate number on a given integer array?

### Solution: run 2 nested For to check member is duplicate or not
###### Implementation code:

    for (int i = 0; i < arraySize; ++i)
	{
		for (int j = (i + 1); j < arraySize; ++j)
		{
			if (array[i] == array[j])
			{
				findedFlag = 1;
				printf("Duplicate Number = %d\n", array[i]);
			}
		}
	}
	if (!findedFlag)
	{
		printf("!!! NO duplicate Number !!!\n");
	}
