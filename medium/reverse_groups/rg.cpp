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
        size_t s = line.find(';');
        std::string ss = line.substr(0, s);
        int n = atoi(line.substr(s+1).c_str());
        std::vector<int> A;
        while (true) {
            int idx = ss.find(',');
            if (idx == std::string::npos) {
                break;
            }
            int a = atoi(ss.substr(0, idx).c_str());
            A.push_back(a);
            ss = ss.substr(idx+1);
        }
        int a = atoi(ss.c_str());
        A.push_back(a);
        int x = 0;
        std::cout << A[n-1];
        size_t i;
        for (i = 0; i <= (A.size() - n); i += n) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 && j == 0) { continue; }
                std::cout << ',' << A[i+n-j-1];
            }
        }
        for (; i < A.size(); i++) {
            std::cout << ',' << A[i];
        }
        std::cout << '\n';
    }
    return 0;
}

