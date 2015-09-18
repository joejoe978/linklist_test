#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size,i;
	printf("please input the size: \n");
	scanf("%d",&size);
	char *A = malloc(sizeof(char)*(size+1));

    printf("please input the string: \n");
    scanf("%s",A);

    for(i=0;i<size;i++){
        if(A[i]%2==1){
            A[i]=A[i];
        }
        if(A[i]%2==0){
            A[i]=(A[i]-'0')/2+'0';
        }
    }
    printf("Your string is : %s \n",A);
	free(A);
	return 0;
}
