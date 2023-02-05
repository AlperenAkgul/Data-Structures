#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 50
#define QUEUE_SIZE 50

struct node{
    int data;
    struct node *next;
};

typedef struct{
    int cnt;
    struct node *top;
}stack;

typedef struct{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

void initialize_s(stack *stk){
    stk->cnt = 0;
    stk->top = NULL;
}

void push(stack *stk, int c){
    if(stk->cnt == STACK_SIZE){
        printf("Stack is full\n");
    }
    else{
        struct  node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
        
}

int pop(stack *stk){
    if(stk->cnt != 0){
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        int x = temp->data;
        free(temp);
        stk->cnt--;
        return x;
    }
    else{
        printf("Stack is Empty\n");
    }
}

void initialize_q(queue *q){
    q->cnt = 0;
    q->rear = q->front = NULL;
}

void enqueue(queue *q, int c){
    if(q->cnt == QUEUE_SIZE){
        printf("Queue is Full\n");
    }
    else{
        struct  node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = NULL;
        if(q->cnt == 0){
            q->front = q->rear = temp;
        }
        else{
            q->rear->next = temp;
            q->rear = temp;
        }
    }
    q->cnt++;
}

int dequeue(queue *q){
    if(q->cnt == 0){
        printf("Queue is Empty\n");
    }
    else{
        struct node *temp = q->front;
        q->front = q->front->next;
        int key = temp->data;
        free(temp);
        q->cnt--;
        return key;
    }
}

int main(){
    char sentence[50];
    int i;
    stack s;
    queue q;
    initialize_s(&s);
    initialize_q(&q);

    printf("Please enter a sentence: ");
    gets(sentence);

    while(i < strlen(sentence)){
        if(isalpha(sentence[i])){
            enqueue(&q, tolower(sentence[i]));
            push(&s, tolower(sentence[i]));
        }
        i++;
    }
    while(q.cnt != 0){
        if(pop(&s) != dequeue(&q)){
            printf("This word is not palindrome\n");
            return 0;
        }
    }
    printf("This word is palindrome\n");
}