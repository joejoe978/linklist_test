#include <stdio.h>
#include <stdlib.h>

void myitoa(int num,char*ans){
    int i=0 , flag = 1;
    if (num<0){
        num = -num;
        flag = 0;
    }
    while(num!=0){
        ans[i] = num%10 + '0';
        num = num / 10;
        i++;
    }
    if(!flag)
        ans[i++] = '-';
    ans[i] = '\0';
    printf("--------- %s\n",ans);
    reverse_char(ans);
}

int myatoi(char* s){
    int sum = 0, i;
    for(i=0;s[i]!='\0';i++){
        sum = sum*10 + s[i]-'0';
    }
    return sum;
}

void reverse_char(char *s){
    int i,strlen=0 ;
    //printf("char : %s\n",s);
    while(s[strlen]!='\0'){
        strlen++;
    }
    //printf("strlen: %d\n",strlen);

    for(i=0;i<(strlen/2);i++){
        s[strlen]=s[i];
        s[i]=s[strlen-i-1];
        s[strlen-i-1]=s[strlen];
    }
    s[strlen] = '\0';
    //printf("string: %s\n",s);
}

int main(){
    //char s[] = "12345";
    char *s = "12345";
    printf("s[2]: %c\n",*(s+2));
    printf("s[2]: %c\n",s[2]);

    int i = myatoi(s);
    printf("After atoi: %d\n",i);
    char *a = (char *)malloc(50);
    //integer to string
    myitoa(i,a);
    //12345
    printf("After itoa: %s\n",a);
    //myitoa(-i,a);
    //-12345
    //printf("%s\n",a);
    return 0;
}



