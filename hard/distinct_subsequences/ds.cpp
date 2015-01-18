#include <iostream>
#include <fstream>
#include <string>

int num_distinct_subsequences(const std::string &s, const std::string &letters)
{
    if (letters.size() == 0) {
        return 1;
    }

    int c = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == letters[0]) {
            c += num_distinct_subsequences(s.substr(i+1), letters.substr(1));
        }
    }

    return c;
}

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
        std::string::size_type n = line.find(",");
        if (n == std::string::npos) {
            return 1;
        }
        std::string nstr = line.substr(0, n);
        std::string letters = line.substr(n+1);
        std::cout << num_distinct_subsequences(nstr, letters) << '\n';
    }
    return 0;
}
