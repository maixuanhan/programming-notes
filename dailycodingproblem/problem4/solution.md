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

## Solution 3 - reuse the input array

The idea of this solution is that we divide the array into 2 parts: positive numbers and non-positive numbers.
We then reuse the signed bit of the number to check that the number of that index is existed (similarly to solution 2).
The time complexity of this algorithm is O(n), the space complexity is O(C) (reuse input array is not counted).
Segregating the input arrays in significant since we use the signed bit for other purpose.

```C++
int FindFirstMissing_reuse_input(vector<int> array)
{
    int i = 0, j = array.size() - 1;
    int count = 0;

    while (i < j)
    {
        while (i < array.size() && array[i] > 0)
            ++i;

        while (j >= 0 && array[j] <= 0)
            --j;

        if (i < j)
        {
            std::swap(array[i], array[j]);
            ++i;
            --j;
            count = i;
        }
    }

    if (count == 0)
    {
        count = array.size();
        for (int i = 0; i < array.size(); ++i)
        {
            if (array[i] <= 0)
            {
                count = i;
                break;
            }
        }
    }

    for (int i = 0; i < count; ++i)
    {
        if (abs(array[i]) <= count)
        {
            array[abs(array[i]) - 1] = -array[abs(array[i]) - 1];
        }
    }

    for (int i = 0; i < count; ++i)
    {
        if (array[i] > 0)
            return i + 1;
    }

    return count + 1;
}
```
