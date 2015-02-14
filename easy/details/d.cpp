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
        int smin = line.size();
        size_t last_X = 0;
        bool consume_until_comma = false;
        for (size_t i = 0; i < line.size(); i++) {
            char c = line[i];
            if (consume_until_comma && c != ',') {
                continue;
            }

            if (c == ',') {
                consume_until_comma = false;
            } else if (c == 'X') {
                last_X = i;
            } else if (c == 'Y') {
                int s = i - last_X - 1;
                if (s < smin) {
                    smin = s;
                }
                consume_until_comma = true;
            }
        }
        std::cout << smin << '\n';
    }
    return 0;
}
