#include <stdio.h>

int main()
{
    unsigned char c = 4 - 7;
    unsigned char d = 4 - 7;

    printf("%u %c \n", c, c);
    printf("%u %c \n", d, d);
    c = ~c + 1;
    d = d * -1;
    printf("%u %c \n", c, c);
    printf("%u %c \n", d, d);

    return 0;
}