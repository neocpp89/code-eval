#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

struct pt {
    int x;
    int y;
};

struct rect {
    struct pt upper_left;
    struct pt lower_right;
};

std::ostream &operator<<(std::ostream &os, const rect &a)
{
    os << "rect { upper-left: (" << a.upper_left.x << ", " << a.upper_left.y << "), lower-right: (" << a.lower_right.x << ", " << a.lower_right.y << ") }";
    return os;
}

bool overlapping(rect &a, rect &b)
{
    if ((a.upper_left.x > b.lower_right.x) ||
        (b.upper_left.x > a.lower_right.x)) {
        return false;
    }

    if ((a.upper_left.y < b.lower_right.y) ||
        (b.upper_left.y < a.lower_right.y)) {
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    std::string line;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::string ss(line);
        int X[8];
        for (size_t i = 0; i < 8; i++) {
            int idx = ss.find_first_of(',');
            int a = atoi(ss.substr(0, idx).c_str());
            X[i] = a;
            ss = ss.substr(idx+1);
        }
        rect A = { {X[0], X[1]}, {X[2], X[3]} };
        rect B = { {X[4], X[5]}, {X[6], X[7]} };
        //std::cout << A << '|' << B << '\n';
        if (overlapping(A, B)) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }
    }
    return 0;
}

