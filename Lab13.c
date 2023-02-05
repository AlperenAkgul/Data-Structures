#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *addElement(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if(head == NULL){
        head = temp;
        temp->next = NULL;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}

struct node *list(struct node *head){
    struct node *p = head, *q = head;
    p = p->next;
    while(p != NULL){
        if(p->data < q->data){
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
        }
        q = q->next;
        p = p->next;
    } 
    return head;
}

void print(struct node *head){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct node *p = head;
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
    }
}


int main(){
    struct node *head = NULL;
    int i, data;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        data = rand()%1000 + 1;
        head = addElement(head, data);
    }
    print(head);
    head = list(head);
    printf("\n");
    print(head);
}