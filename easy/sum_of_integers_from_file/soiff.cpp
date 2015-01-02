#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    int running = 0;
    while (true) {
        int x;
        f >> x;
        if (f.fail()) {
            break;
        }
        running += x;
    }
    std::cout << running;

    return 0;
}

