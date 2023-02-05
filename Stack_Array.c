#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 3

struct stack{
    int top; //index of array
    int data[STACK_SIZE]; //array
};
typedef struct stack stack;

void push(stack *stk, int c){
    if(stk->top == STACK_SIZE - 1){ 
        printf("The Stack is Full");
    }
    else{
        stk->top++;
        stk->data[stk->top] = c; //stk->top is index
    }
}

int pop(stack *stk){
    if(stk->top == -1){
        printf("Stack is empty");
        return -100;
    }
    else{
        int x = stk->data[stk->top];
        stk->top--;
        return x;
    }
}

void reset(stack *stk){ //or initialize
    stk->top = -1;
}

int main(){
    stack stk;
    reset(&stk);
    push(&stk, 4);
    push(&stk, 14);
    push(&stk, 41);
    push(&stk, 6);
    printf("%d \n", pop(&stk));
    printf("%d \n", pop(&stk));
    printf("%d \n", pop(&stk));
    printf("%d \n", pop(&stk));
    return 0;
}