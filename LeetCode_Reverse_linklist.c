#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode*tmp1,*tmp2,*tmp4;
struct ListNode* tail;

/*
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*pre = NULL, *future=NULL;

    if(head==NULL) return NULL;

    while(head->next!=NULL){
        future = head->next;
        head->next = pre;
        pre = head;
        head = future;
    }
    head->next = pre;
    return head;
}
*/
struct ListNode* reverseList(struct ListNode* head) {
    if(!head) return head;

    reverseList1(head, NULL);
    return tail;
}

void reverseList1(struct ListNode* head, struct ListNode* prev)
{
    if(!head){
        tail = prev;
        return;
    }
    reverseList1(head->next, head);
    head->next =  prev;
}

void print(struct ListNode* now){
    while(now->next!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("%d \n",now->val);
    //free(now);
}

int main(){
    tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* head = tmp1;
    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp4;
    tmp4->val = 4;
    tmp4->next = NULL;
    print(head);
    head = reverseList(head);
    print(head);
    return 0;
}
