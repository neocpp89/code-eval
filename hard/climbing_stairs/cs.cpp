#include <iostream>
#include <fstream>
#include <map>
#include <vector>

struct mpint
{
    std::vector<int> digits;

    mpint(int s)
    {
        while (s > 0) {
            digits.push_back(s % 10);
            s /= 10;
        }
    }

    mpint(const struct mpint &a)
    {
        for (size_t d = 0; d < a.digits.size(); d++) {
            digits.push_back(a.digits[d]);
        }
    }

    struct mpint &operator=(struct mpint temp)
    {
        digits = temp.digits;
        return *this;
    }

    friend struct mpint operator+(struct mpint &a, struct mpint &b);
    friend std::ostream &operator<<(std::ostream &os, const struct mpint &a);
};

struct mpint operator+(struct mpint &a, struct mpint &b)
{
    struct mpint result(a);
    if (b.digits.size() > a.digits.size()) {
        return b+a;
    }
    for (size_t digit = 0; digit < a.digits.size(); digit++) {
        if (digit < b.digits.size()) {
            result.digits[digit] += b.digits[digit];
        }
        if (result.digits[digit] > 9) {
            if (digit < a.digits.size()-1) {
                result.digits[digit+1] += (result.digits[digit] / 10);
                result.digits[digit] -= 10;
            } else {
                result.digits.push_back(result.digits[digit] / 10);
                result.digits[digit] -= 10;
            }
        }
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const struct mpint &a)
{
    for(size_t i = a.digits.size(); i > 0; i--) {
        os << a.digits[i-1];
    }
    return os;
}

int ways_to(int current, int wanted)
{
    if (current > wanted) {
        return 0;
    }
    if (current == wanted) {
        return 1;
    }
    return ways_to(current+1, wanted) + ways_to(current+2, wanted);
}

/*
size_t fib(size_t n)
{
    if (n == 1) { return 1; }
    size_t a = 0;
    size_t b = 1;
    n--;
    while (n > 0) {
        size_t t = b;
        b = b + a;
        a = t;
        n--;
    }
    return b;
}
*/

struct mpint fib(size_t n)
{
    struct mpint a(0);
    struct mpint b(1);
    if (n == 1) { return b; }
    n--;
    while (n > 0) {
        struct mpint t(b);
        b = b + a;
        a = t;
        n--;
    }
    return b;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        int x;
        f >> x;
        if (f.fail()) {
            break;
        }
        //std::cout << ways_to(0, x) << '\n';
        std::cout << fib(x+1) << '\n';
    }

    return 0;
}

