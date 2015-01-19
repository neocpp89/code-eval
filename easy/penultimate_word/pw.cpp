#include <iostream>
#include <fstream>
#include <sstream>

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
        size_t n1 = line.find_last_of(' ');
        std::string s = line.substr(0, n1);
        size_t n2 = s.find_last_of(' ');
        if (n2 == std::string::npos) {
            std::cout << s << '\n';
        } else {
            std::cout << s.substr(n2+1) << '\n';
        }
    }

    return 0;
}

