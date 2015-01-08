#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

int derpmod(int n, int m)
{
    while (n >= m) {
        n -= m;
    }
    return n;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        std::string ns;
        std::getline(iss, ns, ',');
        std::string ms;
        std::getline(iss, ms, ',');
        std::cout << derpmod(atoi(ns.c_str()), atoi(ms.c_str())) << '\n';
    }

    return 0;
}

