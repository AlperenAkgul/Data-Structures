#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

struct node *addfront(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if(head == NULL){
        head = temp;
        temp->next = temp;
    }
    else{
        struct node *p = head;

        while(p->next != head){
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
        head = temp;
    }
    return head;
}

struct node *addlast(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if(head == NULL){
        head = temp;
        temp->next = temp;
    }
    else{
        struct node *p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
    return head;
}

struct node *delete(struct node *head, int x){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else{
        struct node *p;
        if(head->data == x){
            p = head;
            while(p->next != head){
                p = p->next;
            }
            p->next = head->next;
            p = head;
            head = head->next;
            free(p);
        }
        else{
            p = head->next;
            struct node *del = head;
            while (p->data != x && p != head)
            {
                del = p;
                p = p->next;
            } 
    
            if(p != head){
                del->next = p->next;
                free(p);
            }
        }
    }
    return head;
}

void print(struct node *head){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else{
        struct node *p = head;
        do
        {
            printf("%d\n", p->data);
            p = p->next;
        } while (p != head);
    }
}

int search(struct node *head, int x){
    if(head == NULL){
        return 0;
    }
    else{
        struct node *p;
        if(head->data == x){
            return 1;
        }
        else{
            p = head->next;
            while (p->data != x && p != head)
            {
                p = p->next;
            } 

            if(p == head){
                return 0;
            }
            else{
                return 1;
            }    
        }
    }
}

int main(){
    int choice;
    int data;
    while(1){
        printf("1.Add Element on Front\n2.Add Element on Last\n3. Delete a Element\n4.Print List\n5.Search a Element\nChoice > ");
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
        case 5:
            printf("Enter Search Data > ");
            scanf("%d", &data);
            printf("%d", search(head, data));
            break;
        
        default:
            printf("You Have Entered Invalid Choice! Please try again\n");
            break;
        }
    }
    return 0;
}