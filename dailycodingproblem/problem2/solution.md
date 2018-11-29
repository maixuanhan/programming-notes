## Solution 1

The solution using division may end up with O(n^2) since the value of an element may be 0.

```C++
vector<int> CalculateProduct_withDivision(const vector<int> &array)
{
    // Check for special cases: empty input array, single element array

    vector<int> result(array.size(), 0);
    int product = 1;

    for (int i = 0; i < array.size(); ++i)
    {
        product *= array[i];
    }

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] == 0)
        {
            result[i] = 1;
            for (int k = 0; k < array.size(); ++k)
            {
                if (i != k)
                {
                    result[i] *= array[k];
                }
            }
        }
        else
        {
            result[i] = product / array[i];
        }
    }

    return result;
}
```

## Solution 2

Use 2 extra arrays to store the product of all elements from the left and from the right and calculate the result based on them.
The algorithm complexity of this approach is O(n).

```C++
vector<int> CalculateProduct_withDivision(const vector<int> &array)
{
    // Check for special cases: empty input array, single element array

    vector<int> result(array.size(), 0);
    int product = 1;

    for (int i = 0; i < array.size(); ++i)
    {
        product *= array[i];
    }

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] == 0)
        {
            result[i] = 1;
            for (int k = 0; k < array.size(); ++k)
            {
                if (i != k)
                {
                    result[i] *= array[k];
                }
            }
        }
        else
        {
            result[i] = product / array[i];
        }
    }

    return result;
}
```
