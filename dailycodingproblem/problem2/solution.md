## Solution 1 - with division

Calculate the `product` of all elements.
Value of i-th element is calculated by `(product / input[i])`.
The solution using division may end up with O(n^2) since the value of an element may be 0. (For zero case, a usual traversing is needed)
The complexity of the algorithm:
- Average case: O(n).
- Worst case: O(n^2).

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

## Solution 2 - without division

Use 2 extra arrays to store the product of all elements from the left and from the right and calculate the result based on them.
The algorithm complexity of this approach is O(n).

```C++
vector<int> CalculateProduct_withoutDivision(const vector<int> &array)
{
    // Check for special cases: empty input array, single element array

    int size = array.size();

    vector<int> result(size, 0);
    vector<int> forward(size + 1, 1);
    vector<int> backward(size + 1, 1);

    for (int i = 0; i < size - 1; ++i)
    {
        forward[i + 1] = forward[i] * array[i];
        backward[size - 1 - i] = backward[size - i] * array[size - 1 - i];
    }

    for (int i = 0; i < size; ++i)
    {
        result[i] = forward[i] * backward[i + 1];
    }

    return result;
}
```
