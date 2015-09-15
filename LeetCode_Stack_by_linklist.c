#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
}*top;
int size = 0;


void print(){
    struct ListNode* now = top;
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
    size--;
    return value;
}

struct ListNode* findtop(){
    return top;
}

int findsize(){
    return size;
}

bool empty(){
    return size==0;
}

int main(){
    push(1);
    push(2);
    print();
    printf("now pop:%d \n",pop());
    print();
    printf("now size:%d \n",findsize());
    printf("now top:%d \n",findtop()->val);
    printf(empty() ? "true" : "false");
    return 0;
}
