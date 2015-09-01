#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *Q;
int Head=0, Tail=0, Number_of_Items = 0,n;


main(){
    int i,tmp1,tmp2 ;
    printf("input array size: ");
    scanf("%d",&n);

    Q =(int*)malloc(n*sizeof(int));

    for(i=1;i<=n;i++){
        enq(i);
    }

    for(i=0;i<n;i++){
        printf(" %d ",Q[i]);
    }
    printf("Head: %d, Tail: %d \n",Head,Tail);

    for(i=0;i<n-1;i++){
        tmp1 = deq();
        tmp2 = deq();
        deq();
        enq(tmp1);
        enq(tmp2);
    }

    printf("the final number is : %d\n",Q[Head]);
    return 0;
}


void enq(int x){
    if(Number_of_Items == 0){
        Q[0]= x;
        Head = 0;
        Tail = 0;
    }
    else{
        Q[(Tail+1)%n]=x;
        Tail=(Tail+1)%n;
    }
    Number_of_Items++;
    //printf("enq(%d), Head:%d, Tail:%d \n",x,Head,Tail);
}

int deq(){
    int del;
    del = Q[Head];
    Head = (Head+1)%n ;
    Number_of_Items--;
    //printf("delete: %d, Head: %d, Tail: %d \n",del,Head,Tail);
    return del;
}
