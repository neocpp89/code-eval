#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


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
        if (line.size() <= 55) {
            std::cout << line << '\n';
        } else {
            std::string sub = line.substr(0, 40);
            size_t p;
            if ((p = sub.rfind(' ')) != std::string::npos) {
                sub = sub.substr(0, p);
            }
            std::cout << sub << "... <Read More>\n"; 
        }
    }
    return 0;
}
