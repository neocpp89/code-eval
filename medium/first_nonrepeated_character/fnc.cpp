#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::map<int, char> m;
        for (size_t n = 0; n < line.size(); n++) {
            m[line[n]]++;
        }
        for (size_t n = 0; n < line.size(); n++) {
            if (m[line[n]] == 1) {
                std::cout << line[n] << '\n';
                break;
            }
        }
    }

    return 0;
}

