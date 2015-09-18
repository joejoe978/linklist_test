#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[30] = "to harp on ";
    char t[30] = "the same string";

    strcat(s, t);

    printf("%s\n", s);

    return 0;
}
