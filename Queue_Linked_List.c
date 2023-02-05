#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct node{
    int data;
    struct node *next;
};

typedef struct{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

void initialize(queue *q){
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull(queue *q){
    if(q->cnt == QUEUE_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(queue *q){
    if(q->cnt == 0){
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
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        if(isEmpty(q)){
            q->front = q->rear = temp;
        }
        else{
            q->rear->next = temp;
            q->rear = temp;
        }
        q->cnt++;
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("The Queue is Empty");
        return -100;
    }
    else{
        int x = q->front->data;
        struct node *temp = q->front;
        q->front = temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}

void printall(queue *q){
    if(isEmpty(q)){
        printf("The Queue is Empty");
    }
    else{
        struct node *temp = q->front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    queue q;
    int choice;
    int data;
    while(1){
        printf("\n1.Initialize\n2.Enqueue\n3.Dequeue\n4.Print\n\nChoice > ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initialize(&q);
            break;

        case 2:
            printf("Please enter data > ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 3:
            dequeue(&q);
            break;
        case 4:
            printall(&q);
            break;    
        default:
            break;
        }

    }
}