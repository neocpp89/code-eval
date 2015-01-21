#include <iostream>
#include <fstream>
#include <vector>

size_t powermod(size_t num, size_t power, size_t mod)
{
    const size_t nm0 = num % mod;
    size_t nm = nm0;
    for (int i = 0; i < (power-1); i++) {
        nm = (nm * nm0) % mod;
    }
    return nm;
}

std::vector<size_t> gather_digit_stats(size_t num, size_t power)
{
    const int mod = 10;
    std::vector<size_t> s(10);
    size_t nm0 = num % mod;
    size_t nm = nm0;
    s[nm0]++;
    size_t cycle_len = 0;
    for (size_t i = 0; i < (power-1); i++) {
        nm = (nm * nm0) % mod;
        if (s[nm] != 0) {
            cycle_len = i+1;
            break;
        }
        s[nm]++;
    }
    if (cycle_len != 0) {
        size_t num_cycles = (power / cycle_len);

        for (size_t i = 0; i < s.size(); i++) {
            s[i] *= num_cycles;
        }

        if (power % cycle_len != 0) {
            size_t leftover = (power % cycle_len) - 1;
            nm0 = num % mod;
            nm = nm0;
            s[nm0]++;
            for (size_t i = 0; i < leftover; i++) {
                nm = (nm * nm0) % mod;
                s[nm]++;
            }
        }
    }

    return s;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    /*
    for (size_t i = 1; i < 10; i++) {
        for (size_t j = 1; j < 20; j++) {
            std::cout << powermod(i, j, 10) << '|';
        }
        std::cout << '\n';
    }
    */

    while (true) {
        size_t a, n;
        f >> a;
        f >> n;
        if (f.fail()) {
            break;
        }
        // std::cout << a << ' ' << n;
        std::vector<size_t> ds = gather_digit_stats(a, n);
        std::cout << 0 << ": " << ds[0];
        for (int i = 1; i < ds.size(); i++) {
            std::cout <<  ", " << i << ": " << ds[i];
        }
        std::cout << '\n';
    }

    return 0;
}

