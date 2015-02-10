#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>
#include <utility>
#include <map>

struct comp
{
        bool operator()(const std::pair<char, int> &a, const std::pair<char, int> &b) const
        {
            return (a.second > b.second);
        }
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1]);
    bool last_was_whitespace = true;
    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::map<char, int> m;
        std::vector<std::pair<char, int> > v;
        for (size_t i = 0; i < line.size(); i++) {
            if (std::isalpha(line[i])) {
                m[std::tolower(line[i])]++;
            }
        }
        for (std::map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            v.push_back(*it);
        }
        std::sort(v.begin(), v.end(), comp());
        int beauty = 0;
        for (size_t i = 0; i < v.size(); i++) {
            //std::cout << v[i].first << ',' << v[i].second << '\n';
            beauty += (v[i].second * (26 - i));
        }
        std::cout << beauty << '\n';
    }
    return 0;
}
