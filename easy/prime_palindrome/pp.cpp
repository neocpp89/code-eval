#include <iostream>
#include <vector>
#include <iterator>

template <typename Iterator>
void generate_primes(Iterator a, size_t upto = 1000)
{
    std::vector<bool> is_prime_sieve(upto+1, true);

    is_prime_sieve[0] = false;
    is_prime_sieve[1] = false;

    for (size_t i = 2; i < upto; i++) {
        if (is_prime_sieve[i]) {
            for (size_t j = i*i; j < upto; j += i) {
                is_prime_sieve[j] = false;
            }
        }
    }

    for (size_t i = 1; i < upto; i++) {
        if (is_prime_sieve[i]) {
            *a = i;
            a++;
        }
    }

    return;
}

bool is_palindrome(int num)
{
    int n = num;
    int r = 0;
    while (n != 0) {
        int d = n % 10;
        n = n / 10;
        r = 10 * r + d;
    }

    return (num == r);
}

int main()
{
    std::vector<int> primes;
    generate_primes(std::back_inserter(primes), 1000);
    for (size_t i = primes.size() - 1; i > 0; i--) {
        if (is_palindrome(primes[i])) {
            std::cout << primes[i];
            break;
        }
    }
    return 0;
}
