#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <numeric>

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
        std::vector<int> A;
        while (true) {
            int idx = line.find(',');
            if (idx == std::string::npos) {
                break;
            }
            int a = atoi(line.substr(0, idx).c_str());
            A.push_back(a);
            line = line.substr(idx+1);
        }
        int a = atoi(line.c_str());
        A.push_back(a);

        int max = A[0];
        for (size_t i = 1; i <= A.size(); i++) {
            int start = std::accumulate(A.begin(), A.begin() + i, 0);
            if (start > max) {
                max = start;
            }
            for (size_t j = 0; (i + j) < A.size(); j++) {
                start += A[j+i];
                start -= A[j];
                if (start > max) {
                    max = start;
                }
            }
        }
        /*
        for (size_t i = 0; i < A.size(); i++)
            std::cout << A[i] << '|';
        */
        std::cout << max << '\n';
    }
    return 0;
}

