#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int *base;
    int *top;
    int size;
    int min;
    int min_num;
    int max_size;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->base = (int*)malloc(sizeof(int)*maxSize);
    stack->top = stack->base;
    stack->size = 0;
    stack->min = INT_MAX;
    stack->min_num = 0;
    stack->max_size = maxSize;
}

void minStackPush(MinStack *stack, int element) {
    if(stack->max_size == stack->size) return NULL;
    *(stack->top) = element;
    stack->top += 1;
    if(element < stack->min){
        stack->min = element;
        stack->min_num = 1;
    }
    else if(element == stack->min){
        stack->min_num ++;
    }
    stack->size += 1;
}

void minStackPop(MinStack *stack) {
    if(stack->size == 0) return NULL;
    stack->top--;
    int cur = *(stack->top);
    stack->size--;
    //printf("now cur:%d, min_num:%d \n",cur,stack->min_num);

    if(cur == stack->min && stack->min_num > 1){
        stack->min_num -= 1;
    }
    else if(cur == stack->min && stack->min_num == 1){
        int i=0 , min = INT_MAX, min_num = 1;
        for(i=0;i<stack->size;i++){
            if(stack->base[i] < min){
                min = stack->base[i];
                min_num = 1;
            }
            else if(stack->base[i] == min){
                min_num ++;
            }
        }
        stack->min = min;
        stack->min_num = min_num;
    }
}

int minStackTop(MinStack *stack) {
    return *(stack->top -1);
}

int minStackGetMin(MinStack *stack) {
    return stack->min;
}

void minStackDestroy(MinStack *stack) {
    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
}

void print(MinStack *stack){
    int i,top,min_num,min;
    for(i=0;i<(stack->size);i++){
        printf("stack[%d]: %d ",i,stack->base[i]);
    }
    printf(" over \n");
    printf("min_num : %d ",stack->min_num);
    top = minStackTop(stack);
    printf("top: %d ",top);
    min = minStackGetMin(stack);
    printf("min: %d\n ",min);
    printf("-----------------\n");
}

int main(){
    int max_num = 5, min = 0, top;
    int *stack = (int*)malloc(sizeof(int)*max_num);
    minStackCreate(stack,max_num);

    minStackPush(stack,2);
    minStackPush(stack,0);
    minStackPush(stack,3);
    minStackPush(stack,0);
    min = minStackGetMin(stack);
    printf("min: %d\n",min);

    minStackPop(stack);
    print(stack);
    min = minStackGetMin(stack);
    printf("min: %d\n",min);


    minStackPop(stack);
    print(stack);
    min = minStackGetMin(stack);
    printf("min: %d\n",min);

    minStackPop(stack);
    print(stack);
    min = minStackGetMin(stack);
    printf("min: %d\n",min);

    minStackDestroy(stack);

    return 0;
}
