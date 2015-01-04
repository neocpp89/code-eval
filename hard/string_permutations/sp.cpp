#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <set>

void permute(std::set<std::string> &s, const std::string &str, const std::string &p)
{
    if (str.size() == 0) {
        s.insert(p);
    } else {
        for (size_t i = 0; i < str.size(); i++) {
            std::string nstr(str);
            const char c = nstr[i];
            nstr.erase(nstr.begin() + i);
            permute(s, nstr, p+c);
        }
    }
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    int lines = 0;
    while (true) { 
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        if (lines != 0) {
            std::cout << '\n';
        }
        std::set<std::string> s;
        permute(s, line, "");
        std::set<std::string>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            if (it != s.begin()) {
                std::cout << ',';
            }
            std::cout << *it;
        }
        lines++;
    }
    return 0;
}
