#include <iostream>
#include <fstream>

int sum_of_digits(int n)
{
    int sod = 0;
    while (n != 0) {
        int d = n % 10;
        n = n / 10;
        sod += d;
    }
    return sod;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    int iters = 0;
    while (true) {
        int n;
        f >> n;
        if (f.fail()) {
            break;
        }
        if (iters != 0) {
            std::cout << '\n';
        }
        std::cout << sum_of_digits(n);
        iters++;
    }

    return 0;
}

