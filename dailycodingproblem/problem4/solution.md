## Solution 1 - sort the array

The first solution comes up to my mind is that sorting the input array but this would make the time complexity beyond O(n).

```C++
int FindFirstMissing_sort(vector<int> array)
{
    sort(array.begin(), array.end());
    int i = 0;

    while (i < array.size() && array[i] < 1)
    {
        ++i;
    }

    int num = 1;
    for (; i < array.size() && array[i] == num; ++i, ++num);

    return num;
}
```

## Solution 2 - mark the values

This solution needs a space with the variable size to check if a number is existed.
(Because they allow modifying the input array in-place, we can re-use the input to store the state instead of creating a new array, maybe by occupying some bit to store the state.)

```C++
int FindFirstMissing_mark(vector<int> array)
{
    vector<bool> m(array.size() + 1, false);

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] > 0 && array[i] < m.size())
            m[array[i]] = true;
    }

    for (int i = 1; i < m.size(); ++i)
    {
        if (!m[i])
            return i;
    }

    return m.size();
}
```
