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
        std::istringstream iss(line);
        std::string phrase;
        std::getline(iss, phrase, ',');
        std::string c;
        std::getline(iss, c, ',');
        size_t idx = phrase.find_last_of(c);
        if (idx == phrase.npos) {
            std::cout << "-1\n";
        } else {
            std::cout << idx << '\n';
        }
    }

    return 0;
}

