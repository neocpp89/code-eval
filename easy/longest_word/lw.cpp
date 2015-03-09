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

    std::string word = "";
    std::string longest = word;
    while (f >> word) {
        if (word.size() > longest.size()) {
            longest = word;
        }
        if (f.peek() == '\n') {
            std::cout << longest << '\n';
            longest = "";
        }
    }

    return 0;
}

