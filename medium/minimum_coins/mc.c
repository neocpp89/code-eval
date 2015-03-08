#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2) { return 1; }
    FILE *f = fopen(argv[1], "r");
    while (1) {
        int n;
        if (1 != fscanf(f, "%d", &n)) {
            break;
        }
        int num_coins = n / 5;
        n = n % 5;
        num_coins += n / 3;
        n = n % 3;
        num_coins += n;
        printf("%d\n", num_coins);
    }
    return 0;
}
