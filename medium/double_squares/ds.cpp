#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

std::map<int, int> prime_factors(int n)
{
    std::map<int, int> pf;
    if (n == 0) {
        return pf;
    }
    while ((n % 2) == 0) {
        pf[2]++;
        n /= 2;
    }
    for (int i = 3; i*i <= n; i += 2) {
        while ((n % i) == 0) {
            pf[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        pf[n]++;
    }
    return pf;
}

inline int intsqrt(int n)
{
    int x = 0;
    int r = n;
    while (std::abs(r - x) > 1) {
        x = r;
        r = (x + n / x) / 2;
    }
    return r;
}

int count_double_squares(int x)
{
    if (x == 0) {
        return 1;
    }
    int c = 0;
    for (int i = 0; 2*i*i < x; i++) {
        int jsq = x - i*i;
        int j = intsqrt(jsq);
        if (j*j == jsq) {
            c++;
        }
    }
    return c;
}

int count_double_squares2(int x)
{
    if (x == 0) { return 1; }
    if (x == 1) { return 1; }
    int r = 0;
    std::map<int, int> p = prime_factors(x);
    int b = 0;
    int a0 = p[2];
    for (std::map<int, int>::iterator it = p.begin(); it != p.end(); it++) {
        int p = it->first;
        int d = it->second;
        if ((p - 3) % 4 == 0) {
            if ((d % 2) != 0) {
                return 0;
            }
        } else if ((p - 1) % 4 == 0) {
            b += (d + 1);
        }
    }
    if ((b % 2) == 0) {
        r = b / 2;
    } else {
        if (a0 % 2 == 0) {
            r = (b - 1) / 2;
        } else {
            r = (b + 1) / 2;
        }
    }
    int sqrtx = std::sqrt(x);
    if (sqrtx * sqrtx == x) {
        r++;
    }
    return r;
}

int B(int x, int y)
{
}

int count_double_squares3(int n)
{
    if (n == 0 || n == 1) { return 1; }
    int x = intsqrt(n);
    int y = 0;
    int c = 0;
    while (x > y) {
        int s = (x*x + y*y);
        if (s < n) {
            y++;
        } else if (s == n) {
            x--;
            y++;
            c++;
        } else { // s > n
            x--;
        }
    }
    return c;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        int x;
        f >> x;
        if (f.fail()) {
            break;
        }
        std::map<int, int> pflist = prime_factors(x);
        /*
        for (std::map<int, int>::iterator it = pflist.begin(); it != pflist.end(); it++) {
            std::cout << it->first << ':' << it->second << ' ';
        }
        std::cout << '\n';
        */
        std::cout << count_double_squares3(x) << '\n';
        //std::cout << x << ' ' << count_double_squares(x) << '|' << count_double_squares2(x) << '\n';
    }
    return 0;
}

