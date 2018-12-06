Iterate the elements to calculate the maximum sum which can be achieved till the particular element.

```C++
int MaxNonAdjacentSum(const std::vector<int> &array)
{
    int max = 0;
    int n1 = 0, n2 = 0, n3 = 0;

    for (int i = 0; i < array.size(); ++i)
    {
        int m = std::max(n2, n3);
        if (array[i] > 0)
            m += array[i];

        if (max < m)
            max = m;

        n3 = n2;
        n2 = n1;
        n1 = m;
    }

    return max;
}
```
