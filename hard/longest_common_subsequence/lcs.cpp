#include <iostream>
#include <fstream>
#include <string>

std::string find_lcs(const std::string &s1, const std::string &s2)
{
    std::string best = "";
    for (size_t i = 0; i < s1.size(); i++) {
        std::string s;
        std::string s2s = s2;
        size_t n = s2s.find_first_of(s1[i]);
        if (n != std::string::npos) {
            s += s2s[n];
            s2s = s2s.substr(n+1);
            s += find_lcs(s1.substr(i+1), s2s);
        }
        if (s.size() > best.size()) {
            best = s;
        }
    }
    return best;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]);

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        size_t n = line.find(';');
        std::cout << find_lcs(line.substr(0,n), line.substr(n+1)) << '\n';
    }

    return 0;
}

