#include <algorithm>
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
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        size_t s = line.find_first_of(';');
        std::string ss = line.substr(s+1);
        int n = atoi(line.substr(0, s).c_str());
        std::vector<int> A(n);
        for (size_t i = 0; i < n; i++) {
            int idx = ss.find_first_of(',');
            int a = atoi(ss.substr(0, idx).c_str());
            A[i] = a;
            ss = ss.substr(idx+1);
        }
        int x = 0;
        for (size_t i = 0; i < A.size(); i++) {
            x += (A[i] - i);
        }
        std::cout << (n+x-1) << '\n';
    }
    return 0;
}

