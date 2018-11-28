#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

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

int main()
{
    vector<int> a = {10, 15, 3, 7};
    int n = 17;

    cout << "CheckArray_sort() = " << CheckArray_sort(a, n) << endl;
    cout << "CheckArray_map() = " << CheckArray_map(a, n) << endl;

    return 0;
}
