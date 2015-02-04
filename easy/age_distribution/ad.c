#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    while (1) {
        int x;
        fscanf(fp, "%d", &x);
        if (feof(fp)) {
            break;
        }
        if (x < 0 || x > 100) {
            printf("This program is for humans\n");
        } else if (x >= 0 && x <= 2) {
            printf("Still in Mama's arms\n");
        } else if (x >= 3 && x <= 4) {
            printf("Preschool Maniac\n");
        } else if (x >= 5 && x <= 11) {
            printf("Elementary school\n");
        } else if (x >= 12 && x <= 14) {
            printf("Middle school\n");
        } else if (x >= 15 && x <= 18) {
            printf("High school\n");
        } else if (x >= 19 && x <= 22) {
            printf("College\n");
        } else if (x >= 23 && x <= 65) {
            printf("Working for the man\n");
        } else if (x >= 66 && x <= 100) {
            printf("The Golden Years\n");
        }
    }
    return 0;
}
