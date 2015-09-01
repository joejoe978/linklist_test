#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next ;
}node;

node *head;

int main(){

    head = NULL ;
    insert(0);
    insert(1);
    insert(4);
    insert(2);
    print();
    delete(2);
    print();
    delete(5);
    delete(1);
    print();
    delete(0);
    print();
    delete(2);
    delete(4);
    print();
    return 0;

}

void insert(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL || head->data >= x){
        newNode->next = head ;
        head = newNode;
    }
    else{
        node *currNode = (node*)malloc(sizeof(node));
        currNode = head;

        while(1){
            if(currNode->next == NULL){
                currNode->next = newNode;
                break;
            }
            else if((currNode->next)->data >= newNode->data){
                newNode->next = currNode->next;
                currNode->next = newNode;
                break;
            }
            else{
                currNode = currNode->next;
            }
        }
    }
}

void delete(int x){
    node *tmp = (node*)malloc(sizeof(node));

    if (head->data == x){
        tmp = head;
        head = head->next;
        free(tmp);
    }
    else{
        node *curr = (node*)malloc(sizeof(node));
        curr = head;

        while(curr->next != NULL){
            if((curr->next)->data == x){
                tmp = curr->next;
                curr->next = tmp->next ;
                free(tmp);
                return ;
            }
            else{
                curr = curr->next;
            }
        }
        printf("Search down! There is no data %d! \n",x);
    }
}

void print(){
    node *curr = (node*)malloc(sizeof(node));
    curr = head;

    if(curr == NULL)
        printf("There is no data!\n");
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf(" \n");
}