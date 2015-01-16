#include <stdio.h>
#include <stdlib.h>

inline int intsqrt(int n)
{
    int r = 0;
    int rnew = n;

    while (r != rnew) {
        r = rnew;
        rnew =  (r + n / r) / 2;
    }
    return r;
}

inline int int_dist(int x1, int y1, int x2, int y2)
{
    const int dx = x1 - x2;
    const int dy = y1 - y2;
    const int ds_sq = dx*dx + dy*dy;
    return intsqrt(ds_sq);
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    while (1) {
        int x1, y1, x2, y2;
        int r;
        r = fscanf(fp, "(%d, %d) (%d, %d)\n", &x1, &y1, &x2, &y2);
        // printf("r:%d\n", r);
        if (r != 4) {
            break;
        }
        printf("%d\n", int_dist(x1, y1, x2, y2));
    }
    return 0;
}

