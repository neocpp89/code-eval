#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    while (true) {
        int n;
        f >> n;
        if (f.fail()) {
            break;
        }
        int num_coins = n / 5;
        n = n % 5;
        num_coins += n / 3;
        n = n % 3;
        num_coins += n;
        std::cout << num_coins << '\n';
    }
    return 0;
}

