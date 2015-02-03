#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::string s;
        std::vector<int> v;
        while (true) {
            f >> s;
            if (f.fail()) {
                return 0;
            }
            if (s == "|") {
                break;
            }
            v.push_back(atoi(s.c_str()));
        }
        for (size_t i = 0; i < v.size(); i++) {
            int vv;
            f >> vv;
            v[i] *= vv;
        }
        if (v.size() > 0) {
            std::cout << v[0];
            for (size_t i = 1; i < v.size(); i++) {
                std::cout << ' ' << v[i];
            }
        }
        std::cout << '\n';
    }

    return 0;
}

