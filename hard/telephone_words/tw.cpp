#include <iostream>
#include <fstream>
#include <set>
#include <string>

std::string charmap[] =
{
    "0",
    "1",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void build_telephone_words(std::set<std::string> &s, const std::string &prefix, const std::string &remaining)
{
    if (remaining.size() == 0) {
        s.insert(prefix);
        return;
    }
    int c = remaining[0] - '0';
    for (size_t i = 0; i < charmap[c].size(); i++) {
        build_telephone_words(s, prefix + charmap[c][i], remaining.substr(1));
    }
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::set<std::string> s;
        std::string x;
        f >> x;
        if (f.fail()) {
            break;
        }
        build_telephone_words(s, "", x);
        std::set<std::string>::iterator it = s.begin();
        std::cout << *it;
        it++;
        while (it != s.end()) {
            std::cout << ',' << *it;
            it++;
        }
        std::cout << '\n';
    }

    return 0;
}

