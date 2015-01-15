#include <stdio.h>
#include <stdlib.h>

int is_armstrong(int n)
{
    int len = 0;
    int nc = n;
    int nf = n;
    while (nc > 0) {
        nc /= 10;
        len++;
    }
    int power_digit_sum = 0;
    while (n > 0) {
        int d = n % 10;
        n /= 10;
        int pd = 1;
        int i;
        for (i = 0; i < len; i++) {
            pd *= d;
        }
        power_digit_sum += pd;
    }
    return (power_digit_sum == nf);
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    while (1) {
        int x;
        fscanf(fp, "%d", &x);
        if (feof(fp)) {
            break;
        }
        if (is_armstrong(x)) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}

