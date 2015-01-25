#include <iostream>
#include <fstream>

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
        int count = 0;
        while (x != 0) {
            if ((x & 1) == 1) {
                count++;
            }
            x >>= 1;
        }
        std::cout << count << '\n';
    }

    return 0;
}

