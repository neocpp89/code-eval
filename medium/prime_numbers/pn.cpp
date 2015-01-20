#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

std::vector<int> sieve(int m)
{
    std::vector<int> primes; 
    std::vector<bool> mask(m >> 1, true);
    primes.reserve(m >> 1);
    if (m >= 2) {
        primes.push_back(2);
        for (int i = 3; i < m; i += 2) {
            if (mask[(i-3)/2] == false) {
                continue;
            }
            for (int j = i*i; j < m; j += i) {
                if ((j & 1) == 1) {
                    int j_idx = (j - 3) >> 1;
                    mask[j_idx] = false;
                }
            }
        }
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i] == true) {
                int p = 2*i + 3;
                primes.push_back(p);
            }
        }
    }
    return primes;
}

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
        int n;
        f >> n;
        if (f.fail()) {
            break;
        }
        // upto.push_back(n);
        if (n >= 2) {
            std::cout << 2;
            for (int i = 3; i < n; i += 2) {
                if (isprime(i)) {
                    std::cout << ',' << i;
                }
            }
            std::cout << '\n';
        }
    }
    /*
    int max = upto[0];
    for (size_t i = 1; i < upto.size(); i++) {
        if (upto[i] > max) {
            max = upto[i];
        }
    }
    std::vector<int> primes = sieve(max);
    for (size_t i = 0; i < upto.size(); i++) {
        if (upto[i] >= 2) {
            std::cout << primes[0];
            for (size_t j = 1 ; j < primes.size(); j++) {
                if (primes[j] >= upto[i]) {
                    break;
                }
                std::cout << ',' << primes[j];
            }
            std::cout << '\n';
        }
    }
    */
    return 0;
}

