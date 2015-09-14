#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *tmp1,*tmp2,*tmp3,*tmp4,*tmp2a,*tmp3a,*tmp4a;


void print(struct ListNode* now){
    now = tmp1;
    while(now!=NULL){
        printf("%d -> ",now->val);
        now = now->next;
    }
    printf("NULL \n");
    //free(now);
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return NULL;

    while(head->next!=NULL){
        if(head->val == head->next->val){
            struct ListNode* trash;
            trash = head->next;
            head->next = trash->next;
            free(trash);
            continue;
        }
        head = head->next;
    }

    //print(head);
    return head;
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

    head = deleteDuplicates(head);
    print(head);
    return 0;
}
