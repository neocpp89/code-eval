#include <iostream>
#include <fstream>
#include <map>
#include <vector>

template <typename T>
T fib(size_t n)
{
    T a(0);
    if (n == 0) { return a; }
    T b(1);
    if (n == 1) { return b; }
    n--;
    while (n > 0) {
        T t(b);
        b = b + a;
        a = t;
        n--;
    }
    return b;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        int x;
        f >> x;
        if (f.fail()) {
            break;
        }
        std::cout << fib<size_t>(x) << '\n';
    }

    return 0;
}

