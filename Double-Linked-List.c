#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

struct node *addfront(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL){
        head->prev = temp;
    }
    head = temp;
    return head;
}

struct node *addlast(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        temp->prev = NULL;
        head = temp;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;    
    }
    return head;
}

struct node *delete(struct node *head, int x){
    if(head == NULL){
        printf("The list is empty");
    }
    else{
        struct node *p = head;
        if(head->data == x){
            head = p->next;
            head->prev = NULL;
            free(p);
        }
        else{
            while(p->data != x && p != NULL){
                p = p->next;
            }
            if(p == NULL){
                return head;
            }
            p->prev->next = p->next;
            if(p->next != NULL)
                p->next->prev = p->prev;
            free(p);    
        }
    }
    return head;
}

void print(struct node *head){
    if(head == NULL){
        printf("The list is Empty");
    }
    else{
        struct node *p = head;
        while(p != NULL){
            printf("%d", p->data);
            p = p->next;
        }
    }
}

int main(){
    int choice;
    int data;
    while(1){
        printf("1.Add Element on Front\n2.Add Element on Last\n3. Delete a Element\n4.Print List\nChoice > ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data > ");
            scanf("%d", &data);
            head = addfront(head, data);
            break;
        case 2: 
            printf("Enter Data > ");
            scanf("%d", &data);
            head = addlast(head, data);
            break;
        case 3:
            printf("Enter Delete Data > ");
            scanf("%d", &data);
            head = delete(head, data);
            break;
        case 4:
            print(head);
            break;
        
        default:
            printf("You Have Entered Invalid Choice! Please try again");
            break;
        }
    }
    return 0;
}