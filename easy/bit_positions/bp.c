#include <stdio.h>
#include <stdlib.h>

inline int same_bit(size_t n, int p1, int p2)
{
    return (((n >> (p1-1)) & 1) == ((n >> (p2-1)) & 1));
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    while (1) {
        size_t n;
        int p1,p2;
        fscanf(fp, "%zu,%d,%d", &n, &p1, &p2);
        if (feof(fp)) {
            break;
        }
        if (same_bit(n,p1,p2) == 1) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}

