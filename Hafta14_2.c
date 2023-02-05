#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *addEdge(struct node *head, int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
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
    temp->next = NULL;
    return head;
}

int degree(struct node *heads[], int v){
    int result = 0;
    struct node *temp = heads[v]->next;
    while(temp != NULL){
        result++;
        temp = temp->next;
    }
    return result;
}

int main(){
    int i;
    int n = 5;

    struct node *heads[5] = {NULL};

    heads[0] = addEdge(heads[0], 1); //vertex 1
    heads[0] = addEdge(heads[0], 2);
    heads[1] = addEdge(heads[1], 2); //vertex 2
    heads[1] = addEdge(heads[1], 4);
    heads[2] = addEdge(heads[2], 3); //vertex 3
    heads[2] = addEdge(heads[2], 1);
    heads[2] = addEdge(heads[2], 4);
    heads[2] = addEdge(heads[2], 5);
    heads[3] = addEdge(heads[3], 4); //vertex 4
    heads[3] = addEdge(heads[3], 1);
    heads[3] = addEdge(heads[3], 3);
    heads[3] = addEdge(heads[3], 5);
    heads[4] = addEdge(heads[4], 5); //vertex 5

    struct node *headsin[5] = {NULL};

    headsin[0] = addEdge(headsin[0], 1);
    headsin[0] = addEdge(headsin[0], 4);
    headsin[0] = addEdge(headsin[0], 3);
    headsin[1] = addEdge(headsin[1], 2);
    headsin[1] = addEdge(headsin[1], 1);
    headsin[2] = addEdge(headsin[2], 3);
    headsin[2] = addEdge(headsin[2], 4);
    headsin[3] = addEdge(headsin[3], 4);
    headsin[3] = addEdge(headsin[3], 2);
    headsin[3] = addEdge(headsin[3], 3);
    headsin[4] = addEdge(headsin[4], 5);
    headsin[4] = addEdge(headsin[4], 3);
    headsin[4] = addEdge(headsin[4], 4);

    for(i = 0; i < n; i++){
        printf("outdegree of %d vertex is %d\n", i + 1, degree(heads, i));
    }

    for(i = 0; i < n; i++){
        printf("indegree of %d vertex is %d\n", i + 1, degree(headsin, i));
    }

}