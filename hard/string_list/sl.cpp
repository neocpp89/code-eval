#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>

void allstr(std::set<std::string> &s, size_t wanted_len, const std::string &current, const std::set<char> &pool)
{
    if (current.size() == wanted_len) {
        s.insert(current);
    } else {
        std::set<char>::iterator it;
        for (it = pool.begin(); it != pool.end(); it++) {
            allstr(s, wanted_len, current + (*it), pool);
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
        std::string::size_type n = line.find(",");
        if (n == std::string::npos) {
            exit(1);
        }
        std::string letters = line.substr(n+1);
        std::string nstr = line.substr(0, n);
        int np = std::atoi(nstr.c_str());
        std::set<char> pool;
        for (size_t i = 0; i < letters.size(); i++) {
            pool.insert(letters[i]);
        }
        if (lines != 0) {
            std::cout << '\n';
        }
        std::set<std::string> s;
        allstr(s, np, "", pool);
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
