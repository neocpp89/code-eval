#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

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

int main()
{
    std::vector<int> primes;
    generate_primes(std::back_inserter(primes), 10000);
    if (primes.size() < 1000) {
        return 1;
    }
    std::cout << std::accumulate(primes.begin(), primes.begin()+1000, 0);
    return 0;
}
