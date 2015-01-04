#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

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
        if (lines != 0) {
            std::cout << '\n';
        }
        int alphac = 0;
        for (size_t i = 0; i < line.size(); i++) {
            const char c = line[i];
            if (std::isalpha(c)) {
                if (alphac & 1) {
                    std::cout << (char)std::tolower(c);
                } else {
                    std::cout << (char)std::toupper(c);
                }
                alphac++;
            } else {
                std::cout << c;
            }
        }
        lines++;
    }
    return 0;
}
