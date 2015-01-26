#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
        size_t p = line.rfind(',');
        std::string s = line.substr(0,p);
        std::string toremove = line.substr(p+2); // remove leading space
        std::vector<char> v;
        v.reserve(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            bool print = true;
            char c = line[i];
            for (size_t j = 0; j < toremove.size(); j++) {
                if (c == toremove[j]) {
                    print = false;
                    break;
                }
            }
            if (print) {
                v.push_back(c);
            }
        }
        while (v.back() == ' ') {
            v.pop_back();
        }
        for (size_t i = 0; i < v.size(); i++) {
            std::cout << v[i];
        }
        std::cout << '\n';
    }

    return 0;
}

