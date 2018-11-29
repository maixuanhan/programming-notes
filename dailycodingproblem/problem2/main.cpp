#include <iostream>
#include <vector>

using namespace std;

#define CHECK_SPECIAL_CASES(a)        \
    do                                \
    {                                 \
        if (a.size() == 0)            \
            return vector<int>();     \
                                      \
        if (a.size() == 1)            \
            return vector<int>(1, 0); \
    } while (false)

vector<int> CalculateProduct_withDivision(const vector<int> &array)
{
    CHECK_SPECIAL_CASES(array);

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

vector<int> CalculateProduct_withoutDivision(const vector<int> &array)
{
    CHECK_SPECIAL_CASES(array);

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

void PrintArray(const vector<int> &array)
{
    cout << '[';
    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << ", ";
    }
    cout << ']' << endl;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5}; // output should be [120, 60, 40, 30, 24]

    cout << "CalculateProduct_withDivision() : \n";
    PrintArray(CalculateProduct_withDivision(a));

    cout << "CalculateProduct_withoutDivision() : \n";
    PrintArray(CalculateProduct_withoutDivision(a));

    return 0;
}
