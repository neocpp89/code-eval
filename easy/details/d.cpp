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
        size_t cmin = line.size();
        size_t p;
        do {
            p = line.find(',');
            std::string s = line.substr(0, p);
            size_t nc = s.find('Y') - s.rfind('X') - 1;
            if (nc < cmin) {
                cmin = nc;
            }
            line = line.substr(p+1);
        } while (p != std::string::npos);
        std::cout << cmin << '\n';
    }
    return 0;
}
