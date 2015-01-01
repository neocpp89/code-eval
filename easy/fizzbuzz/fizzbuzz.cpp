#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    int iters = 0;
    while (true) {
        int x, y, n;
        f >> x;
        f >> y;
        f >> n;
        if (f.fail()) {
            break;
        }
        if (iters != 0) {
            std::cout << '\n';
        }
        for (int i = 1; i <= n; i++) {
            if (i % x == 0 && i % y == 0) {
                std::cout << "FB";
            } else if (i % x == 0) {
                std::cout << "F";
            } else if (i % y == 0) {
                std::cout << "B";
            } else {
                std::cout << i;
            }
            if (i != n) {
                std::cout << ' ';
            }
        }
        iters++;
    }

    return 0;
}

