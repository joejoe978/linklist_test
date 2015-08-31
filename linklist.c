#include <stdio.h>
#include <string.h>

struct node {
    char name[80];
    struct node *next;
};

int main(void)
{
    struct node x, y, a, b, *head, *curr ;
    strcpy(x.name,"John");
    strcpy(y.name,"Mary");
    strcpy(a.name,"Joe");
    strcpy(b.name,"Ace");

    head = &x;
    //*head = &x ;
    x.next = &y;
    y.next = &a;
    a.next = &b;
    b.next = 0;

    curr = head ;
    while (curr != 0){
        printf("curr = %s \n",curr->name);
        curr = curr->next ;
    }

    printf("curr point to : %X \n", curr);
    printf("head point to : %X \n", head);
    printf("x address = %X \n", &x);
    printf("b address = %X \n", &b);


    return 0;
}
