#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    f.seekg(0, std::ios::end);
    std::cout << f.tellg();
    return 0;
}
