#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *tmp1,*tmp2,*tmp3,*tmp4,*tmp2a;

/*
struct ListNode* removeElements(struct ListNode* head, int val) {

    if (head==NULL)return NULL;
    if (head->val==val) return removeElements(head->next,val);

    head->next = removeElements(head->next,val);
    return head;
}
*/

struct ListNode *removeElements(struct ListNode *head, int val){
    struct ListNode **list = &head;
    while (*list != NULL){
        print();
        if ((*list)->val == val){
            *list = (*list)->next;
        }
        else{
            list = &((*list)->next);
        }
    }
    return head;
}


void print(struct ListNode* now){
    now = tmp1;
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
    //tmp3 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp4 =(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp2a =(struct ListNode*)malloc(sizeof(struct ListNode));

    tmp1->val = 1;
    tmp1->next = tmp2;
    tmp2->val = 2;
    tmp2->next = tmp4;
    //tmp3->val = 3;
    //tmp3->next = tmp4;
    tmp4->val = 4;
    tmp4->next = tmp2a;
    tmp2a->val = 2;
    tmp2a->next = NULL;

    struct ListNode *head = tmp1;
    removeElements(head, 2);
    //print(head);
    return 0;
}
