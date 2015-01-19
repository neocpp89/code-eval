#include <iostream>
#include <fstream>
#include <string>

const std::string digits[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

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
        while (true) {
            size_t n1 = line.find_first_of(';');
            std::string d = line.substr(0, n1);
            for (size_t i = 0; i < 10; i++) {
                if (d == digits[i]) {
                    std::cout << i;
                    break;
                }
            }
            line = line.substr(n1+1);
            if (n1 == std::string::npos) {
                break;
            }
        }
        std::cout << '\n';
    }

    return 0;
}

