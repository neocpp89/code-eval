#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]);

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        int last_x;
        bool beginning = true;
        int count = 1;
        iss >> last_x;
        while (true) {
            int x;
            iss >> x;
            if (iss.fail()) {
                if (!beginning) {
                    std::cout << ' ';
                }
                std::cout << count << ' ' << last_x;
                break;
            }
            if (x == last_x) {
                count++;
            } else {
                if (!beginning) {
                    std::cout << ' ';
                } else {
                    beginning = false;
                }
                std::cout << count << ' ' << last_x;
                last_x = x;
                count = 1;
            }
        }
        std::cout << '\n';
    }

    return 0;
}

