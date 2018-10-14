# How do you find the largest and smallest number in an unsorted integer array?

### Solution: create a variable to store the largest or the smallest element when passing the array.
###### Implementation code:
```
    findLargestEle(unsigned int array[], unsigned int arraySize)
    theLargest = array[0];
    for (int i = 1; i < arraySize; ++i)
    {
        if (array[i] > theLargest)
        {
            theLargest = array[i];
        }
    }
    return theLargest;
```