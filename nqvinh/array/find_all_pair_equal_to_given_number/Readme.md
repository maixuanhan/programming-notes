# How do you find all pairs of an integer array whose sum is equal to a given number?

### Solution: Pass through array to get all pairs equal to given number.

#### Implementation code:
```
for (int i = 0; i < arraySize; ++i)
{
    for(int j = i + 1; j < arraySize; j++)
    {
        if ((array[i] + array[j]) == givenNum)
        {
            printf(" %d  +  %d = %d\n", array[i], array[j], givenNum);
        }
    }
}
```
