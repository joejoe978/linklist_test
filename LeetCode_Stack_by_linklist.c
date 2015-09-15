#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
}*top;

void print(){
    struct ListNode* now = top;
    while(now!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("NULL \n");
    //free(now);
}

bool empty(){
    return top==NULL;
}

void push(int num){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(int));
    node->val = num;
    node->next = top;
    top = node;
}

int pop(){
    if(empty()) return INT_MIN;
    struct ListNode* tmp = top;
    int value;
    value = tmp->val;
    top = tmp->next;
    free(tmp);
    return value;
}

struct ListNode* findtop(){
    return top;
}

int main(){
    push(1);
    push(2);
    print();
    printf("now pop:%d \n",pop());
    print();
    printf("now top:%d \n",findtop()->val);
    printf("now pop:%d \n",pop());
    printf(empty() ? "true" : "false");
    printf(" \n");
    printf("now pop:%d \n",pop());
    return 0;
}
