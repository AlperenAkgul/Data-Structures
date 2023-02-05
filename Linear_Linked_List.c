#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *addfront(struct node *head, int x){ //adds to the start of list
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

struct node *addlast(struct node *head, int x){ //adds to the last of the list
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    struct node *p = head;
    if(head == NULL){
        head = temp;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }

    return head;
}

struct node *addElement(struct node *head, int x){ // adds from smaller to largest
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    struct node *p = head;
    while(p->next != NULL && p->next->data < temp->data){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;  

    return head;
}

void print(struct node *head){
    struct node *p = head;
    if(p == NULL){
        printf("This list is empty");
    }
    else{
        while(p != NULL){
            printf("%d\t", p->data);
            p = p->next;
        }
    }   
}

void print_rec(struct node *head){
    if(head == NULL){
        return;
    }
    else{
        print_rec(head->next);
        printf("%d", head->data);
    }
}

int count(struct node *head){
    struct node *p = head;
    int cnt = 0;
    if(p == NULL){
        printf("This list is empty");
        return cnt;
    }
    else{
        while(p != NULL){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
}

int count_rec(struct node *head){
    int static cnt = 0;
    if(head == NULL){
        return cnt;
    }
    else{
        cnt++;
        count_rec(head->next);
    }
}

struct node *destroy(struct node *head){
    struct node *temp = head;
    while(head != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
    return head;
}

struct node *rec_destroy(struct node *head){
    if(head == NULL){
        return 0;
    }
    else{
        rec_destroy(head->next);
        free(head);
    }
}

struct node *delete(struct node *head, int x){
    struct node *temp = head;
    struct node *del = head;
    if(head == NULL){
        printf("This list is empty");
    }
    else{
        if(head->data == x){
            head = head->next;
            free(temp);
        }
        else{
            while(temp->next != NULL && temp->data != x){
                del = temp;
                temp = temp->next;
            }
            if(temp->data = x){
                del->next = temp->next;
                free(temp);
            }
        }
    }
    return head;
}

int main(){
    struct node *head = NULL;
    int choice;
    int x;
    while(1){
        printf("\n1.Add Element on Front\n2.Add Element on Last\n3.Print list\n4.Print list recursively\n5.Count elements\n6.Count Elements recursively\n7.Destroy List\n8.Delete an Element\n9.Add sorted element to the list\n\nPlease enter your choice > ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Please enter data > ");
            scanf("%d", &x);
            head = addfront(head, x);
            break;

        case 2:
            printf("Please enter data > ");
            scanf("%d", &x);
            head = addlast(head, x);
            break;

        case 3:
            print(head);
            break;
        
        case 4:
            print_rec(head);
            break;

        case 5:
            printf("%d", count(head));
            break;

        case 6: 
            printf("%d", count_rec(head));
            break;
        
        case 7:
            destroy(head);
            break;

        case 8: 
            printf("Please enter data you want to delete > ");
            scanf("%d", &x);
            delete(head, x);
            break;
        case 9:
            printf("Please enter data > ");
            scanf("%d", &x);
            head = addElement(head, x);
            break;
        
        default:
            printf("You have entered invalid choice! Please try again\n");
            break;
        }
    }
}