#include <iostream>
#include <fstream>
#include <set>
#include <cmath>

int sum_sq_digits(int n)
{
    int d = 0;
    int r = 0;
    while (n != 0) {
        d = n % 10;
        n /= 10;
        r += (d * d);
    }
    return r;
}

bool ishappy(int n)
{
    std::set<int> s;
    s.insert(n);
    bool happy = true;
    while (n != 1) {
        n = sum_sq_digits(n);
        if (s.count(n) != 0) {
            happy = false;
            break;
        }
        s.insert(n);
    }
    return happy;
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
        if (ishappy(x)) {
            std::cout << "1\n";
        } else {
            std::cout << "0\n";
        }
    }

    return 0;
}

