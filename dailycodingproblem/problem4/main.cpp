#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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

int main()
{
    vector<int> a = {3, 4, -1, 1}; // 2
    vector<int> b = {1, 2, 0};     // 3

    cout << "FindFirstMissing_mark([3, 4, -1, 1]) = " << FindFirstMissing_mark(a) << endl;
    cout << "FindFirstMissing_sort([3, 4, -1, 1]) = " << FindFirstMissing_sort(a) << endl;

    cout << "FindFirstMissing_mark([1, 2, 0]) = " << FindFirstMissing_mark(b) << endl;
    cout << "FindFirstMissing_sort([1, 2, 0]) = " << FindFirstMissing_sort(b) << endl;

    return 0;
}
