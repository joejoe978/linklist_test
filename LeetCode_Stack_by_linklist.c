#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
int size = 0;
struct ListNode *top=NULL,*tmp1,*tmp2,*tmp3,*tmp4,*tmp2a,*tmp3a,*tmp4a;

void print(struct ListNode* now){
    now = tmp1;
    while(now!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("NULL \n");
    //free(now);
}

void push(int num){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(int));
    node->val = num;
    node->next = top;
    top = node;
    size++;
}

int pop(){
    if(size == 0) return INT_MIN;
    struct ListNode* tmp = top;
    int value;
    value = tmp->val;
    top = tmp->next;
    free(tmp);
    return value;
}

struct ListNode* top(){
    return top;
}

int size(){
    return size;
}

bool empty(){
    return size==0;
}

int main(){
    tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    //tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp3a =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4a =(struct ListNode*)malloc(sizeof(struct ListNode));

    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp3;
    tmp3->val = 2;
    tmp3->next = tmp4;
    tmp4->val = 2;
    tmp4->next = NULL;
    //tmp2a->val = 3;
    //tmp2a->next = NULL;
    //tmp3a->val = 3;
    //tmp3a->next = NULL;
    //tmp4a->val = 3;
    //tmp4a->next = NULL;

    struct ListNode *head = tmp1;

    print(head);
    return 0;
}
