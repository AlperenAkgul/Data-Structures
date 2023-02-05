#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *substractMin(struct node *head){
    struct node *p = head;
    int min = head->data;
    while(p != NULL){
        if(p->data < min)
            min = p->data;
        p = p->next;
    }
    p = head;
    while(p != NULL){
        p->data -= min;
        p = p->next;
    }
    return head;
}