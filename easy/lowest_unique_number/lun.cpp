#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
        std::istringstream iss(line);
        std::vector<int> picked(9, 0);
        std::vector<int> player;
        while (true) {
            int x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            picked[x-1]++;
            player.push_back(x);
        }
        bool unique = false;
        for (size_t i = 0; i < 8; i++) {
            if (picked[i] == 1) {
                for (size_t j = 0; j < player.size(); j++) {
                    if (player[j] == i+1) {
                        std::cout << j+1 << '\n';
                        unique = true;
                        break;
                    }
                }
            }
            if (unique) {
                break;
            }
        }
        if (!unique) {
            std::cout << "0\n";
        }
    }

    return 0;
}

