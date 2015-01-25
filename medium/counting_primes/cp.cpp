#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

bool isprime(int n)
{
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    // std::vector<int> upto;
    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        size_t p = line.find(',');
        int n = std::atoi(line.substr(0,p).c_str());
        int m = std::atoi(line.substr(p+1).c_str());
        int c = 0;
        if (n == 2) {
            c++;
        }
        if (n % 2 == 0) {
            n++;
        }
        if (m % 2 == 0) {
            m--;
        }
        for (int p = n; p <= m; p += 2) {
            if (isprime(p)) {
                c++;
            }
        }
        std::cout << c << '\n';
    }
    return 0;
}

