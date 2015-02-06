#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

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
        int upper = 0;
        int lower = 0;
        for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == '\n') {
            upper = 0;
            lower = 0;
        } else if (std::isupper(c)) {
            upper++;
        } else if (std::islower(c)) {
            lower++;
        }
        }
        const double pu = static_cast<double>(100*upper)/(upper+lower);
        const double pl = static_cast<double>(100*lower)/(upper+lower);
        std::cout << std::fixed << std::setprecision(2) << "lowercase: " << pl << " uppercase: " << pu << '\n';
    }
    return 0;
}

