#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        std::vector<int> seq;
        std::set<int> s;
        while (true) {
            int x;
            iss >> x;
            if (s.count(x) == 0) {
                s.insert(x);
                seq.push_back(x);
            } else {
                std::vector<int>::iterator it = seq.end();
                it--;
                while (*it != x) {
                    it--;
                }
                std::cout << x;
                it++;
                while (it != seq.end()) {
                    std::cout << ' ' << *it;
                    it++;
                }
                break;
            }
        }

        std::cout << '\n';
    }

    return 0;
}

