#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
        size_t n1 = line.find('|');
        std::string s = line.substr(0, n1);
        std::istringstream iss(line.substr(n1+1));
        while (true) {
            int x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            std::cout << s[x-1];
        }
        std::cout << '\n';
    }
    return 0;
}

