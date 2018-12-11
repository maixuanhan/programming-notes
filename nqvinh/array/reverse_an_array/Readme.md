# How do you reverse an array?

### Solution: swap the first element with the last element, swap the second element with the element next to the last element, go on until meet the midle element.

#### Implementation code:
```
for (int i = 0; i < (arraySize / 2); i++)
{
    swap(&array[i], &array[arraySize -1 - i]);
}
```
