#include <iostream>
#include <fstream>
#include <utility>

template <typename Integral>
Integral reverse(Integral num)
{
    Integral n = num;
    Integral r = 0;
    while (n != 0) {
        Integral d = n % 10;
        n = n / 10;
        r = 10 * r + d;
    }

    return r;
}

template <typename Integral>
bool is_palindrome(Integral n)
{
    Integral r = reverse(n);
    return (n == r);
}


std::pair<int, size_t> reverse_and_add(size_t starting, const size_t maxit = 100)
{
    int iters = 0;
    size_t n = starting;
    do {
        if(is_palindrome(n)) {
            return std::make_pair(iters, n);
        } else {
            n += reverse(n);
            iters++;
        }
    } while (iters <= maxit);

    return std::make_pair(iters, n);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    int iters = 0;
    while (true) {
        int n;
        f >> n;
        if (f.fail()) {
            break;
        }
        if (iters != 0) {
            std::cout << '\n';
        }
        std::pair<int, size_t> a = reverse_and_add(n);
        std::cout << a.first << ' ' << a.second;
        iters++;
    }

    return 0;
}

