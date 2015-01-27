#include <iostream>
#include <fstream>
#include <cmath>

bool isvalid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void print_knight_moves(std::ostream &os, int x, int y)
{
    bool printed = false;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if ((std::abs(i)+std::abs(j)) != 3) {
                continue;
            }
            if (isvalid(x+i, y+j)) {
                if (printed) {
                    os << ' ';
                } else {
                    printed = true;
                }
                os << static_cast<char>(x+i+'a') << static_cast<char>(y+j+'1');
            }
        }
    }
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file
    while (true) {
        std::string s;
        f >> s;
        if (f.fail()) {
            break;
        }
        int x = s[0]-'a';
        int y = s[1]-'1';
        print_knight_moves(std::cout, x, y);
        std::cout << '\n';
    }
    return 0;
}

