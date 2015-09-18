#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int A[]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

bool search(int line, int start, int end, int val) {
    int i, *a = A+line;
    // int *a = A[line];

    for(i=0;i<5;i++)
        printf(" A[%d]: %d \n",i,a[i]);

    while(start<=end) {
        int i = (start+end)/2;
        printf("i: %d \n",i);
        if(a[i]>val) {
            end = i-1;
        }
        else if(a[i]<val) {
            start = i+1;
        }
        else {
            printf("hi\n");
            return true;
        }
    }
}

int main(){
    int i,j ;
    int *p = A;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%2d ",p[5*i+j]);
        }
        printf(" \n");
    }

    for(i=0;i<5;i++){
        printf(" ---- %d ----",i);
        if(search(i,0,4,30)){
            printf("find at line %d \n",i);
        }
        else
            printf("false!\n");
    }
    return 0;
}
