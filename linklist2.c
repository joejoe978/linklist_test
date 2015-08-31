#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MALLOC(p,s)\
    if ( !(p = malloc(s))){ \
        fprintf(stderr,"Insufficient memory!"); \
        exit(EXIT_FAILURE); \
    }

struct Node {
    int id;
    struct Node *next;
}*head;

typedef struct{
    int i;
    float PI;
    struct rec *next;
}rec;


int main(void)
{
    head = NULL ;
    insert(1);
    insert(3);
    insert(5);
    insert(7);
    insert(9);
    print();
    delete(7);
    delete(3);
    print();
    return 0;
}

void insert(int new){
    struct Node *tmp ;
    //struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));

    /*
    if ( !(tmp = malloc(sizeof(struct Node)))){
        fprintf(stderr,"Insufficient memory!");
        exit(EXIT_FAILURE);
    }
    */

    /*
    if  (tmp = (struct Node*)malloc(sizeof(struct Node)) == NULL){
        fprintf(stderr, "Insufficient memory!");
        exit(EXIT_FAILURE);
    }
    */

    MALLOC(tmp,sizeof(struct Node));

    tmp->id = new ;
    tmp->next = NULL ;

    if (head == NULL)
        head = tmp ;
    else {
        struct Node *curr ;
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = tmp;
    }
}

void delete(int old){
    struct Node *pre ;
    MALLOC(pre,sizeof(struct Node));

    pre->next = head;
    while((pre->next)->id != old){
        pre = pre->next;
    }
    struct Node *tmp = pre->next ;
    pre->next = tmp->next;
    free(tmp);
}

void print(){
    struct Node *now;
    MALLOC(now,sizeof(struct Node));

    now = head ;
    while(now->next != NULL){
        printf("%d -> ",(*now).id);
        now = now->next;
    }
    printf("%d  \n",(*now).id);
    printf("over \n");
}

