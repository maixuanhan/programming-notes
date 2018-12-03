#include <cassert>
#include <iostream>
#include <functional>

int main()
{
    auto cons = [](int a, int b) {
        auto pair = [&](std::function<int(int, int)> f) {
            return f(a, b);
        };

        return pair;
    };

    auto car = [](std::function<int(std::function<int(int, int)>)> pair) -> int {
        auto first = [](int a, int b) -> int {
            return a;
        };

        return pair(first);
    };

    auto cdr = [](std::function<int(std::function<int(int, int)>)> pair) -> int {
        auto last = [](int a, int b) -> int {
            return b;
        };

        return pair(last);
    };

    assert(car(cons(3, 4)) == 3);
    assert(cdr(cons(3, 4)) == 4);
    std::cout << "All tests PASSED!" << std::endl;

    return 0;
}
