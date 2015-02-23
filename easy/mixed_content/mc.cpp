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
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::vector<std::string> vs;
        std::vector<int> vn;
        while (true) {
            size_t n1 = line.find(',');
            char c = line[0] - '0';
            if (c > 9 || c < 0) {
                vs.push_back(line.substr(0, n1));
            } else {
                int n = atoi(line.substr(0, n1).c_str());
                vn.push_back(n);
            }
            line = line.substr(n1+1);
            if (n1 == std::string::npos) {
                break;
            }
        }
        if (vs.size() > 0) {
            bool first = true;
            for (size_t i = 0; i < vs.size(); i++) {
                if (!first) {
                    std::cout << ',';
                }
                std::cout << vs[i];
                first = false;
            }
        }
        if (vs.size() > 0 && vn.size() > 0) {
            std::cout << '|';
        }
        if (vn.size() > 0) {
            bool first = true;
            for (size_t i = 0; i < vn.size(); i++) {
                if (!first) {
                    std::cout << ',';
                }
                std::cout << vn[i];
                first = false;
            }
        }
        std::cout << '\n';
    }

    return 0;
}

