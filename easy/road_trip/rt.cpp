#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

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
        std::vector<int> citydists;
        while (true) {
            std::string citypair;
            std::getline(iss, citypair, ';');
            if (iss.fail()) {
                break;
            }
            size_t n = citypair.find_first_of(',');
            int dist = atoi(citypair.substr(n+1).c_str());
            citydists.push_back(dist);
        }
        std::sort(citydists.begin(), citydists.end());
        std::cout << citydists[0];
        for (size_t i = 1; i < citydists.size(); i++) {
            std::cout << ',' << (citydists[i] - citydists[i-1]);
        }
        std::cout << '\n';
    }

    return 0;
}

