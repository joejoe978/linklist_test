#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse1(struct ListNode* head){
    struct ListNode *pre=NULL, *future=head->next ;

    if(!head) return NULL;
    while(head->next!=NULL){
        head->next = pre;
        pre = head;
        head = future;
        future = head->next;
    }
     head->next = pre;
     //print(head);
     return head;
}

bool isPalindrome(struct ListNode* head) {
    if(!head || !head->next) return true;   ///**************
    struct ListNode *slow=head, *fast=head , *newhead;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(!fast->next)
        newhead = reverse1(slow->next);  // odd number
    else
        newhead = reverse1(slow->next); // even number

    while(newhead!=NULL){
        if(newhead->val!=head->val) return false;   ///**************
        newhead = newhead->next;
        head = head->next;
    }
    return true;
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
    struct ListNode* head;
    struct ListNode *tmp1,*tmp2,*tmp3,*tmp4,*tmp5;

    tmp1 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp5 =(struct ListNode*)malloc(sizeof(struct ListNode));

    head = tmp1;
    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp3;
    tmp3->val = 3;
    tmp3->next = tmp4;
    tmp4->val = 2;
    tmp4->next = tmp5;
    tmp5->val = 2;
    tmp5->next = NULL;
    print(head);
    //reverse1(head);
    if(isPalindrome(head))
        printf("yes! \n");
    else
        printf("no! \n");

    return 0;
}
