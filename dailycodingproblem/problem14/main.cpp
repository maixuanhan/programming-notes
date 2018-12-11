#include <iostream>

using namespace std;

double EstimatePi()
{
    int inner = 0, total = 0;
    for (double x = 0; x < 0.5; x += 0.0001)
    {
        for (double y = 0; y < 0.5; y += 0.0001)
        {
            if (4 * (x * x + y * y) <= 1)
                inner++;
            total++;
        }
    }

    return (int)(4000 * (double)inner / total) / (double)1000;
}

int main()
{
    cout << "Estimated PI is " << EstimatePi() << endl;
    return 0;
}
