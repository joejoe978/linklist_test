#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode *stack ;
    while(head!=NULL){

    }
}

int main(){
    tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2a =(struct ListNode*)malloc(sizeof(struct ListNode));

    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp4;
    tmp4->val = 4;
    tmp4->next = tmp2a;
    tmp2a->val = 2;
    tmp2a->next = NULL;

    return 0;
}
