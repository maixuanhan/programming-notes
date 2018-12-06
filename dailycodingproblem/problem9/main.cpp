#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    std::vector<int> a = {2, 4, 6, 2, 5};
    std::vector<int> b = {5, 1, 1, 5};

    std::cout << "MaxNonAdjacentSum([2, 4, 6, 2, 5]) = " << MaxNonAdjacentSum(a) << std::endl;
    std::cout << "MaxNonAdjacentSum([5, 1, 1, 5]) = " << MaxNonAdjacentSum(b) << std::endl;
    return 0;
}
