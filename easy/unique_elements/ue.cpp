#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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
        size_t p1 = line.find_first_of(',');
        int last = atoi(line.substr(0, p1).c_str());
        std::cout << last;
        line = line.substr(p1+1);
        while (true) {
            size_t n1 = line.find_first_of(',');
            int n = atoi(line.substr(0, n1).c_str());
            if (last != n) {
                std::cout << ',' << n;
                last = n;
            }
            line = line.substr(n1+1);
            if (n1 == std::string::npos) {
                break;
            }
        }
        std::cout << '\n';
    }

    return 0;
}

