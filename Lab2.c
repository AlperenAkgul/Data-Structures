#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addfront(struct node *head, int key){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    head = temp;
    return head;    
}

struct node *addlast(struct node *head, int key){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        struct node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = temp;
    }
    return head;
}

void print(struct node *head){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else{
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    }
}

void print_reverse(struct node *head){
    if(head == NULL){
        return;
    }
    else{
        print_reverse(head->next);
        printf("%d", head->data);
    }  
}

int count(struct node *head){
    int counter = 0;
    while(head != NULL){
        counter++;
        head = head->next;
    }
    return counter;
}

int main(){
    struct node *head = NULL;
    int data, choice;
    while(1){
        printf("\n1- Insert a node at front\n2- Insert a node at end\n3- Print the list\n4- Print the list reverse\n 0- Exit\n\n Choice > ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert to the front > ");
            scanf("%d", &data);
            head = addfront(head, data);
            break;
        
        case 2:
            printf("Enter the value to insert to the end > ");
            scanf("%d", &data);
            head = addlast(head, data);
            break;

        case 3:
            print(head);
            break;
        
        case 4:
            print_reverse(head);
            break;
        
        case 0:
            return 0;
            
        default:
            break;
        }
    }
    

}