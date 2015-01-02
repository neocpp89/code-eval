#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool cmp(const std::string &a, const std::string &b)
{
    return (a.size() >= b.size());
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    std::string line;
    int iter = 0;
    int num_to_print;
    f >> num_to_print;
    std::vector<std::string> s;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        if (line.size() == 0) {
            continue;
        }
        if (iter != 0) {
            std::cout << '\n';
        }
        s.push_back(line);
    }
    std::sort(s.begin(), s.end(), cmp);
    if (num_to_print > 0) {
        std::cout << s[0];
    }
    for (int i = 1; i < num_to_print; i++) {
        std::cout << '\n' << s[i];
    }

    return 0;
}

