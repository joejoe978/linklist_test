#include <stdio.h>

int main(void) {
	char N[4];
	int i;
	scanf("%s",N);
	for(i=0;i<3;i++){
        N[i]=N[i]+16;
        if(N[i]==64) N[i]=74;
	}
	printf("%s",N);
	return 0;
}
