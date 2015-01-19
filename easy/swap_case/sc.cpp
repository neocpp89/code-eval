#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    f.seekg(0, std::ios::end);
    size_t s = f.tellg();
    std::vector<char> v(s);
    f.seekg(0, std::ios::beg);
    f.read(&v[0], s);
    for (size_t i = 0; i < s; i++) {
        if (std::isupper(v[i])) {
            v[i]= std::tolower(v[i]);
        } else if(std::islower(v[i])) {
            v[i]= std::toupper(v[i]);
        }
    }
    std::string str(v.data(), s);
    std::cout << str;
    return 0;
}
