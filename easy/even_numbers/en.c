#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    int iters = 0;
    while (1) {
        int x;
        fscanf(fp, "%d", &x);
        if (feof(fp)) {
            break;
        }
        printf("%d\n", (~x & 1));
        iters++;
    }
    return 0;
}
