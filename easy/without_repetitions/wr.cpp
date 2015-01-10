#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1]);
    std::string line;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        if (line.size() > 0) {
            char s = line[0]; 
            std::cout << s;
            for (size_t i = 1; i < line.size(); i++) {
                if (line[i] != s) {
                    std::cout << line[i];
                }
                s = line[i];
            }
        }
        std::cout << '\n';
    }
    return 0;
}
