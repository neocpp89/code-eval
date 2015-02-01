#include <iostream>

int main()
{
    unsigned int s = 0xDEADBEEF;
    unsigned char *c = reinterpret_cast<unsigned char *>(&s);
    if (c[0] == 0xDE) {
        std::cout << "BigEndian\n";
    } else if (c[0] == 0xEF) {
        std::cout << "LittleEndian\n";
    } else {
        std::cout << std::hex << static_cast<int>(c[0]) << ": Unknown endianness.\n";
    }
    return 0;
}
