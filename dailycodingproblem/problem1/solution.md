## Solution 1

Sort the input array.
Try to check the result by traversing both forwarding and backwarding directions.

The complexity of the algorithm is up to the complexity of the sorting algorithm.

```C++
bool CheckArray_sort(vector<int> array, int number)
{
    sort(array.begin(), array.end());
    int f = 0;
    int b = array.size() - 1;

    while (f < b)
    {
        int s = array[f] + array[b];
        if (s == number)
        {
            return true;
        }
        else if (s > number)
        {
            --b;
        }
        else
        {
            ++f;
        }
    }

    return false;
}
```

## Solution 2

Utilize the language's feature **map** to mark if the complement of the sum is existed.

The complexity of the algorithm:
- Average case: O(n).
- Worst case: O(n^2).

```C++
bool CheckArray_map(vector<int> array, int number)
{
    unordered_map<int, bool> m;
    for (int i = 0; i < array.size(); ++i)
    {
        int r = number - array[i];
        if (m[r])
            return true;

        m[array[i]] = true;
    }
    return false;
}
```