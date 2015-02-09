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
    bool last_was_whitespace = true;
    while (true) { 
        char c;
        f.get(c);
        if (f.fail()) {
            break;
        }
        if (last_was_whitespace) {
            std::cout << static_cast<char>(std::toupper(c));
        } else {
            std::cout << c;
        }
        last_was_whitespace = std::isspace(c);
    }
    return 0;
}
