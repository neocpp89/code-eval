#include <iostream>
#include <ios>
#include <fstream>

int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
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
        std::cout << !(x & 1) << '\n';
    }

    return 0;
}

