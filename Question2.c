#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *add(struct node *head){
    struct node *p = head;
    int sum = head->data;
    while(p->next != head){
        p = p->next;
    }
    sum += p->data;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = sum;
    temp->next = head;
    p->next = temp;
    return head;
}