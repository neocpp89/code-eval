#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    while (true) { 
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        int first = 0;
        while (true) {
            std::string word;
            iss >> word;
            if (iss.fail()) {
                break;
            }
            word[0] = std::toupper(word[0]);
            if (first != 0) {
                std::cout << ' ';
            }
            std::cout << word;
            first++;
        }
        std::cout << '\n';
    }
    return 0;
}
