#include <iostream>
#include <fstream>
#include <map>

inline void count_digits(std::map<int, int> &m, int n, int &nd)
{
    nd = 0;
    while (n != 0) {
        m[n % 10]++;
        n /= 10;
        nd++;
    }
    return;
}

inline bool is_self_describing(std::map<int, int> &m, int n, int nd)
{
    int pos = nd-1;
    while (n != 0) {
        if (m[pos] != n % 10) {
            return false;
        }
        n /= 10;
        pos--;
    }
    return true;
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
        std::map<int, int> digit_count; //defaults to zero with new key.
        int num_digits;
        count_digits(digit_count, x, num_digits);
        if (is_self_describing(digit_count, x, num_digits)) {
            std::cout << "1\n";
        } else {
            std::cout << "0\n";
        }
    }

    return 0;
}

