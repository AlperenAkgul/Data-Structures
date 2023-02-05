#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 3

struct node{
    int data;
    struct node *next;
};

typedef struct{
    int cnt;
    struct node *top;
}stack;

void initialization(stack *stk){
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int c){
    if(stk->cnt == STACK_SIZE){
        printf("\nThe Stack is Full\n");
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(stack *stk){
    if(stk->cnt == 0){
        printf("\nThe Stack is Empty\n");
        return -1;
    }
    else{
        int x = stk->top->data;
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt--;
        return x;
    }
}

void print(stack *stk){
    if(stk->cnt == 0){
        printf("The Stack is Empty");
    }
    else{
        struct node *temp = stk->top;
        while(temp != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    stack stk;
    initialization(&stk);
    push(&stk, 4);
    push(&stk, 14);
    push(&stk, 41);
    push(&stk, 6);
    printf("%d \t", pop(&stk));
    printf("%d \t", pop(&stk));
    printf("%d \t", pop(&stk));
    printf("%d \t", pop(&stk));
    push(&stk, 4);
    push(&stk, 14);
    print(&stk);
    return 0;
}