#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

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

int main()
{
    vector<int> a = {3, 4, -1, 1,0,-2,-9,0}; // 2
    vector<int> b = {1, 2, 0};     // 3

    cout << "       FindFirstMissing_mark([3, 4, -1, 1]) = " << FindFirstMissing_mark(a) << endl;
    cout << "FindFirstMissing_reuse_input([3, 4, -1, 1]) = " << FindFirstMissing_reuse_input(a) << endl;
    cout << "       FindFirstMissing_sort([3, 4, -1, 1]) = " << FindFirstMissing_sort(a) << endl << endl;

    cout << "       FindFirstMissing_mark([1, 2, 0]) = " << FindFirstMissing_mark(b) << endl;
    cout << "FindFirstMissing_reuse_input([1, 2, 0]) = " << FindFirstMissing_reuse_input(b) << endl;
    cout << "       FindFirstMissing_sort([1, 2, 0]) = " << FindFirstMissing_sort(b) << endl;

    return 0;
}
