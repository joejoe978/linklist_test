#include <stdio.h>
#include <stdlib.h>
#include "aa.c"

extern int x;

void test1() {
    int x = 11;
    printf("test1():%d\n", x);
}

void test2() {
    x = 12;
    printf("test2():%d\n", x);
}

int main(int argc, char** argv) {
    printf("main():%d\n", x); //办x=1
    aa_test(); //办x=1
    test1(); //test1()跋办x=11
    aa_test(); //办x=1
    test2(); //办x=12
    aa_test(); //办x=12
    printf("main():%d\n", x); //办x=12
    return (0);
}
