#include <iostream>
#include <ios>
#include <fstream>

int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]);

    while (true) {
        int x;
        f >> x;
        if (f.fail()) {
            break;
        }
        if (x < 0 || x > 100) {
            std::cout << "This program is for humans\n";
        } else if (x >= 0 && x <= 2) {
            std::cout << "Still in Mama's arms\n";
        } else if (x >= 3 && x <= 4) {
            std::cout << "Preschool Maniac\n";
        } else if (x >= 5 && x <= 11) {
            std::cout << "Elementary school\n";
        } else if (x >= 12 && x <= 14) {
            std::cout << "Middle school\n";
        } else if (x >= 15 && x <= 18) {
            std::cout << "High school\n";
        } else if (x >= 19 && x <= 22) {
            std::cout << "College\n";
        } else if (x >= 23 && x <= 65) {
            std::cout << "Working for the man\n";
        } else if (x >= 66 && x <= 100) {
            std::cout << "The Golden Years\n";
        }
    }

    return 0;
}

