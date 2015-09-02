#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
}*head;

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(){
    head = NULL;

    struct ListNode *tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    head = tmp1;
    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp3;
    tmp3->val = 3;
    tmp3->next = tmp4;
    tmp4->val = 4;
    tmp4->next = NULL;

    print();
    deleteNode(tmp2);
    print();
    return 0;
}

void print(){
    struct ListNode *now = head;
    while(now->next!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("%d \n",now->val);
}
