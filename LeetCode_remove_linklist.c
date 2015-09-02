#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
}*First;

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head==NULL) return;
    if (head->val==val && head->next==NULL){
        head = NULL;
        return ;
    }
    while(head->next != NULL){
        if (head->val == val){
            head->val = head->next->val;
            head->next = head->next->next;
        }
        else
            head = head->next ;
    }

}

int main(){
    struct ListNode *tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmp2a =(struct ListNode*)malloc(sizeof(struct ListNode));

    First = tmp1;
    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp3;
    tmp3->val = 3;
    tmp3->next = tmp4;
    tmp4->val = 4;
    tmp4->next = tmp2a;
    tmp2a->val = 2;
    tmp2a->next = NULL;

    print();
    removeElements(head, 2);
    print();
    return 0;
}

void print(){
    struct ListNode *now = First;
    while(now->next!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("%d \n",now->val);
}
