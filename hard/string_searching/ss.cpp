#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <cstdlib>

bool is_substring(const std::string &s, const std::string &re)
{
    for (size_t i = 0; i < s.size(); i++) {
        int mode = 0; // not in consume mode
        int offset = 0;
        bool found = true;
        for (size_t j = 0; j < re.size(); j++) {
            if (mode == 1) {
                while (i+j+offset < s.size()) {
                    if (s[i+j+offset] == re[j]) {
                        mode = 0;
                        break;
                    }
                    offset++; 
                }
                if (i+j+offset >= s.size()) {
                    found = false;
                    break;
                }
            }
            if (re[j] == '*' && (j == 0 || re[j-1] != '\\')) {
                // match zero or more, so skip this char
                // std::cout << "found * in " << re << '\n';
                mode = 1;
                continue;
            }
            if (re[j] == '\\' && j != re.size() && re[j+1] == '*') {
                // next char is a literal *
                // std::cout << "found literal * in " << re << '\n';
                offset--;
                continue;
            }
            if (re[j] != s[i+j+offset]) {
                // std::cout << re[j] << " != " << s[i+j+offset] << '\n';
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
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
        std::string text = line.substr(0, n);
        std::string searchfor = line.substr(n+1);
        if (is_substring(text, searchfor)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
        // std::cout << text << ':' << searchfor << '\n';
        // std::cout << is_substring(text, searchfor) << '\n';
    }
    return 0;
}
