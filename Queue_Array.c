#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct{
    int cnt;
    int front;
    int rear;
    int data[QUEUE_SIZE];
}queue;

void initialize(queue *q){
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
}

int isEmpty(queue *q){
    if(q->cnt == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(queue *q){
    if(q->cnt == QUEUE_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q, int x){
    if(isFull(q)){
        printf("The Queue is Full");
    }
    else{
        q->rear++;
        q->cnt++;
        if(q->rear == QUEUE_SIZE){
            q->rear = 0;
        }
        q->data[q->rear] = x;
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("The Queue is Empty");
        return -100;
    }
    else{
        int x = q->data[q->front];
        q->front++;
        q->cnt--;
        if(q->front == QUEUE_SIZE){
            q->front = 0;
        }
        return x;
    }
}

void printall(queue *q){
    if(isEmpty(q)){
        printf("The Queue is empty");
    }
    else{
        int temp = q->front;
        do{
            printf("%d\t", q->data[temp++]);
            if(temp == QUEUE_SIZE)
                temp = 0;
        }while (temp != q->rear+1);
    }
}

int main(){
    queue q;
    int choice;
    int data;
    initialize(&q);
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Print\n\nChoice > ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Please enter data > ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            printall(&q);
            break; 

        default:
            break;
        }

    }
}