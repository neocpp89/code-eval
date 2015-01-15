#include <stdio.h>
#include <stdlib.h>

size_t fib(size_t n)
{
    size_t a = 0;
    if (n == 0) { return a; }
    size_t b = 1;
    if (n == 1) { return b; }
    n--;
    while (n > 0) {
        size_t t = b;
        b = b + a;
        a = t;
        n--;
    }
    return b;
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    while (1) {
        size_t x;
        fscanf(fp, "%zu", &x);
        if (feof(fp)) {
            break;
        }
        printf("%zu\n", fib(x));
    }
    return 0;
}

