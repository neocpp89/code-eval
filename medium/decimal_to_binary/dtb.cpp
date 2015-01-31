#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    while (true) {
        size_t x;
        f >> x;
        if (f.fail()) {
            break;
        }
        std::vector<char> v;
        if (x == 0) {
            std::cout << "0\n";
            continue;
        }
        while (x > 0) {
            v.push_back('0' + (x & 1));
            x >>= 1;
        }
        while (!v.empty()) {
            std::cout << v.back();
            v.pop_back();
        }
        std::cout << '\n';
    }
    return 0;
}

