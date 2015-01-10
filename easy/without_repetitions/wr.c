#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    if (argc != 2) { return 1; }
    int fp = open(argv[1], O_RDONLY);
    #define BLEN 32
    char buf[BLEN];
    char last;
    int i;
    int s;
    read(fp, &last, 1);
    printf("%c", last);
    while ((s = read(fp, buf, BLEN)) != 0) {
        for(i = 0; i < s; i++) {
            if (buf[i] != last) {
                printf("%c", buf[i]);
            }
            last = buf[i];
        }
    }
    close(fp);
    return 0;
}
