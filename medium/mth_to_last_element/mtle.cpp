#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    std::string line;
    int iter = 0;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        if (line.size() == 0) {
            continue;
        }
        std::istringstream ss(line);
        std::vector<std::string> c;
        while (true) {
            std::string cc;
            ss >> cc;
            if (ss.fail()) {
                break;
            }
            c.push_back(cc);
        }
        int m = std::atoi(c.back().c_str());
        int idx = c.size()-m-1;
        if (idx < 0 || idx >= c.size()) {
            continue;
        }
        if (iter != 0) {
            std::cout << '\n';
        }
        std::cout << c[idx];
        iter++;
    }

    return 0;
}

