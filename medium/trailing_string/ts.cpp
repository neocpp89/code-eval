#include <iostream>
#include <fstream>
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
        size_t p = line.find(',');
        std::string s = line.substr(0,p).c_str();
        std::string ts = line.substr(p+1).c_str();
        int p1 = s.size() - ts.size();
        if (p1 >= 0) {
            bool same = true;
            for (int i = p1; i < s.size(); i++) {
                if (ts[i-p1] != s[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                std::cout << 1 << '\n';
            } else {
                std::cout << 0 << '\n';
            }
        } else {
            std::cout << 0 << '\n';
        }
    }
    return 0;
}

